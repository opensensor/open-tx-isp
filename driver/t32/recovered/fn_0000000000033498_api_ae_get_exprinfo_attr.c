/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dd2d4[] __asm__("t32_data_dd2d4");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
extern unsigned char ref_private_msleep[] __asm__("private_msleep");
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_tisp_log2_fixed_to_fixed[] __asm__("tisp_log2_fixed_to_fixed");
u64 api_ae_get_exprinfo_attr(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_334ac = ((u32)(unsigned long)ref_t32_data_dd2d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_334d4 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    const u32 hi_334e8 = ((u32)(unsigned long)ref_private_msleep + 0x8000U) & 0xffff0000U;
    const u32 hi_3352c = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_3353c = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_3389c = ((u32)(unsigned long)ref_tisp_log2_fixed_to_fixed + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_33498:
    sp = sp + -56;
    v1 = 232;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    s0 = a1;
    a1 = a0 * v1;
    v0 = hi_334ac;
    v0 = v0 - hi_334ac + (u32)(unsigned long)ref_t32_data_dd2d4;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    s5 = hi_334d4;
    s3 = a0 << (0x2 & 31);
    s5 = s5 - hi_334d4 + (u32)(unsigned long)ref_t32_data_e1588;
    s2 = 0;
    s5 = s3 + s5;
    s6 = hi_334e8;
    v0 = a1 + v0;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (56));
    s4 = *(volatile u16 *)(unsigned long)(v0 + (2));
    s7 = 50;
    a1 = *(volatile u32 *)(unsigned long)(s5 + (0));
L_33500:
    v0 = *(volatile u8 *)(unsigned long)(a1 + (1285));
    branch = (v0 == 0); v0 = s6 - hi_334e8 + (u32)(unsigned long)ref_private_msleep;
    if (branch) goto L_3352c;
    goto L_3350c;
L_3350c:
    callee = v0; a0 = 10;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_33514;
L_33514:
    v0 = s2 + 1;
    s2 = v0 & 0xff;
    if (s2 != s7) { a1 = *(volatile u32 *)(unsigned long)(s5 + (0)); goto L_33500; }
    goto L_33524;
L_33524:
    v0 = 50; goto L_338b4;
L_3352c:
    v0 = hi_3352c;
    v0 = v0 - hi_3352c + (u32)(unsigned long)ref_t32_data_e15a8;
    s3 = v0 + s3;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    s6 = hi_3353c;
    a2 = 9;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = a1 + 1276;
    s6 = s6 - hi_3353c + ((u32)(unsigned long)ref_memcpy + (0));
    callee = s6; a0 = a0 + 12833;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_33558;
L_33558:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a1 = *(volatile u32 *)(unsigned long)(s5 + (0));
    a2 = 32;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = a1 + 576;
    callee = s6; a0 = a0 + 8608;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_33574;
L_33574:
    v1 = *(volatile u32 *)(unsigned long)(s3 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u8 *)(unsigned long)(v0 + (12841));
    v0 = a0 ^ 0x1;
    if (v0 != 0) a0 = 0;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = a0;
    a0 = 0xfU << 16;
    v0 = s1 & 0xffff;
    a0 = a0 + 16960;
    s1 = s1 >> (0x10 & 31);
    a0 = v0 * a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (12833));
    *(volatile u32 *)(unsigned long)(s0 + (8)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (12834));
    *(volatile u32 *)(unsigned long)(s0 + (12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    s1 = s1 * s4;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (12835));
    *(volatile u32 *)(unsigned long)(s0 + (16)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (12836));
    *(volatile u32 *)(unsigned long)(s0 + (20)) = v0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8608));
    if (s1) { lo = a0 / s1; hi = a0 % s1; } else { lo = ~0U; hi = a0; }
    branch = (v0 == 0); a0 = lo;
    if (branch) goto L_335f0;
    goto L_335ec;
L_335ec:
    a1 = a0 * a1;
