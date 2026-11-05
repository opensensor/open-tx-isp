/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_f0904[] __asm__("t32_data_f0904");
extern unsigned char ref_tisp_s_sdns_ratio[] __asm__("tisp_s_sdns_ratio");
extern unsigned char ref_tisp_s_defog_ratio[] __asm__("tisp_s_defog_ratio");
extern unsigned char ref_tisp_s_mdns_ratio[] __asm__("tisp_s_mdns_ratio");
extern unsigned char ref_tisp_tmo_api_strength_ctrl[] __asm__("tisp_tmo_api_strength_ctrl");
extern unsigned char ref_tisp_s_dpc_ratio[] __asm__("tisp_s_dpc_ratio");
u64 tisp_s_module_ratio_attr(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b1fe4 = ((u32)(unsigned long)ref_t32_data_f0904 + 0x8000U) & 0xffff0000U;
    const u32 hi_b202c = ((u32)(unsigned long)ref_tisp_s_sdns_ratio + 0x8000U) & 0xffff0000U;
    const u32 hi_b2034 = ((u32)(unsigned long)ref_tisp_s_defog_ratio + 0x8000U) & 0xffff0000U;
    const u32 hi_b2038 = ((u32)(unsigned long)ref_tisp_s_mdns_ratio + 0x8000U) & 0xffff0000U;
    const u32 hi_b2028 = ((u32)(unsigned long)ref_tisp_tmo_api_strength_ctrl + 0x8000U) & 0xffff0000U;
    const u32 hi_b2030 = ((u32)(unsigned long)ref_tisp_s_dpc_ratio + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_b1fe0:
    sp = sp + -56;
    v1 = hi_b1fe4;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    s1 = *(volatile u32 *)(unsigned long)(v1 - hi_b1fe4 + (u32)(unsigned long)ref_t32_data_f0904);
    v0 = a0 << (0x7 & 31);
    *(volatile u32 *)(unsigned long)(sp + (48)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    s2 = a0;
    s1 = s1 + v0;
    s3 = a1 + 4;
    s0 = 0;
    s4 = hi_b2028;
    s5 = hi_b202c;
    s6 = hi_b2030;
    s7 = hi_b2034;
    s8 = hi_b2038;
L_b203c:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (1060));
    v0 = *(volatile u32 *)(unsigned long)(s3 + (-4));
    if (v1 != v0) { *(volatile u32 *)(unsigned long)(s1 + (1060)) = v0; goto L_b2070; }
    goto L_b204c;
L_b204c:
    a0 = *(volatile u8 *)(unsigned long)(s1 + (1064));
    branch = (v0 == 0); v1 = *(volatile u8 *)(unsigned long)(s3 + (0));
    if (branch) goto L_b20f0;
    goto L_b2058;
L_b2058:
    a1 = 1;
    if (v0 != a1) { *(volatile u32 *)(unsigned long)(s1 + (1060)) = v0; goto L_b2070; }
    goto L_b2064;
L_b2064:
    if (a0 == v1) { s0 = s0 + 1; goto L_b20f4; }
    goto L_b206c;
L_b206c:
    *(volatile u32 *)(unsigned long)(s1 + (1060)) = v0;
L_b2070:
    branch = (v0 == 0); a1 = 128;
    if (branch) goto L_b207c;
    goto L_b2078;
L_b2078:
    a1 = *(volatile u8 *)(unsigned long)(s3 + (0));
L_b207c:
    v0 = 2;
    branch = (s0 == v0); *(volatile u8 *)(unsigned long)(s1 + (1064)) = a1;
    if (branch) goto L_b20d0;
    goto L_b2088;
L_b2088:
    v0 = (s32)s0 < (s32)(3);
    branch = (v0 == 0); v0 = 3;
    if (branch) goto L_b20a8;
    goto L_b2094;
L_b2094:
    v0 = 1;
    branch = (s0 == v0); a0 = s2;
    if (branch) goto L_b20c8;
    goto L_b20a0;
L_b20a0:
    v0 = s5 - hi_b202c + (u32)(unsigned long)ref_tisp_s_sdns_ratio; goto L_b20e8;
L_b20a8:
    branch = (s0 == v0); a0 = s2;
    if (branch) goto L_b20e4;
    goto L_b20b0;
L_b20b0:
    v0 = 4;
    if (s0 == v0) { v0 = s7 - hi_b2034 + (u32)(unsigned long)ref_tisp_s_defog_ratio; goto L_b20e8; }
    goto L_b20bc;
L_b20bc:
    a0 = s2;
    v0 = s5 - hi_b202c + (u32)(unsigned long)ref_tisp_s_sdns_ratio; goto L_b20e8;
L_b20c8:
    v0 = s8 - hi_b2038 + (u32)(unsigned long)ref_tisp_s_mdns_ratio; goto L_b20e8;
L_b20d0:
    v0 = s4 - hi_b2028 + (u32)(unsigned long)ref_tisp_tmo_api_strength_ctrl;
    callee = v0; a0 = s2 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b20dc;
L_b20dc:
    s0 = s0 + 1; goto L_b20f4;
L_b20e4:
    v0 = s6 - hi_b2030 + (u32)(unsigned long)ref_tisp_s_dpc_ratio;
L_b20e8:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b20f0;
L_b20f0:
    s0 = s0 + 1;
L_b20f4:
    v0 = 5;
    s1 = s1 + 8;
    branch = (s0 != v0); s3 = s3 + 8;
    if (branch) goto L_b203c;
    goto L_b2104;
L_b2104:
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    s8 = *(volatile u32 *)(unsigned long)(sp + (48));
    s7 = *(volatile u32 *)(unsigned long)(sp + (44));
    s6 = *(volatile u32 *)(unsigned long)(sp + (40));
    s5 = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = 0;
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
