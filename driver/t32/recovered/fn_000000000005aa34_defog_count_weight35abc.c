/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_bfa30[] __asm__("t32_data_bfa30");
extern unsigned char ref_t32_data_bfa60[] __asm__("t32_data_bfa60");
extern unsigned char ref_t32_data_e211c[] __asm__("t32_data_e211c");
extern unsigned char ref_t32_data_e20e0[] __asm__("t32_data_e20e0");
extern unsigned char ref_private_vfree[] __asm__("private_vfree");
extern unsigned char ref_private_vmalloc[] __asm__("private_vmalloc");
extern unsigned char ref_t32_data_bfaf0[] __asm__("t32_data_bfaf0");
extern unsigned char ref_t32_data_c9958[] __asm__("t32_data_c9958");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_defog_wei_interpcot[] __asm__("defog_wei_interpcot");
u64 defog_count_weight35abc(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u32 arg10)
{
    u32 stack[174] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_5aa50 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_5aa5c = ((u32)(unsigned long)ref_t32_data_bfa30 + 0x8000U) & 0xffff0000U;
    const u32 hi_5aabc = ((u32)(unsigned long)ref_t32_data_bfa60 + 0x8000U) & 0xffff0000U;
    const u32 hi_5ac40 = ((u32)(unsigned long)ref_t32_data_e211c + 0x8000U) & 0xffff0000U;
    const u32 hi_5ac54 = ((u32)(unsigned long)ref_t32_data_e20e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_5ac8c = ((u32)(unsigned long)ref_private_vfree + 0x8000U) & 0xffff0000U;
    const u32 hi_5ac9c = ((u32)(unsigned long)ref_private_vmalloc + 0x8000U) & 0xffff0000U;
    const u32 hi_5acb4 = ((u32)(unsigned long)ref_t32_data_bfaf0 + 0x8000U) & 0xffff0000U;
    const u32 hi_5acb8 = ((u32)(unsigned long)ref_t32_data_c9958 + 0x8000U) & 0xffff0000U;
    const u32 hi_5acbc = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_5ace8 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_5b0b0 = ((u32)(unsigned long)ref_defog_wei_interpcot + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[110];
    stack[114] = arg4;
    stack[115] = arg5;
    stack[116] = arg6;
    stack[117] = arg7;
    stack[118] = arg8;
    stack[119] = arg9;
    stack[120] = arg10;
L_5aa34:
    sp = sp + -440;
    v0 = *(volatile u32 *)(unsigned long)(sp + (464));
    *(volatile u32 *)(unsigned long)(sp + (412)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (400)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (376)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (468));
    s3 = a1;
    s0 = hi_5aa50;
    *(volatile u32 *)(unsigned long)(sp + (380)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (472));
    a1 = hi_5aa5c;
    s0 = s0 - hi_5aa50 + ((u32)(unsigned long)ref_memcpy + (0));
    *(volatile u32 *)(unsigned long)(sp + (384)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (476));
    *(volatile u32 *)(unsigned long)(sp + (436)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (432)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (388)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (480));
    s8 = a2;
    *(volatile u32 *)(unsigned long)(sp + (428)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (424)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (420)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (416)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (408)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (404)) = s1;
    a2 = 48;
    a1 = a1 - hi_5aa5c + (u32)(unsigned long)ref_t32_data_bfa30;
    s4 = a0 & 0xff;
    a0 = sp + 272;
    s7 = a3;
    s5 = *(volatile u32 *)(unsigned long)(sp + (456));
    s6 = *(volatile u32 *)(unsigned long)(sp + (460));
    callee = s0; *(volatile u32 *)(unsigned long)(sp + (392)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5aabc;
L_5aabc:
    a1 = hi_5aabc;
    a1 = a1 - hi_5aabc + (u32)(unsigned long)ref_t32_data_bfa60;
    a0 = sp + 144;
    callee = s0; a2 = 126;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5aad0;
L_5aad0:
    s2 = s3 + 5;
    v0 = 10;
    if (v0) { lo = s2 / v0; hi = s2 % v0; } else { lo = ~0U; hi = s2; }
    s1 = s8 + 9;
    v0 = 18;
    v1 = sp + 272;
    a1 = s5 + 48;
    a0 = s5;
    s2 = lo;
    if (v0) { lo = s1 / v0; hi = s1 % v0; } else { lo = ~0U; hi = s1; }
    v0 = s2 << (0x2 & 31);
    v0 = v0 + s2;
    v0 = v0 + -1;
    *(volatile u32 *)(unsigned long)(sp + (352)) = v0;
    s1 = lo;
    v0 = s1 << (0x2 & 31);
    v0 = v0 + s1;
    s3 = s3 * s8;
    v0 = v0 + -1;
    *(volatile u32 *)(unsigned long)(sp + (356)) = v0;
    v0 = 2025;
    s3 = s3 + 1012;
    s0 = s2 * s1;
    if (v0) { lo = s3 / v0; hi = s3 % v0; } else { lo = ~0U; hi = s3; }
    s3 = lo;
    a3 = s3 * s7;
    a3 = a3 + 64;
    a3 = a3 >> (0x7 & 31);
L_5ab40:
    v0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = a0 + 2;
    v1 = v1 + 2;
    v0 = v0 * a3;
    v0 = v0 + 8192;
    v0 = v0 >> (0xe & 31);
    branch = (a0 != a1); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v0;
    if (branch) goto L_5ab40;
    goto L_5ab60;
L_5ab60:
    v1 = 0;
    a0 = 126;
L_5ab68:
    v0 = sp + 16;
    a1 = v0 + v1;
    v0 = sp + 144;
    v0 = v0 + v1;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v1 = v1 + 2;
    v0 = v0 * a3;
    v0 = v0 + 4096;
    v0 = v0 >> (0xd & 31);
    branch = (v1 != a0); *(volatile u16 *)(unsigned long)(a1 + (0)) = v0;
    if (branch) goto L_5ab68;
    goto L_5ab94;
L_5ab94:
    v1 = s6;
    v0 = 0;
    a1 = 31;
L_5aba0:
    a0 = v0 << (0x2 & 31);
    a2 = sp + 16;
    a0 = a2 + a0;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (2));
    v0 = v0 + 1;
    v1 = v1 + 2;
    branch = (v0 != a1); *(volatile u16 *)(unsigned long)(v1 + (-2)) = a0;
    if (branch) goto L_5aba0;
    goto L_5abc0;
L_5abc0:
    v0 = *(volatile u16 *)(unsigned long)(s5 + (46));
    v0 = v0 >> (0xd & 31);
    branch = (v0 != 0); v0 = 8191;
    if (branch) goto L_5abe8;
    goto L_5abd0;
L_5abd0:
    v0 = *(volatile u16 *)(unsigned long)(s6 + (60));
L_5abd4:
    v0 = v0 >> (0xe & 31);
    if (v0 != 0) { v0 = 16383; goto L_5ac1c; }
    goto L_5abe0;
L_5abe0:
    v0 = 13; goto L_5ac3c;
L_5abe8:
    *(volatile u16 *)(unsigned long)(s5 + (46)) = v0;
    v0 = s5 + 44;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (2));
L_5abf4:
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a0 = (u32)a0 < (u32)(v1);
    branch = (a0 != 0); v1 = v1 + -1;
    if (branch) goto L_5abd0;
    goto L_5ac04;
L_5ac04:
    *(volatile u16 *)(unsigned long)(v0 + (0)) = v1;
    v0 = v0 + -2;
    if (s5 != v0) { v1 = *(volatile u16 *)(unsigned long)(v0 + (2)); goto L_5abf4; }
    goto L_5ac14;
L_5ac14:
    v0 = *(volatile u16 *)(unsigned long)(s6 + (60)); goto L_5abd4;
L_5ac1c:
    *(volatile u16 *)(unsigned long)(s6 + (60)) = v0;
    v0 = s6 + 58;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (2));
L_5ac28:
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a0 = (u32)a0 < (u32)(v1);
    branch = (a0 == 0); v1 = v1 + -1;
    if (branch) goto L_5ac6c;
    goto L_5ac38;
L_5ac38:
    v0 = 13;
L_5ac3c:
    v0 = s0 * v0;
    s3 = hi_5ac40;
    s5 = s4 << (0x2 & 31);
    s3 = s3 - hi_5ac40 + (u32)(unsigned long)ref_t32_data_e211c;
    s6 = s5 + s3;
    v1 = *(volatile u32 *)(unsigned long)(s6 + (0));
    s4 = hi_5ac54;
    v1 = (u32)v1 < (u32)(v0);
    branch = (v1 == 0); s4 = s4 - hi_5ac54 + (u32)(unsigned long)ref_t32_data_e20e0;
    if (branch) goto L_5acd8;
    goto L_5ac64;
L_5ac64:
    s7 = s4 + s5; goto L_5ac84;
L_5ac6c:
    *(volatile u16 *)(unsigned long)(v0 + (0)) = v1;
    v0 = v0 + -2;
    if (s6 != v0) { v1 = *(volatile u16 *)(unsigned long)(v0 + (2)); goto L_5ac28; }
    goto L_5ac7c;
L_5ac7c:
    v0 = 13; goto L_5ac3c;
L_5ac84:
    a0 = *(volatile u32 *)(unsigned long)(s7 + (0));
    *(volatile u32 *)(unsigned long)(s6 + (0)) = v0;
    v0 = hi_5ac8c;
    v0 = v0 - hi_5ac8c + (u32)(unsigned long)ref_private_vfree;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5ac9c;
L_5ac9c:
    v0 = hi_5ac9c;
    v0 = v0 - hi_5ac9c + (u32)(unsigned long)ref_private_vmalloc;
    callee = v0; a0 = *(volatile u32 *)(unsigned long)(s6 + (0));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5acac;
L_5acac:
    branch = (v0 != 0); *(volatile u32 *)(unsigned long)(s7 + (0)) = v0;
    if (branch) goto L_5acd8;
    goto L_5acb4;
L_5acb4:
    a2 = hi_5acb4;
    a1 = hi_5acb8;
    v0 = hi_5acbc;
    a3 = 374;
    a2 = a2 - hi_5acb4 + (u32)(unsigned long)ref_t32_data_bfaf0;
    a1 = a1 - hi_5acb8 + (u32)(unsigned long)ref_t32_data_c9958;
    v0 = v0 - hi_5acbc + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5acd8;
L_5acd8:
    s4 = s4 + s5;
    s3 = s3 + s5;
    a2 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a0 = *(volatile u32 *)(unsigned long)(s4 + (0));
    v0 = hi_5ace8;
    v0 = v0 - hi_5ace8 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5acf8;
L_5acf8:
    a2 = *(volatile u32 *)(unsigned long)(s4 + (0));
    v1 = s1;
    a3 = 0;
    v0 = a2 + s0;
    s5 = v0 + s0;
    s7 = s5 + s0;
    *(volatile u32 *)(unsigned long)(sp + (328)) = v0;
    v0 = s7 + s0;
    *(volatile u32 *)(unsigned long)(sp + (332)) = v0;
    v0 = v0 + s0;
    s3 = v0 + s0;
    t6 = s3 + s0;
    a1 = t6 + s0;
    s8 = a1 + s0;
    s6 = s8 + s0;
    s4 = s6 + s0;
    *(volatile u32 *)(unsigned long)(sp + (320)) = v0;
    v0 = s4 + s0;
    *(volatile u32 *)(unsigned long)(sp + (336)) = v0;
    v0 = s2 << (0x1 & 31);
    *(volatile u32 *)(unsigned long)(sp + (340)) = v0;
    v0 = s1 << (0x1 & 31);
    *(volatile u32 *)(unsigned long)(sp + (348)) = v0;
    v0 = (s32)s1 < (s32)(0);
    if (v0 != 0) v1 = 0;
    t9 = 0;
    t1 = 63;
    t2 = 63;
    *(volatile u32 *)(unsigned long)(sp + (396)) = v1;
L_5ad6c:
    v0 = (s32)t9 < (s32)(s2);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (352));
    if (branch) goto L_5b020;
    goto L_5ad78;
