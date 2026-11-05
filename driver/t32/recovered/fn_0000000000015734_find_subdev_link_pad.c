/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_bea84[] __asm__("t32_data_bea84");
extern unsigned char ref_t32_data_c6abc[] __asm__("t32_data_c6abc");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
u64 find_subdev_link_pad(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_157ac = ((u32)(unsigned long)ref_t32_data_bea84 + 0x8000U) & 0xffff0000U;
    const u32 hi_157b0 = ((u32)(unsigned long)ref_t32_data_c6abc + 0x8000U) & 0xffff0000U;
    const u32 hi_157b4 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_157e8 = ((u32)(unsigned long)ref_t32_data_bea84 + 0x8000U) & 0xffff0000U;
    const u32 hi_15800 = ((u32)(unsigned long)ref_t32_data_bea84 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_15734:
    sp = sp + -24;
    a3 = a0 + 84;
    a0 = a0 + 148;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (0));
L_15748:
    if (v0 == 0) { a3 = a3 + 4; goto L_15784; }
    goto L_15750;
L_15750:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = *(volatile u32 *)(unsigned long)(a1 + (0));
    t0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_1575c:
    at = *(volatile u8 *)(unsigned long)(a2 + (0));
    v1 = v1 + 1;
    branch = (at != t0); a2 = a2 + 1;
    if (branch) goto L_15778;
    goto L_1576c;
L_1576c:
    branch = (t0 != 0); t0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_1575c;
    goto L_15774;
L_15774:
    t0 = at;
L_15778:
    t0 = t0 - at;
    branch = (t0 == 0); a3 = a3 + 4;
    if (branch) goto L_15794;
    goto L_15784;
L_15784:
    if (a3 != a0) { v0 = *(volatile u32 *)(unsigned long)(a3 + (0)); goto L_15748; }
    goto L_1578c;
L_1578c:
    v0 = 0; goto L_15814;
L_15794:
    v1 = *(volatile u8 *)(unsigned long)(a1 + (4));
    a0 = 1;
    branch = (v1 == a0); a0 = 2;
    if (branch) goto L_157d8;
    goto L_157a4;
L_157a4:
    if (v1 == a0) { v1 = *(volatile u8 *)(unsigned long)(a1 + (5)); goto L_157f4; }
    goto L_157ac;
L_157ac:
    a2 = hi_157ac;
L_157b0:
    a1 = hi_157b0;
    v0 = hi_157b4;
    a3 = 463;
    a2 = a2 - hi_157ac + (u32)(unsigned long)ref_t32_data_bea84;
    a1 = a1 - hi_157b0 + (u32)(unsigned long)ref_t32_data_c6abc;
    v0 = v0 - hi_157b4 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_157d0;
L_157d0:
    v0 = 0; goto L_15814;
L_157d8:
    v1 = *(volatile u8 *)(unsigned long)(a1 + (5));
    a0 = *(volatile u16 *)(unsigned long)(v0 + (270));
    a0 = (u32)v1 < (u32)(a0);
    branch = (a0 == 0); a2 = hi_157e8;
    if (branch) goto L_157b0;
    goto L_157ec;
L_157ec:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (276)); goto L_15808;
L_157f4:
    a0 = *(volatile u16 *)(unsigned long)(v0 + (268));
    a0 = (u32)v1 < (u32)(a0);
L_157fc:
    branch = (a0 == 0); a2 = hi_15800;
    if (branch) goto L_157b0;
    goto L_15804;
L_15804:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (272));
L_15808:
    a0 = 36;
    a1 = v1 * a0;
    v0 = a1 + v0;
L_15814:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
