/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2424[] __asm__("t32_data_e2424");
extern unsigned char ref_tisp_ysp_all_reg_refresh[] __asm__("tisp_ysp_all_reg_refresh");
extern unsigned char ref_tisp_ysp_intp_reg_refresh[] __asm__("tisp_ysp_intp_reg_refresh");
u64 tisp_ysp_par_refresh(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_7b258 = ((u32)(unsigned long)ref_t32_data_e2424 + 0x8000U) & 0xffff0000U;
    const u32 hi_7b290 = ((u32)(unsigned long)ref_tisp_ysp_all_reg_refresh + 0x8000U) & 0xffff0000U;
    const u32 hi_7b2b8 = ((u32)(unsigned long)ref_tisp_ysp_intp_reg_refresh + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_7b254:
    sp = sp + -32;
    v0 = hi_7b258;
    v0 = v0 - hi_7b258 + (u32)(unsigned long)ref_t32_data_e2424;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    s2 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    v1 = s2 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    s0 = a1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (8));
    v1 = -1;
    branch = (a3 != v1); s1 = v0;
    if (branch) goto L_7b29c;
    goto L_7b290;
L_7b290:
    v0 = hi_7b290;
    v0 = v0 - hi_7b290 + (u32)(unsigned long)ref_tisp_ysp_all_reg_refresh; goto L_7b2c0;
L_7b29c:
    v1 = (u32)a1 < (u32)(a3);
    v0 = a1 - a3;
    t0 = a3 - a1;
    if (v1 != 0) v0 = t0;
    a2 = (u32)v0 < (u32)(a2);
    if (a2 != 0) { s0 = a3; goto L_7b2d0; }
    goto L_7b2b8;
L_7b2b8:
    v0 = hi_7b2b8;
    v0 = v0 - hi_7b2b8 + (u32)(unsigned long)ref_tisp_ysp_intp_reg_refresh;
L_7b2c0:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7b2c8;
L_7b2c8:
    v0 = s1 + s2; goto L_7b2d4;
L_7b2d0:
    v0 = s1 + s2;
L_7b2d4:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (8)) = s0;
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
