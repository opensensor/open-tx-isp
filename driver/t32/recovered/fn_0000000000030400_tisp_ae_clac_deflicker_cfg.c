/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
extern unsigned char ref_fix_point_mult3_32[] __asm__("fix_point_mult3_32");
u64 tisp_ae_clac_deflicker_cfg(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[82] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_30400 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_30440 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    const u32 hi_30470 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_304d0 = ((u32)(unsigned long)ref_fix_point_mult3_32 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[18];
L_30400:
    v0 = hi_30400;
    sp = sp + -72;
    a0 = a0 << (0x2 & 31);
    v0 = v0 - hi_30400 + (u32)(unsigned long)ref_t32_data_e15a8;
    v0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (68)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = hi_30440;
    v0 = v0 - hi_30440 + (u32)(unsigned long)ref_t32_data_e1588;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a0 = a0 + v0;
    s2 = *(volatile u32 *)(unsigned long)(a0 + (0));
    s4 = *(volatile u32 *)(unsigned long)(v1 + (1660));
    s0 = *(volatile u16 *)(unsigned long)(v1 + (1736));
    a2 = *(volatile u32 *)(unsigned long)(s2 + (1264));
    s1 = *(volatile u32 *)(unsigned long)(a1 + (4));
    s4 = s4 << (0x1 & 31);
    s5 = 1;
    s4 = s4 << (s0 & 31);
    s3 = hi_30470;
    s3 = s3 - hi_30470 + (u32)(unsigned long)ref_fix_point_div_32;
    if (a2 == 0) a2 = s5;
    a1 = s4;
    a0 = s0;
    s6 = *(volatile u32 *)(unsigned long)(s2 + (1260));
    callee = s3; s7 = *(volatile u16 *)(unsigned long)(s1 + (8554));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_30490;
L_30490:
    v0 = v0 >> (s0 & 31);
    v0 = v0 & 0xff;
    v1 = (u32)v0 < (u32)(121);
    s2 = s2 + 1700;
    branch = (v1 != 0); s8 = s3;
    if (branch) goto L_304dc;
    goto L_304a8;
L_304a8:
    v0 = 120;
    *(volatile u8 *)(unsigned long)(s1 + (12842)) = v0;
L_304b0:
    v0 = 1;
    v1 = 2;
    v0 = v0 << (s0 & 31);
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    t1 = 0x3fffU << 16;
    t0 = s7 << (s0 & 31);
    s3 = 1;
    t1 = t1 | 0xffff;
    s7 = hi_304d0;
    v1 = lo; goto L_304ec;
L_304dc:
    if (v0 != 0) { *(volatile u8 *)(unsigned long)(s1 + (12842)) = v0; goto L_304b0; }
    goto L_304e4;
L_304e4:
    *(volatile u8 *)(unsigned long)(s1 + (12842)) = s5; goto L_304b0;
L_304ec:
    v0 = *(volatile u8 *)(unsigned long)(s1 + (12842));
    a0 = (u32)v0 < (u32)(s3);
    branch = (a0 != 0); t2 = s3 << (s0 & 31);
    if (branch) goto L_30568;
    goto L_304fc;
L_304fc:
    a1 = t0;
    a2 = s4;
    a0 = s0;
    s5 = s3 + t1;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (24)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t0;
    callee = s8; *(volatile u32 *)(unsigned long)(sp + (20)) = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_30520;
L_30520:
    t2 = *(volatile u32 *)(unsigned long)(sp + (20));
    a3 = v0;
    a2 = s6;
    a1 = t2;
    v0 = s7 - hi_304d0 + (u32)(unsigned long)ref_fix_point_mult3_32;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3053c;
L_3053c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s5 = s5 << (0x2 & 31);
    s5 = s2 + s5;
    v0 = v0 + v1;
    v0 = v0 >> (s0 & 31);
    s3 = s3 + 1;
    *(volatile u32 *)(unsigned long)(s5 + (0)) = v0;
    s3 = s3 & 0xff;
    t1 = *(volatile u32 *)(unsigned long)(sp + (24));
    t0 = *(volatile u32 *)(unsigned long)(sp + (16)); goto L_304ec;
L_30568:
    a0 = 0x3fffU << 16;
    a0 = a0 | 0xffff;
L_30570:
    v1 = (u32)v0 < (u32)(120);
    if (v1 == 0) { v0 = *(volatile u8 *)(unsigned long)(s1 + (12842)); goto L_305a8; }
    goto L_3057c;
L_3057c:
    v1 = *(volatile u8 *)(unsigned long)(s1 + (12842));
    v1 = v1 + a0;
    v1 = v1 << (0x2 & 31);
    v1 = s2 + v1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = v0 << (0x2 & 31);
    v1 = s2 + v1;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a1;
    v0 = v0 & 0xff; goto L_30570;
L_305a8:
    v0 = v0 + -1;
    *(volatile u8 *)(unsigned long)(s1 + (12842)) = v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (68));
    s8 = *(volatile u32 *)(unsigned long)(sp + (64));
    s7 = *(volatile u32 *)(unsigned long)(sp + (60));
    s6 = *(volatile u32 *)(unsigned long)(sp + (56));
    s5 = *(volatile u32 *)(unsigned long)(sp + (52));
    s4 = *(volatile u32 *)(unsigned long)(sp + (48));
    s3 = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    sp = sp + 72;
    return ((u64)v1 << 32) | v0;
}