L_5ad78:
    v1 = t9 << (0x1 & 31);
    v1 = v0 - v1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (340));
    t3 = v1 - v0;
    v0 = t3 - v0;
    v1 = v1 * v1;
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (324)) = v1;
    v1 = 0;
    t3 = t3 * t3;
    *(volatile u32 *)(unsigned long)(sp + (344)) = v0;
L_5ada4:
    v0 = (s32)v1 < (s32)(s1);
    branch = (v0 == 0); a0 = *(volatile u32 *)(unsigned long)(sp + (356));
    if (branch) goto L_5b010;
    goto L_5adb0;
L_5adb0:
    v0 = v1 << (0x1 & 31);
    t0 = *(volatile u32 *)(unsigned long)(sp + (348));
    v0 = a0 - v0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (348));
    t4 = *(volatile u32 *)(unsigned long)(sp + (324));
    a0 = v0 - a0;
    t0 = a0 - t0;
    t0 = t0 * t0;
    v0 = v0 * v0;
    t5 = t4 + t0;
    t0 = t3 + t0;
    t0 = t0 + 32;
    t0 = (s32)t0 >> (0x6 & 31);
    *(volatile u32 *)(unsigned long)(sp + (364)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (344));
    t5 = t5 + 32;
    t5 = (s32)t5 >> (0x6 & 31);
    a0 = a0 * a0;
    t8 = t4 + v0;
    t8 = t8 + 32;
    t8 = (s32)t8 >> (0x6 & 31);
    t7 = t4 + a0;
    t4 = t3 + v0;
    v0 = t0 + v0;
    ra = t3 + a0;
    v0 = v0 + 32;
    a0 = t0 + a0;
    v0 = (s32)v0 >> (0x6 & 31);
    a0 = a0 + 32;
    ra = ra + 32;
    *(volatile u32 *)(unsigned long)(sp + (368)) = v0;
    v0 = (s32)a0 >> (0x6 & 31);
    t7 = t7 + 32;
    t4 = t4 + 32;
    ra = (s32)ra >> (0x6 & 31);
    *(volatile u32 *)(unsigned long)(sp + (372)) = v0;
    v0 = sp + 16;
    t7 = (s32)t7 >> (0x6 & 31);
    t4 = (s32)t4 >> (0x6 & 31);
    *(volatile u32 *)(unsigned long)(sp + (360)) = ra;
    t0 = v0;
    a0 = 0;
