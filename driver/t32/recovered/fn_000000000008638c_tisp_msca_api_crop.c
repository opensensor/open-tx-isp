/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
extern unsigned char ref_tisp_msca_init_chx_cfg[] __asm__("tisp_msca_init_chx_cfg");
extern unsigned char ref_t32_data_d03a0[] __asm__("t32_data_d03a0");
extern unsigned char ref_tisp_reg_write[] __asm__("tisp_reg_write");
u64 tisp_msca_api_crop(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_863a0 = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    const u32 hi_86438 = ((u32)(unsigned long)ref_tisp_msca_init_chx_cfg + 0x8000U) & 0xffff0000U;
    const u32 hi_86448 = ((u32)(unsigned long)ref_t32_data_d03a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_8646c = ((u32)(unsigned long)ref_tisp_reg_write + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_8638c:
    sp = sp + -24;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    t0 = *(volatile u16 *)(unsigned long)(a2 + (0));
    s0 = a0 & 0xff;
    v1 = hi_863a0;
    a3 = s0 << (0x2 & 31);
    v0 = v1 - hi_863a0 + (u32)(unsigned long)ref_t32_data_e2768;
    a0 = 1;
    a1 = a1 & 0xff;
    branch = (t0 != a0); v1 = v0 + a3;
    if (branch) goto L_863ec;
    goto L_863bc;
L_863bc:
    t0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = 872;
    t1 = a1 * v1;
    a0 = *(volatile u16 *)(unsigned long)(a2 + (2));
    v1 = t1 + t0;
    *(volatile u16 *)(unsigned long)(v1 + (40)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(a2 + (4));
    *(volatile u16 *)(unsigned long)(v1 + (42)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(a2 + (6));
    *(volatile u16 *)(unsigned long)(v1 + (44)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(a2 + (8)); goto L_86418;
L_863ec:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = 872;
    t0 = a1 * v1;
    v1 = t0 + a0;
    t0 = a1 << (0x1 & 31);
    *(volatile u16 *)(unsigned long)(v1 + (40)) = 0;
    *(volatile u16 *)(unsigned long)(v1 + (42)) = 0;
    a0 = a0 + t0;
    t0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    *(volatile u16 *)(unsigned long)(v1 + (44)) = t0;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (6));
L_86418:
    *(volatile u16 *)(unsigned long)(v1 + (46)) = a0;
    v0 = v0 + a3;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 872;
    v1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a2 = a1 * v0;
    v0 = a2 + a0;
    *(volatile u16 *)(unsigned long)(v0 + (38)) = v1;
    v0 = hi_86438;
    v0 = v0 - hi_86438 + (u32)(unsigned long)ref_tisp_msca_init_chx_cfg;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_86448;
L_86448:
    v0 = hi_86448;
    v0 = *(volatile u8 *)(unsigned long)(v0 - hi_86448 + (u32)(unsigned long)ref_t32_data_d03a0);
    branch = (v0 != 0); a1 = 13;
    if (branch) goto L_86460;
    goto L_86458;
L_86458:
    a1 = 0xfU << 16;
    a1 = a1 + 16;
L_86460:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    a0 = s0;
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    t9 = hi_8646c;
    a2 = 1;
    t9 = t9 - hi_8646c + (u32)(unsigned long)ref_tisp_reg_write;
    callee = t9; sp = sp + 24;
    switch (callee) { case 0x8638c: goto L_8638c; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
}
