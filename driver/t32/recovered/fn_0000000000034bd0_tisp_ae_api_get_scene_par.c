/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_tisp_ae_api_get_luma[] __asm__("tisp_ae_api_get_luma");
extern unsigned char ref_tisp_ae_api_get_scene_luma[] __asm__("tisp_ae_api_get_scene_luma");
u64 tisp_ae_api_get_scene_par(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_34bd0 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_34cc4 = ((u32)(unsigned long)ref_tisp_ae_api_get_luma + 0x8000U) & 0xffff0000U;
    const u32 hi_34ce0 = ((u32)(unsigned long)ref_tisp_ae_api_get_scene_luma + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_34bd0:
    v0 = hi_34bd0;
    sp = sp + -32;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_34bd0 + (u32)(unsigned long)ref_t32_data_e15a8;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t6 = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (1684));
    branch = (v1 != 0); t5 = a1;
    if (branch) goto L_34c18;
    goto L_34c00;
L_34c00:
    v1 = 1;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v1;
    *(volatile u8 *)(unsigned long)(a1 + (4)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (8)) = v1;
    *(volatile u8 *)(unsigned long)(a1 + (12)) = 0; goto L_34c7c;
L_34c18:
    a0 = 1;
    branch = (v1 != a0); a0 = 2;
    if (branch) goto L_34c4c;
    goto L_34c24;
L_34c24:
    a0 = 3;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (2942));
    *(volatile u32 *)(unsigned long)(a1 + (8)) = a0;
    v1 = v1 + -1;
    *(volatile u8 *)(unsigned long)(a1 + (4)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (2940)); goto L_34c74;
L_34c4c:
    if (v1 != a0) { v1 = *(volatile u32 *)(unsigned long)(v0 + (0)); goto L_34c80; }
    goto L_34c54;
L_34c54:
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (1708));
    *(volatile u32 *)(unsigned long)(a1 + (8)) = v1;
    a0 = a0 + -1;
    *(volatile u8 *)(unsigned long)(a1 + (4)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (1712));
L_34c74:
    v1 = v1 + -1;
    *(volatile u8 *)(unsigned long)(t5 + (12)) = v1;
L_34c7c:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
L_34c80:
    a0 = 128;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (2960));
    branch = (v1 != a0); *(volatile u32 *)(unsigned long)(t5 + (20)) = v1;
    if (branch) goto L_34c98;
    goto L_34c90;
L_34c90:
    *(volatile u32 *)(unsigned long)(t5 + (16)) = 0; goto L_34ca0;
L_34c98:
    v1 = 1;
    *(volatile u32 *)(unsigned long)(t5 + (16)) = v1;
L_34ca0:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = sp + 16;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (8566));
    v1 = v1 ^ 0x1;
    v1 = (u32)0 < (u32)(v1);
    *(volatile u32 *)(unsigned long)(t5 + (24)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (368));
    *(volatile u32 *)(unsigned long)(t5 + (28)) = v0;
    v0 = hi_34cc4;
    v0 = v0 - hi_34cc4 + (u32)(unsigned long)ref_tisp_ae_api_get_luma;
    callee = v0; a0 = t6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_34cd4;
L_34cd4:
    v0 = *(volatile u8 *)(unsigned long)(sp + (16));
    a1 = t5 + 36;
    *(volatile u32 *)(unsigned long)(t5 + (32)) = v0;
    v0 = hi_34ce0;
    v0 = v0 - hi_34ce0 + (u32)(unsigned long)ref_tisp_ae_api_get_scene_luma;
    callee = v0; a0 = t6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_34cf0;
L_34cf0:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    v0 = 0;
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