L_5ae58:
    ra = *(volatile u16 *)(unsigned long)(t0 + (0));
    ra = (u32)t8 < (u32)(ra);
    if (ra == 0) { a0 = a0 + 1; goto L_5ae7c; }
    goto L_5ae68;
L_5ae68:
    t0 = v1 + a3;
    t0 = a2 + t0;
    a0 = t2 - a0;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = a0; goto L_5ae84;
L_5ae7c:
    branch = (a0 != t1); t0 = t0 + 2;
    if (branch) goto L_5ae58;
    goto L_5ae84;
L_5ae84:
    t0 = v0;
    a0 = 0;
L_5ae8c:
    t8 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t8 = (u32)t7 < (u32)(t8);
    if (t8 == 0) { a0 = a0 + 1; goto L_5aeb4; }
    goto L_5ae9c;
L_5ae9c:
    t7 = *(volatile u32 *)(unsigned long)(sp + (328));
    t0 = v1 + a3;
    a0 = t2 - a0;
    t0 = t7 + t0;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = a0; goto L_5aebc;
L_5aeb4:
    branch = (a0 != t1); t0 = t0 + 2;
    if (branch) goto L_5ae8c;
    goto L_5aebc;
L_5aebc:
    t0 = v0;
    a0 = 0;
L_5aec4:
    t7 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t7 = (u32)t5 < (u32)(t7);
    if (t7 == 0) { a0 = a0 + 1; goto L_5aee8; }
    goto L_5aed4;