L_335f0:
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8612));
    *(volatile u32 *)(unsigned long)(s0 + (28)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8616));
    *(volatile u32 *)(unsigned long)(s0 + (32)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8620));
    *(volatile u32 *)(unsigned long)(s0 + (36)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1250));
    *(volatile u32 *)(unsigned long)(s0 + (40)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1251));
    *(volatile u32 *)(unsigned long)(s0 + (44)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1252));
    *(volatile u32 *)(unsigned long)(s0 + (48)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1253));
    *(volatile u32 *)(unsigned long)(s0 + (52)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1254));
    *(volatile u32 *)(unsigned long)(s0 + (56)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1255));
    *(volatile u32 *)(unsigned long)(s0 + (60)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1256));
    *(volatile u32 *)(unsigned long)(s0 + (64)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1257));
    *(volatile u32 *)(unsigned long)(s0 + (68)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    branch = (v0 == 0); a1 = *(volatile u32 *)(unsigned long)(a1 + (448));
    if (branch) goto L_33688;
    goto L_33684;
L_33684:
    a1 = a0 * a1;
L_33688:
    *(volatile u32 *)(unsigned long)(s0 + (72)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (452));
    *(volatile u32 *)(unsigned long)(s0 + (76)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (456));
    *(volatile u32 *)(unsigned long)(s0 + (80)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (460));
    *(volatile u32 *)(unsigned long)(s0 + (84)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    branch = (v0 == 0); a1 = *(volatile u32 *)(unsigned long)(a1 + (464));
    if (branch) goto L_336c0;
    goto L_336bc;
L_336bc:
    a1 = a0 * a1;
L_336c0:
    *(volatile u32 *)(unsigned long)(s0 + (88)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (468));
    *(volatile u32 *)(unsigned long)(s0 + (92)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (472));
    *(volatile u32 *)(unsigned long)(s0 + (96)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (476));
    *(volatile u32 *)(unsigned long)(s0 + (100)) = a1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = -256;
    a2 = *(volatile u32 *)(unsigned long)(a3 + (12836));
    a2 = a1 & a2;
    a1 = 0x101U << 16;
    a1 = a1 + 256;
    if (a2 != a1) { *(volatile u32 *)(unsigned long)(s0 + (104)) = 0; goto L_3371c; }
    goto L_33708;
L_33708:
    a1 = *(volatile u8 *)(unsigned long)(a3 + (12840));
    a2 = 1;
    if (a1 != a2) { *(volatile u32 *)(unsigned long)(s0 + (104)) = 0; goto L_3371c; }
    goto L_33718;
L_33718:
    *(volatile u32 *)(unsigned long)(s0 + (104)) = a1;
L_3371c:
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (12837));
    *(volatile u32 *)(unsigned long)(s0 + (108)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (12838));
    *(volatile u32 *)(unsigned long)(s0 + (112)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (12839));
    *(volatile u32 *)(unsigned long)(s0 + (116)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (12840));
    *(volatile u32 *)(unsigned long)(s0 + (120)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    branch = (v0 == 0); a1 = *(volatile u32 *)(unsigned long)(a1 + (8624));
    if (branch) goto L_3375c;
    goto L_33758;
L_33758:
    a1 = a0 * a1;
L_3375c:
    *(volatile u32 *)(unsigned long)(s0 + (124)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8628));
    *(volatile u32 *)(unsigned long)(s0 + (128)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8632));
    *(volatile u32 *)(unsigned long)(s0 + (132)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8636));
    *(volatile u32 *)(unsigned long)(s0 + (136)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1258));
    *(volatile u32 *)(unsigned long)(s0 + (140)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1259));
    *(volatile u32 *)(unsigned long)(s0 + (144)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1260));
    *(volatile u32 *)(unsigned long)(s0 + (148)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1261));
    *(volatile u32 *)(unsigned long)(s0 + (152)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1262));
    *(volatile u32 *)(unsigned long)(s0 + (156)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1263));
    *(volatile u32 *)(unsigned long)(s0 + (160)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1264));
    *(volatile u32 *)(unsigned long)(s0 + (164)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1265));
    *(volatile u32 *)(unsigned long)(s0 + (168)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    branch = (v0 == 0); a1 = *(volatile u32 *)(unsigned long)(a1 + (480));
    if (branch) goto L_337f4;
    goto L_337f0;
L_337f0:
    a1 = a0 * a1;
L_337f4:
    *(volatile u32 *)(unsigned long)(s0 + (172)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (484));
    *(volatile u32 *)(unsigned long)(s0 + (176)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (488));
    *(volatile u32 *)(unsigned long)(s0 + (180)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (492));
    *(volatile u32 *)(unsigned long)(s0 + (184)) = a1;
    branch = (v0 != 0); a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    if (branch) goto L_3382c;
    goto L_33824;
L_33824:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (496)); goto L_33834;
L_3382c:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (496));
    a0 = a0 * v0;
L_33834:
    *(volatile u32 *)(unsigned long)(s0 + (188)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = 16;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (500));
    *(volatile u32 *)(unsigned long)(s0 + (192)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (504));
    *(volatile u32 *)(unsigned long)(s0 + (196)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (508));
    *(volatile u32 *)(unsigned long)(s0 + (200)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (7480));
    *(volatile u32 *)(unsigned long)(s0 + (204)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (7512));
    *(volatile u32 *)(unsigned long)(s0 + (208)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (7476));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (7472));
    a0 = a0 << (0x16 & 31);
    v0 = v0 >> (0xa & 31);
    v0 = a0 | v0;
    *(volatile u32 *)(unsigned long)(s0 + (212)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (7472));
    v0 = hi_3389c;
    v0 = v0 - hi_3389c + (u32)(unsigned long)ref_tisp_log2_fixed_to_fixed;
    callee = v0; a1 = 10;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_338ac;
L_338ac:
    *(volatile u32 *)(unsigned long)(s0 + (216)) = v0;
    v0 = s2;
L_338b4:
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    s7 = *(volatile u32 *)(unsigned long)(sp + (48));
    s6 = *(volatile u32 *)(unsigned long)(sp + (44));
    s5 = *(volatile u32 *)(unsigned long)(sp + (40));
    s4 = *(volatile u32 *)(unsigned long)(sp + (36));
    s3 = *(volatile u32 *)(unsigned long)(sp + (32));
    s2 = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
