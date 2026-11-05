/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
extern unsigned char ref_t32_data_c9ef8[] __asm__("t32_data_c9ef8");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_c9f58[] __asm__("t32_data_c9f58");
extern unsigned char ref_t32_data_c9fa4[] __asm__("t32_data_c9fa4");
u64 tisp_msca_api_set_osd_out_cfg(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_85c54 = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    const u32 hi_85ca8 = ((u32)(unsigned long)ref_t32_data_c9ef8 + 0x8000U) & 0xffff0000U;
    const u32 hi_85cac = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_85cf0 = ((u32)(unsigned long)ref_t32_data_c9f58 + 0x8000U) & 0xffff0000U;
    const u32 hi_85cf4 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_85d18 = ((u32)(unsigned long)ref_t32_data_c9fa4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
L_85c40:
    sp = sp + -40;
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s0;
    t4 = *(volatile u8 *)(unsigned long)(a1 + (1));
    a0 = a0 & 0xff;
    t1 = hi_85c54;
    v0 = 1;
    a0 = a0 << (0x2 & 31);
    t1 = t1 - hi_85c54 + (u32)(unsigned long)ref_t32_data_e2768;
    branch = (t4 != v0); a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    if (branch) goto L_85e08;
    goto L_85c6c;
L_85c6c:
    t0 = 20;
    a3 = a2 * t0;
    v1 = t1 + a0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t3 = *(volatile u16 *)(unsigned long)(v1 + (44));
    t5 = a3 + v1;
    a3 = *(volatile u16 *)(unsigned long)(t5 + (686));
    a3 = (u32)t3 < (u32)(a3);
    branch = (a3 != 0); v0 = a1;
    if (branch) goto L_85ca8;
    goto L_85c94;
L_85c94:
    t2 = *(volatile u16 *)(unsigned long)(v1 + (46));
    a3 = *(volatile u16 *)(unsigned long)(t5 + (688));
    a3 = (u32)t2 < (u32)(a3);
    if (a3 == 0) { a2 = *(volatile u16 *)(unsigned long)(a1 + (2)); goto L_85cc8; }
    goto L_85ca8;
L_85ca8:
    a1 = hi_85ca8;
    v0 = hi_85cac;
    a1 = a1 - hi_85ca8 + (u32)(unsigned long)ref_t32_data_c9ef8;
    v0 = v0 - hi_85cac + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_85cc0;
L_85cc0:
    v0 = 0; goto L_85ea4;
L_85cc8:
    t7 = *(volatile u16 *)(unsigned long)(a1 + (6));
    a3 = *(volatile u16 *)(unsigned long)(a1 + (4));
    t6 = a2 + t7;
    t6 = (s32)t3 < (s32)(t6);
    branch = (t6 != 0); t8 = *(volatile u16 *)(unsigned long)(a1 + (8));
    if (branch) goto L_85cf0;
    goto L_85ce0;
L_85ce0:
    t6 = a3 + t8;
    t6 = (s32)t2 < (s32)(t6);
    if (t6 == 0) { *(volatile u8 *)(unsigned long)(t5 + (680)) = t4; goto L_85d30; }
    goto L_85cf0;
L_85cf0:
    a1 = hi_85cf0;
    s0 = hi_85cf4;
    *(volatile u32 *)(unsigned long)(sp + (28)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (24)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (20)) = t8;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t7;
    a1 = a1 - hi_85cf0 + (u32)(unsigned long)ref_t32_data_c9f58;
    s0 = s0 - hi_85cf4 + (u32)(unsigned long)ref_isp_printf;
    callee = s0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_85d18;
L_85d18:
    a1 = hi_85d18;
    a1 = a1 - hi_85d18 + (u32)(unsigned long)ref_t32_data_c9fa4;
    callee = s0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_85d28;
L_85d28:
    v0 = -1; goto L_85ea4;
L_85d30:
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = *(volatile u16 *)(unsigned long)(a1 + (2));
    t4 = a2 * t0;
    a2 = t4 + v1;
    *(volatile u16 *)(unsigned long)(a2 + (682)) = a3;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = *(volatile u16 *)(unsigned long)(a1 + (4));
    t4 = a2 * t0;
    a2 = t4 + v1;
    *(volatile u16 *)(unsigned long)(a2 + (684)) = a3;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = *(volatile u16 *)(unsigned long)(a1 + (6));
    t4 = a2 * t0;
    a2 = t4 + v1;
    *(volatile u16 *)(unsigned long)(a2 + (686)) = a3;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = *(volatile u16 *)(unsigned long)(a1 + (8));
    t4 = a2 * t0;
    a2 = t4 + v1;
    *(volatile u16 *)(unsigned long)(a2 + (688)) = a3;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = a2 * t0;
    a2 = a3 + v1;
    a3 = *(volatile u32 *)(unsigned long)(a1 + (12));
    *(volatile u32 *)(unsigned long)(a2 + (692)) = a3;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = *(volatile u16 *)(unsigned long)(a1 + (16));
    t4 = a2 * t0;
    a2 = t4 + v1;
    *(volatile u16 *)(unsigned long)(a2 + (696)) = a3;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = a2 * t0;
    t0 = a3 + v1;
    a3 = *(volatile u16 *)(unsigned long)(t0 + (682));
    a2 = *(volatile u16 *)(unsigned long)(t0 + (686));
    a2 = a2 + a3;
    a2 = (s32)t3 < (s32)(a2);
    if (a2 == 0) { v0 = *(volatile u8 *)(unsigned long)(v0 + (0)); goto L_85dd8; }
    goto L_85dcc;
L_85dcc:
    t3 = t3 - a3;
    *(volatile u16 *)(unsigned long)(t0 + (686)) = t3;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
L_85dd8:
    a2 = 20;
    a3 = v0 * a2;
    v1 = a3 + v1;
    a2 = *(volatile u16 *)(unsigned long)(v1 + (684));
    v0 = *(volatile u16 *)(unsigned long)(v1 + (688));
    v0 = v0 + a2;
    v0 = (s32)t2 < (s32)(v0);
    if (v0 == 0) { t1 = t1 + a0; goto L_85e84; }
    goto L_85dfc;
L_85dfc:
    t2 = t2 - a2;
    *(volatile u16 *)(unsigned long)(v1 + (688)) = t2; goto L_85e80;
L_85e08:
    v1 = 20;
    a3 = a2 * v1;
    v0 = t1 + a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = a3 + v0;
    *(volatile u8 *)(unsigned long)(a2 + (680)) = t4;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = a2 * v1;
    a2 = a3 + v0;
    *(volatile u16 *)(unsigned long)(a2 + (682)) = 0;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = a2 * v1;
    a2 = a3 + v0;
    *(volatile u16 *)(unsigned long)(a2 + (684)) = 0;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = a2 * v1;
    a2 = a3 + v0;
    *(volatile u16 *)(unsigned long)(a2 + (686)) = 0;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = a2 * v1;
    a2 = a3 + v0;
    *(volatile u16 *)(unsigned long)(a2 + (688)) = 0;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = a2 * v1;
    a2 = a3 + v0;
    *(volatile u32 *)(unsigned long)(a2 + (692)) = 0;
    a2 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a3 = a2 * v1;
    v0 = a3 + v0;
    *(volatile u16 *)(unsigned long)(v0 + (696)) = 0;
L_85e80:
    t1 = t1 + a0;
L_85e84:
    a0 = *(volatile u32 *)(unsigned long)(t1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v0 = 1;
    v1 = v0 << (v1 & 31);
    v0 = *(volatile u32 *)(unsigned long)(a0 + (880));
    v0 = v0 | v1;
    *(volatile u32 *)(unsigned long)(a0 + (880)) = v0;
    v0 = 0;
L_85ea4:
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    sp = sp + 40;
    return ((u64)v1 << 32) | v0;
}