L_5aed4:
    t0 = v1 + a3;
    t0 = s5 + t0;
    a0 = t2 - a0;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = a0; goto L_5aef0;
L_5aee8:
    branch = (a0 != t1); t0 = t0 + 2;
    if (branch) goto L_5aec4;
    goto L_5aef0;
L_5aef0:
    t0 = v0;
    a0 = 0;
L_5aef8:
    t5 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t5 = (u32)t4 < (u32)(t5);
    if (t5 == 0) { a0 = a0 + 1; goto L_5af1c; }
    goto L_5af08;
L_5af08:
    t0 = v1 + a3;
    t0 = s7 + t0;
    a0 = t2 - a0;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = a0; goto L_5af24;
L_5af1c:
    branch = (a0 != t1); t0 = t0 + 2;
    if (branch) goto L_5aef8;
    goto L_5af24;
L_5af24:
    t0 = v0;
    a0 = 0;
L_5af2c:
    t4 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t5 = *(volatile u32 *)(unsigned long)(sp + (360));
    t4 = (u32)t5 < (u32)(t4);
    if (t4 == 0) { a0 = a0 + 1; goto L_5af58; }
    goto L_5af40;
L_5af40:
    t4 = *(volatile u32 *)(unsigned long)(sp + (332));
    t0 = v1 + a3;
    a0 = t2 - a0;
    t0 = t4 + t0;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = a0; goto L_5af60;
