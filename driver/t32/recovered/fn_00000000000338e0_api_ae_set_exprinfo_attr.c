/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dd2d4[] __asm__("t32_data_dd2d4");
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_tisp_math_exp2[] __asm__("tisp_math_exp2");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
u64 api_ae_set_exprinfo_attr(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_338f8 = ((u32)(unsigned long)ref_t32_data_dd2d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_33924 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_33d0c = ((u32)(unsigned long)ref_tisp_math_exp2 + 0x8000U) & 0xffff0000U;
    const u32 hi_33d70 = ((u32)(unsigned long)ref_tisp_math_exp2 + 0x8000U) & 0xffff0000U;
    const u32 hi_33f7c = ((u32)(unsigned long)ref_tisp_math_exp2 + 0x8000U) & 0xffff0000U;
    const u32 hi_33fdc = ((u32)(unsigned long)ref_tisp_math_exp2 + 0x8000U) & 0xffff0000U;
    const u32 hi_3402c = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_338e0:
    sp = sp + -48;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    s0 = a1;
    a1 = 232;
    v0 = a0 * a1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    s4 = hi_338f8;
    s4 = s4 - hi_338f8 + (u32)(unsigned long)ref_t32_data_dd2d4;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s6;
    s5 = a0;
    s3 = 0xfU << 16;
    s3 = s3 + 16960;
    s1 = hi_33924;
    s2 = s5 << (0x2 & 31);
    s1 = s1 - hi_33924 + (u32)(unsigned long)ref_t32_data_e15a8;
    a1 = v0 + s4;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (56));
    v1 = a0 & 0xffff;
    v0 = v1 * s3;
    v1 = *(volatile u16 *)(unsigned long)(a1 + (2));
    s3 = a0 >> (0x10 & 31);
    a0 = *(volatile u32 *)(unsigned long)(s0 + (4));
    s3 = v1 * s3;
    v1 = 1;
    if (s3) { lo = v0 / s3; hi = v0 % s3; } else { lo = ~0U; hi = v0; }
    v0 = s1 + s2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (a0 != v1); s3 = lo;
    if (branch) goto L_339f4;
    goto L_33968;
L_33968:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u8 *)(unsigned long)(v1 + (12841)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    branch = (a1 == 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (24));
    if (branch) goto L_33988;
    goto L_33980;
L_33980:
    if (s3) { lo = v1 / s3; hi = v1 % s3; } else { lo = ~0U; hi = v1; }
    v1 = lo;
L_33988:
    *(volatile u32 *)(unsigned long)(a0 + (8608)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (28));
    *(volatile u32 *)(unsigned long)(v1 + (8612)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (32));
    *(volatile u32 *)(unsigned long)(v1 + (8616)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (36));
    *(volatile u32 *)(unsigned long)(v1 + (8620)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    branch = (a1 == 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (124));
    if (branch) goto L_339c8;
    goto L_339c0;
L_339c0:
    if (s3) { lo = v1 / s3; hi = v1 % s3; } else { lo = ~0U; hi = v1; }
    v1 = lo;
L_339c8:
    *(volatile u32 *)(unsigned long)(a0 + (8624)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (128));
    *(volatile u32 *)(unsigned long)(v1 + (8628)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (132));
    *(volatile u32 *)(unsigned long)(v1 + (8632)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (136));
    *(volatile u32 *)(unsigned long)(v0 + (8636)) = v1; goto L_33b44;
L_339f4:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u8 *)(unsigned long)(a0 + (12841)) = 0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u32 *)(unsigned long)(s0 + (8));
    *(volatile u8 *)(unsigned long)(a0 + (12833)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (8));
    if (a0 != v1) { v1 = *(volatile u32 *)(unsigned long)(v0 + (4)); goto L_33a34; }
    goto L_33a14;
L_33a14:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    branch = (a1 == 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (24));
    if (branch) goto L_33a2c;
    goto L_33a24;
L_33a24:
    if (s3) { lo = v1 / s3; hi = v1 % s3; } else { lo = ~0U; hi = v1; }
    v1 = lo;
L_33a2c:
    *(volatile u32 *)(unsigned long)(a0 + (8608)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
L_33a34:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (12));
    *(volatile u8 *)(unsigned long)(v1 + (12834)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (12));
    v1 = 1;
    branch = (a0 != v1); v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    if (branch) goto L_33a58;
    goto L_33a4c;
L_33a4c:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (28));
    *(volatile u32 *)(unsigned long)(v1 + (8612)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
L_33a58:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (20));
    *(volatile u8 *)(unsigned long)(v1 + (12836)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (20));
    v1 = 1;
    branch = (a0 != v1); v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    if (branch) goto L_33a7c;
    goto L_33a70;
L_33a70:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (36));
    *(volatile u32 *)(unsigned long)(v1 + (8620)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
L_33a7c:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (16));
    *(volatile u8 *)(unsigned long)(v1 + (12835)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (16));
    v1 = 1;
    branch = (a0 != v1); v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    if (branch) goto L_33aa0;
    goto L_33a94;
