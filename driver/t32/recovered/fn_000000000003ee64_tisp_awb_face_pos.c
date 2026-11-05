/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
extern unsigned char ref_tisp_reg_write[] __asm__("tisp_reg_write");
extern unsigned char ref_system_reg_set_awb_trig[] __asm__("system_reg_set_awb_trig");
extern unsigned char ref_t32_data_d03a0[] __asm__("t32_data_d03a0");
u64 tisp_awb_face_pos(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3ee74 = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_3efa8 = ((u32)(unsigned long)ref_tisp_reg_write + 0x8000U) & 0xffff0000U;
    const u32 hi_3efac = ((u32)(unsigned long)ref_system_reg_set_awb_trig + 0x8000U) & 0xffff0000U;
    const u32 hi_3efb4 = ((u32)(unsigned long)ref_t32_data_d03a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_3efd4 = ((u32)(unsigned long)ref_tisp_reg_write + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
    stack[18] = arg4;
    stack[19] = arg5;
L_3ee64:
    sp = sp + -56;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s2;
    s5 = a0;
    s2 = hi_3ee74;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s3;
    s2 = s2 - hi_3ee74 + (u32)(unsigned long)ref_t32_data_e16b4;
    s3 = s5 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s4;
    v1 = s3 + s2;
    t2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = a2 & 0xffff;
    s0 = a3 & 0xffff;
    t1 = *(volatile u32 *)(unsigned long)(t2 + (4));
    s1 = a2;
    a2 = (u32)s0 < (u32)(a2);
    a1 = a1 & 0xff;
    a0 = *(volatile u16 *)(unsigned long)(sp + (72));
    v0 = *(volatile u16 *)(unsigned long)(sp + (76));
    a3 = *(volatile u16 *)(unsigned long)(t1 + (28690));
    branch = (a2 == 0); t3 = *(volatile u16 *)(unsigned long)(t1 + (28692));
    if (branch) goto L_3eed4;
    goto L_3eed0;
L_3eed0:
    s1 = s0;
L_3eed4:
    s1 = s1 & 0xffff;
    v1 = 2;
    a2 = (u32)s1 < (u32)(2);
    if (a2 != 0) s1 = v1;
    a2 = (u32)s0 < (u32)(2);
    if (a2 != 0) s0 = v1;
    v1 = a0;
    a0 = (u32)v0 < (u32)(a0);
    if (a0 != 0) { v1 = v0; goto L_3eefc; }
    goto L_3eefc;
L_3eefc:
    t3 = a3 * t3;
    v1 = v1 & 0xffff;
    a0 = 2;
    a2 = (u32)v1 < (u32)(2);
    if (a2 != 0) v1 = a0;
    a2 = (u32)v0 < (u32)(2);
    if (a2 != 0) v0 = a0;
    t4 = 2;
    a0 = 6;
    t5 = 4;
    t3 = t3 >> (0x3 & 31);
    a2 = s0 - s1;
L_3ef2c:
    if (a2 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)a2 / (s32)a0; hi = (s32)a2 % (s32)a0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    s1 = a2 + s1;
    s1 = s1 & 0xffff;
    s0 = s0 - s1;
    t0 = s0 << (0x2 & 31);
    s0 = t0 + s0;
    if (s0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)s0 / (s32)a0; hi = (s32)s0 % (s32)a0; } else { lo = (s32)s0 < 0 ? 1 : ~0U; hi = s0; }
    a2 = v0 - v1;
    s0 = lo;
    s0 = s1 + s0;
    s0 = s0 & 0xffff;
    if (a2 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)a2 / (s32)a0; hi = (s32)a2 % (s32)a0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    v1 = a2 + v1;
    v1 = v1 & 0xffff;
    v0 = v0 - v1;
    a3 = v0 << (0x2 & 31);
    v0 = a3 + v0;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a2 = s0 - s1;
    v0 = lo;
    v0 = v1 + v0;
    v0 = v0 & 0xffff;
    a3 = v0 - v1;
    a2 = a2 * a3;
    if (a2 == 0x80000000U && t5 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t5) { lo = (s32)a2 / (s32)t5; hi = (s32)a2 % (s32)t5; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    a2 = (u32)a2 < (u32)(t3);
    if (a2 == 0) { t4 = t4 + -1; goto L_3efcc; }
    goto L_3efa8;
L_3efa8:
    s6 = hi_3efa8;
L_3efac:
    s4 = hi_3efac;
    a0 = 1;
    s7 = hi_3efb4;
    s6 = s6 - hi_3efa8 + (u32)(unsigned long)ref_tisp_reg_write;
    branch = (a1 != a0); s4 = s4 - hi_3efac + (u32)(unsigned long)ref_system_reg_set_awb_trig;
    if (branch) goto L_3f07c;
    goto L_3efc4;
L_3efc4:
    a2 = 0x2U << 16; goto L_3efe0;
L_3efcc:
    t4 = t4 & 0xff;
    branch = (t4 == 0); s6 = hi_3efd4;
    if (branch) goto L_3efac;
    goto L_3efd8;
L_3efd8:
    a2 = s0 - s1; goto L_3ef2c;
L_3efe0:
    t1 = t1 + a2;
    a1 = *(volatile u32 *)(unsigned long)(t1 + (-11132));
    a1 = a1 + 1;
    *(volatile u32 *)(unsigned long)(t1 + (-11132)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(t2 + (4));
    a1 = 255;
    a0 = a0 + a2;
    a2 = *(volatile u32 *)(unsigned long)(a0 + (-11132));
    if (a2 == a1) { *(volatile u32 *)(unsigned long)(a0 + (-11132)) = 0; goto L_3f008; }
    goto L_3f008;
L_3f008:
    a0 = *(volatile u8 *)(unsigned long)(s7 - hi_3efb4 + (u32)(unsigned long)ref_t32_data_d03a0);
    branch = (a0 != 0); a1 = 1923;
    if (branch) goto L_3f01c;
    goto L_3f014;
L_3f014:
    a1 = 0x1U << 16;
    a1 = a1 + 24800;
L_3f01c:
    a2 = v0 << (0x10 & 31);
    a2 = a2 | v1;
    callee = s6; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3f02c;
L_3f02c:
    v0 = *(volatile u8 *)(unsigned long)(s7 - hi_3efb4 + (u32)(unsigned long)ref_t32_data_d03a0);
    branch = (v0 != 0); a1 = 1924;
    if (branch) goto L_3f040;
    goto L_3f038;
L_3f038:
    a1 = 0x1U << 16;
    a1 = a1 + 24804;
L_3f040:
    a2 = s0 << (0x10 & 31);
    a2 = a2 | s1;
    callee = s6; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3f050;
L_3f050:
    a0 = 1;
    callee = s4; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3f05c;
L_3f05c:
    v0 = s2 + s3;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = 1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u8 *)(unsigned long)(v1 + (28706)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u8 *)(unsigned long)(v0 + (28707)) = 0; goto L_3f0e0;
L_3f07c:
    v0 = *(volatile u8 *)(unsigned long)(s7 - hi_3efb4 + (u32)(unsigned long)ref_t32_data_d03a0);
    branch = (v0 != 0); a1 = 1923;
    if (branch) goto L_3f090;
    goto L_3f088;
L_3f088:
    a1 = 0x1U << 16;
    a1 = a1 + 24800;
L_3f090:
    a2 = 0x2U << 16;
    a2 = a2 + 2;
    callee = s6; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3f0a0;
L_3f0a0:
    v0 = *(volatile u8 *)(unsigned long)(s7 - hi_3efb4 + (u32)(unsigned long)ref_t32_data_d03a0);
    branch = (v0 != 0); a1 = 1924;
    if (branch) goto L_3f0b4;
    goto L_3f0ac;
L_3f0ac:
    a1 = 0x1U << 16;
    a1 = a1 + 24804;
L_3f0b4:
    a2 = 0x2U << 16;
    a2 = a2 + 2;
    callee = s6; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3f0c4;
L_3f0c4:
    a1 = 0;
    callee = s4; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3f0d0;
L_3f0d0:
    v0 = s2 + s3;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u8 *)(unsigned long)(v0 + (28706)) = 0;
L_3f0e0:
    s2 = s2 + s3;
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    v1 = 0x2U << 16;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = v0 + v1;
    v1 = 1;
    *(volatile u8 *)(unsigned long)(v0 + (-23476)) = v1;
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    s7 = *(volatile u32 *)(unsigned long)(sp + (48));
    s6 = *(volatile u32 *)(unsigned long)(sp + (44));
    s5 = *(volatile u32 *)(unsigned long)(sp + (40));
    s4 = *(volatile u32 *)(unsigned long)(sp + (36));
    s3 = *(volatile u32 *)(unsigned long)(sp + (32));
    s2 = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = 0;
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