L_5af58:
    branch = (a0 != t1); t0 = t0 + 2;
    if (branch) goto L_5af2c;
    goto L_5af60;
L_5af60:
    t0 = v0;
    a0 = 0;
L_5af68:
    t4 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t5 = *(volatile u32 *)(unsigned long)(sp + (364));
    t4 = (u32)t5 < (u32)(t4);
    if (t4 == 0) { a0 = a0 + 1; goto L_5af94; }
    goto L_5af7c;
L_5af7c:
    t4 = *(volatile u32 *)(unsigned long)(sp + (320));
    t0 = v1 + a3;
    a0 = t2 - a0;
    t0 = t4 + t0;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = a0; goto L_5af9c;
L_5af94:
    branch = (a0 != t1); t0 = t0 + 2;
    if (branch) goto L_5af68;
    goto L_5af9c;
L_5af9c:
    t0 = v0;
    a0 = 0;
L_5afa4:
    t4 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t5 = *(volatile u32 *)(unsigned long)(sp + (368));
    t4 = (u32)t5 < (u32)(t4);
    if (t4 == 0) { a0 = a0 + 1; goto L_5afcc; }
    goto L_5afb8;
L_5afb8:
    t0 = v1 + a3;
    t0 = s3 + t0;
    a0 = t2 - a0;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = a0; goto L_5afd4;
L_5afcc:
    branch = (a0 != t1); t0 = t0 + 2;
    if (branch) goto L_5afa4;
    goto L_5afd4;
L_5afd4:
    a0 = 0;
L_5afd8:
    t0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t4 = *(volatile u32 *)(unsigned long)(sp + (372));
    t0 = (u32)t4 < (u32)(t0);
    if (t0 == 0) { a0 = a0 + 1; goto L_5b000; }
    goto L_5afec;