L_33a94:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (32));
    *(volatile u32 *)(unsigned long)(v1 + (8616)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
L_33aa0:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (108));
    *(volatile u8 *)(unsigned long)(v1 + (12837)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (108));
    v1 = 1;
    if (a0 != v1) { v1 = *(volatile u32 *)(unsigned long)(v0 + (4)); goto L_33ad8; }
    goto L_33ab8;
L_33ab8:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    branch = (a1 == 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (124));
    if (branch) goto L_33ad0;
    goto L_33ac8;
L_33ac8:
    if (s3) { lo = v1 / s3; hi = v1 % s3; } else { lo = ~0U; hi = v1; }
    v1 = lo;
L_33ad0:
    *(volatile u32 *)(unsigned long)(a0 + (8624)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
L_33ad8:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (112));
    *(volatile u8 *)(unsigned long)(v1 + (12838)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (112));
    v1 = 1;
    branch = (a0 != v1); v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    if (branch) goto L_33afc;
    goto L_33af0;
L_33af0:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (128));
    *(volatile u32 *)(unsigned long)(v1 + (8628)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
L_33afc:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (120));
    *(volatile u8 *)(unsigned long)(v1 + (12840)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (120));
    v1 = 1;
    branch = (a0 != v1); v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    if (branch) goto L_33b20;
    goto L_33b14;
L_33b14:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (136));
    *(volatile u32 *)(unsigned long)(v1 + (8636)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
L_33b20:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    *(volatile u8 *)(unsigned long)(v1 + (12839)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    v1 = 1;
    if (a0 != v1) { v1 = *(volatile u32 *)(unsigned long)(s0 + (40)); goto L_33b48; }
    goto L_33b38;
L_33b38:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (132));
    *(volatile u32 *)(unsigned long)(v0 + (8632)) = v1;
L_33b44:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (40));
L_33b48:
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33b7c;
    goto L_33b54;
L_33b54:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1250)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (a0 == 0); v0 = *(volatile u32 *)(unsigned long)(s0 + (72));
    if (branch) goto L_33b9c;
    goto L_33b70;
L_33b70:
    if (s3) { lo = v0 / s3; hi = v0 % s3; } else { lo = ~0U; hi = v0; }
    v0 = lo; goto L_33b9c;
L_33b7c:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1250)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 232;
    a0 = s5 * v0;
    v0 = a0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (68));
L_33b9c:
    *(volatile u32 *)(unsigned long)(v1 + (448)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (44));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33bc8;
    goto L_33bb0;
L_33bb0:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1251)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (76)); goto L_33bdc;
L_33bc8:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1251)) = 0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 1024;
L_33bdc:
    *(volatile u32 *)(unsigned long)(v0 + (452)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (48));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33c08;
    goto L_33bf0;
L_33bf0:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1252)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (80)); goto L_33c1c;
L_33c08:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1252)) = 0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 1024;
L_33c1c:
    *(volatile u32 *)(unsigned long)(v0 + (456)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (52));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33c48;
    goto L_33c30;
L_33c30:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1253)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (84)); goto L_33c5c;
L_33c48:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1253)) = 0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 1024;
L_33c5c:
    *(volatile u32 *)(unsigned long)(v0 + (460)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (56));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33c98;
    goto L_33c70;
L_33c70:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1254)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (a0 == 0); v0 = *(volatile u32 *)(unsigned long)(s0 + (88));
    if (branch) goto L_33cb8;
    goto L_33c8c;
L_33c8c:
    if (s3) { lo = v0 / s3; hi = v0 % s3; } else { lo = ~0U; hi = v0; }
    v0 = lo; goto L_33cb8;
L_33c98:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1254)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 232;
    a0 = s5 * v0;
    v0 = a0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (72));
L_33cb8:
    *(volatile u32 *)(unsigned long)(v1 + (464)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (60));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33ce8;
    goto L_33ccc;
L_33ccc:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1255)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (92));
    *(volatile u32 *)(unsigned long)(v0 + (468)) = v1; goto L_33d20;
L_33ce8:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 10;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1255)) = 0;
    s6 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 232;
    v1 = s5 * v0;
    v0 = v1 + s4;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (36));
    v0 = hi_33d0c;
    v0 = v0 - hi_33d0c + (u32)(unsigned long)ref_tisp_math_exp2;
    callee = v0; a1 = 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_33d1c;
L_33d1c:
    *(volatile u32 *)(unsigned long)(s6 + (468)) = v0;
L_33d20:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (64));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33d4c;
    goto L_33d30;
L_33d30:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1256)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (96));
    *(volatile u32 *)(unsigned long)(v0 + (472)) = v1; goto L_33d84;
