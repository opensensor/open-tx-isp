/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
extern unsigned char ref_t32_data_bf420[] __asm__("t32_data_bf420");
extern unsigned char ref_t32_data_bf448[] __asm__("t32_data_bf448");
extern unsigned char ref_t32_data_c9430[] __asm__("t32_data_c9430");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
u64 tisp_awb_set_mode(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3f80c = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_3f840 = ((u32)(unsigned long)ref_t32_data_bf420 + 0x8000U) & 0xffff0000U;
    const u32 hi_3f928 = ((u32)(unsigned long)ref_t32_data_bf448 + 0x8000U) & 0xffff0000U;
    const u32 hi_3f92c = ((u32)(unsigned long)ref_t32_data_c9430 + 0x8000U) & 0xffff0000U;
    const u32 hi_3f930 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_3f808:
    sp = sp + -32;
    v0 = hi_3f80c;
    v0 = v0 - hi_3f80c + (u32)(unsigned long)ref_t32_data_e16b4;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    s1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = (u32)v0 < (u32)(10);
    branch = (v1 == 0); s0 = *(volatile u32 *)(unsigned long)(s1 + (8));
    if (branch) goto L_3f928;
    goto L_3f83c;
L_3f83c:
    v1 = v0 << (0x2 & 31);
    v0 = hi_3f840;
    v0 = v0 - hi_3f840 + (u32)(unsigned long)ref_t32_data_bf420;
    v0 = v0 + v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    callee = v0; ;
    switch (callee) { case 0x3f808: goto L_3f808; case 0x3f858: goto L_3f858; case 0x3f860: goto L_3f860; case 0x3f868: goto L_3f868; case 0x3f880: goto L_3f880; case 0x3f898: goto L_3f898; case 0x3f8b0: goto L_3f8b0; case 0x3f8c8: goto L_3f8c8; case 0x3f8e0: goto L_3f8e0; case 0x3f8f8: goto L_3f8f8; case 0x3f910: goto L_3f910; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_3f858:
    *(volatile u32 *)(unsigned long)(s0 + (0)) = 0; goto L_3f94c;
L_3f860:
    v0 = 1; goto L_3f914;
L_3f868:
    v0 = 2;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = 384;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
L_3f878:
    *(volatile u32 *)(unsigned long)(s0 + (8)) = v0; goto L_3f94c;
L_3f880:
    v0 = 3;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = 438;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
    v0 = 303; goto L_3f878;
L_3f898:
    v0 = 4;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = 219;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
    v0 = 690; goto L_3f878;
L_3f8b0:
    v0 = 5;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = 240;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
    v0 = 564; goto L_3f878;
L_3f8c8:
    v0 = 6;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = 315;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
    v0 = 459; goto L_3f878;
L_3f8e0:
    v0 = 7;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = 468;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
    v0 = 279; goto L_3f878;
L_3f8f8:
    v0 = 8;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = 240;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
    v0 = 376; goto L_3f878;
L_3f910:
    v0 = 9;
L_3f914:
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (8)); goto L_3f878;
L_3f928:
    a2 = hi_3f928;
    a1 = hi_3f92c;
    v0 = hi_3f930;
    a3 = 3134;
    a2 = a2 - hi_3f928 + (u32)(unsigned long)ref_t32_data_bf448;
    a1 = a1 - hi_3f92c + (u32)(unsigned long)ref_t32_data_c9430;
    v0 = v0 - hi_3f930 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3f94c;
L_3f94c:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    v0 = 0x2U << 16;
    v1 = v1 + v0;
    *(volatile u8 *)(unsigned long)(v1 + (-23474)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (4));
    v1 = v1 + v0;
    *(volatile u16 *)(unsigned long)(v1 + (-23468)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (8));
    v1 = v1 + v0;
    *(volatile u16 *)(unsigned long)(v1 + (-23466)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (4));
    v0 = v1 + v0;
    v1 = 1;
    *(volatile u8 *)(unsigned long)(v0 + (-23476)) = v1;
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = 0;
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