L_5afec:
    v0 = v1 + a3;
    v0 = t6 + v0;
    a0 = t2 - a0;
    *(volatile u8 *)(unsigned long)(v0 + (0)) = a0; goto L_5b008;
L_5b000:
    branch = (a0 != t1); v0 = v0 + 2;
    if (branch) goto L_5afd8;
    goto L_5b008;
L_5b008:
    v1 = v1 + 1; goto L_5ada4;
L_5b010:
    v0 = *(volatile u32 *)(unsigned long)(sp + (396));
    t9 = t9 + 1;
    a3 = a3 + v0; goto L_5ad6c;
L_5b020:
    v0 = *(volatile u32 *)(unsigned long)(sp + (332));
    a0 = *(volatile u32 *)(unsigned long)(sp + (320));
    a3 = t6;
    s1 = 0;
L_5b030:
    branch = (s1 == s0); t0 = a1 + s1;
    if (branch) goto L_5b0ac;
    goto L_5b038;
L_5b038:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = v0 + 1;
    v1 = v1 >> (0x1 & 31);
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1;
    t1 = *(volatile u8 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v0 + (-1));
    t0 = s8 + s1;
    a0 = a0 + 1;
    v1 = v1 + t1;
    v1 = (s32)v1 >> (0x2 & 31);
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (-1));
    t1 = *(volatile u8 *)(unsigned long)(a3 + (0));
    t0 = s6 + s1;
    a3 = a3 + 1;
    v1 = v1 + t1;
    v1 = (s32)v1 >> (0x2 & 31);
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a0 + (-1));
    t0 = s4 + s1;
    v1 = v1 >> (0x1 & 31);
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (336));
    t0 = v1 + s1;
    v1 = *(volatile u8 *)(unsigned long)(a3 + (-1));
    s1 = s1 + 1;
    v1 = v1 >> (0x1 & 31);
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1; goto L_5b030;
L_5b0ac:
    a3 = *(volatile u32 *)(unsigned long)(sp + (376));
    s0 = hi_5b0b0;
    s0 = s0 - hi_5b0b0 + (u32)(unsigned long)ref_defog_wei_interpcot;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5b0c0;
L_5b0c0:
    a3 = *(volatile u32 *)(unsigned long)(sp + (380));
    a2 = *(volatile u32 *)(unsigned long)(sp + (328));
    a1 = s8;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5b0d4;
L_5b0d4:
    a3 = *(volatile u32 *)(unsigned long)(sp + (384));
    a2 = s7;
    a1 = s6;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5b0e8;
L_5b0e8:
    a3 = *(volatile u32 *)(unsigned long)(sp + (388));
    a2 = s5;
    a1 = s4;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5b0fc;
L_5b0fc:
    a3 = *(volatile u32 *)(unsigned long)(sp + (392));
    a1 = *(volatile u32 *)(unsigned long)(sp + (336));
    ra = *(volatile u32 *)(unsigned long)(sp + (436));
    s8 = *(volatile u32 *)(unsigned long)(sp + (432));
    s7 = *(volatile u32 *)(unsigned long)(sp + (428));
    s6 = *(volatile u32 *)(unsigned long)(sp + (424));
    s5 = *(volatile u32 *)(unsigned long)(sp + (420));
    s4 = *(volatile u32 *)(unsigned long)(sp + (416));
    s2 = *(volatile u32 *)(unsigned long)(sp + (408));
    a2 = s3;
    a0 = s1;
    s3 = *(volatile u32 *)(unsigned long)(sp + (412));
    s1 = *(volatile u32 *)(unsigned long)(sp + (404));
    t9 = s0;
    s0 = *(volatile u32 *)(unsigned long)(sp + (400));
    callee = t9; sp = sp + 440;
    switch (callee) { case 0x5aa34: goto L_5aa34; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
}