L_33d4c:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 10;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1256)) = 0;
    s6 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 232;
    v1 = s5 * v0;
    v0 = v1 + s4;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (40));
    v0 = hi_33d70;
    v0 = v0 - hi_33d70 + (u32)(unsigned long)ref_tisp_math_exp2;
    callee = v0; a1 = 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_33d80;
L_33d80:
    *(volatile u32 *)(unsigned long)(s6 + (472)) = v0;
L_33d84:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (68));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33db0;
    goto L_33d94;
L_33d94:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1257)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (100));
    *(volatile u32 *)(unsigned long)(v0 + (476)) = v1; goto L_33dbc;
L_33db0:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v0 + (1257)) = 0;
L_33dbc:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (140));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33df4;
    goto L_33dcc;
L_33dcc:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1258)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (a0 == 0); v0 = *(volatile u32 *)(unsigned long)(s0 + (172));
    if (branch) goto L_33e14;
    goto L_33de8;
L_33de8:
    if (s3) { lo = v0 / s3; hi = v0 % s3; } else { lo = ~0U; hi = v0; }
    v0 = lo; goto L_33e14;
L_33df4:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1258)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 232;
    a0 = s5 * v0;
    v0 = a0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (88));
L_33e14:
    *(volatile u32 *)(unsigned long)(v1 + (480)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (144));
    v0 = s1 + s2;
    v1 = 1;
    branch = (a0 != v1); v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    if (branch) goto L_33e40;
    goto L_33e2c;
L_33e2c:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1259)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (176)); goto L_33e50;
L_33e40:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1259)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 1024;
L_33e50:
    *(volatile u32 *)(unsigned long)(v0 + (484)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (148));
    v0 = s1 + s2;
    v1 = 1;
    branch = (a0 != v1); v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    if (branch) goto L_33e7c;
    goto L_33e68;
L_33e68:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1260)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (180)); goto L_33e8c;
L_33e7c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1260)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 1024;
L_33e8c:
    *(volatile u32 *)(unsigned long)(v0 + (488)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (152));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33eb8;
    goto L_33ea0;
L_33ea0:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1261)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (184)); goto L_33ecc;
L_33eb8:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1261)) = 0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 1024;
L_33ecc:
    *(volatile u32 *)(unsigned long)(v0 + (492)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (156));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33f08;
    goto L_33ee0;
L_33ee0:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1262)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (a0 == 0); v0 = *(volatile u32 *)(unsigned long)(s0 + (188));
    if (branch) goto L_33f28;
    goto L_33efc;
L_33efc:
    if (s3) { lo = v0 / s3; hi = v0 % s3; } else { lo = ~0U; hi = v0; }
    v0 = lo; goto L_33f28;
L_33f08:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1262)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 232;
    a0 = s5 * v0;
    v0 = a0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (92));
L_33f28:
    *(volatile u32 *)(unsigned long)(v1 + (496)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (160));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33f58;
    goto L_33f3c;
L_33f3c:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1263)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (192));
    *(volatile u32 *)(unsigned long)(v0 + (500)) = v1; goto L_33f90;
L_33f58:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 10;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1263)) = 0;
    s3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 232;
    v1 = s5 * v0;
    v0 = v1 + s4;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (36));
    v0 = hi_33f7c;
    v0 = v0 - hi_33f7c + (u32)(unsigned long)ref_tisp_math_exp2;
    callee = v0; a1 = 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_33f8c;
L_33f8c:
    *(volatile u32 *)(unsigned long)(s3 + (500)) = v0;
L_33f90:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (164));
    v0 = 1;
    branch = (v1 != v0); v0 = s1 + s2;
    if (branch) goto L_33fbc;
    goto L_33fa0;
L_33fa0:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1264)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (196));
    *(volatile u32 *)(unsigned long)(v0 + (504)) = v1; goto L_33ff4;
L_33fbc:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 10;
    a1 = 16;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (1264)) = 0;
    s3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 232;
    v1 = s5 * v0;
    v0 = hi_33fdc;
    v0 = v0 - hi_33fdc + (u32)(unsigned long)ref_tisp_math_exp2;
    s4 = v1 + s4;
    callee = v0; a0 = *(volatile u32 *)(unsigned long)(s4 + (40));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_33ff0;
L_33ff0:
    *(volatile u32 *)(unsigned long)(s3 + (504)) = v0;
L_33ff4:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (168));
    v0 = 1;
    branch = (v1 != v0); s1 = s1 + s2;
    if (branch) goto L_34020;
    goto L_34004;
L_34004:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1265)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (200));
    *(volatile u32 *)(unsigned long)(v0 + (508)) = v1; goto L_3402c;
L_34020:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(v0 + (1265)) = 0;
L_3402c:
    v0 = hi_3402c;
    v0 = v0 - hi_3402c + (u32)(unsigned long)ref_t32_data_e1588;
    s2 = v0 + s2;
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    v1 = 1;
    *(volatile u8 *)(unsigned long)(v0 + (1285)) = v1;
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s6 = *(volatile u32 *)(unsigned long)(sp + (40));
    s5 = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
