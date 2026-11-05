/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e17c0[] __asm__("t32_data_e17c0");
extern unsigned char ref_tisp_simple_intp_uint16[] __asm__("tisp_simple_intp_uint16");
extern unsigned char ref_tisp_simple_intp_uint8[] __asm__("tisp_simple_intp_uint8");
extern unsigned char ref_tisp_round_int64[] __asm__("tisp_round_int64");
u64 tisp_gib_interp_by_again(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_41c30 = ((u32)(unsigned long)ref_t32_data_e17c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_41cb8 = ((u32)(unsigned long)ref_tisp_simple_intp_uint16 + 0x8000U) & 0xffff0000U;
    const u32 hi_41f10 = ((u32)(unsigned long)ref_tisp_simple_intp_uint8 + 0x8000U) & 0xffff0000U;
    const u32 hi_41f94 = ((u32)(unsigned long)ref_tisp_round_int64 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
L_41c28:
    sp = sp + -64;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    s0 = hi_41c30;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s6;
    s0 = s0 - hi_41c30 + (u32)(unsigned long)ref_t32_data_e17c0;
    s6 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (60)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s3;
    v0 = s6 + s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = 1;
    s2 = a1 & 0xffff;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    s1 = a1 >> (0x10 & 31);
    s4 = *(volatile u8 *)(unsigned long)(a2 + (544));
    s7 = *(volatile u8 *)(unsigned long)(a2 + (545));
    s8 = *(volatile u16 *)(unsigned long)(v1 + (0));
    branch = (s4 == a0); s3 = *(volatile u32 *)(unsigned long)(v0 + (8));
    if (branch) goto L_41cac;
    goto L_41c90;
L_41c90:
    branch = (s4 != 0); ;
    if (branch) goto L_41ca4;
    goto L_41c98;
L_41c98:
    a0 = (u32)s7 < (u32)(2);
    branch = (a0 != 0); a0 = 1;
    if (branch) goto L_41cac;
    goto L_41ca4;
L_41ca4:
    if (s8 == a0) { v1 = *(volatile u16 *)(unsigned long)(v1 + (2)); goto L_41e84; }
    goto L_41cac;
L_41cac:
    v1 = *(volatile u32 *)(unsigned long)(a2 + (4));
    if (v1 != 0) { v1 = *(volatile u16 *)(unsigned long)(a2 + (146)); goto L_41ddc; }
    goto L_41cb8;
L_41cb8:
    s5 = hi_41cb8;
    s5 = s5 - hi_41cb8 + (u32)(unsigned long)ref_tisp_simple_intp_uint16;
    a2 = a2 + 36;
    a1 = s2;
    callee = s5; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41cd0;
L_41cd0:
    *(volatile u16 *)(unsigned long)(s3 + (64)) = v0;
    s3 = s0 + s6;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a1 = s2;
    a0 = s1;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = a2 + 58;
    callee = s5; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41cf8;
L_41cf8:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a1 = s2;
    a0 = s1;
    *(volatile u16 *)(unsigned long)(v1 + (66)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = a2 + 80;
    callee = s5; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41d20;
L_41d20:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a1 = s2;
    a0 = s1;
    *(volatile u16 *)(unsigned long)(v1 + (68)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = a2 + 102;
    callee = s5; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41d48;
L_41d48:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a0 = s1;
    a1 = s2;
    *(volatile u16 *)(unsigned long)(v1 + (70)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = a2 + 124;
    callee = s5; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41d70;
L_41d70:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    *(volatile u16 *)(unsigned long)(v1 + (72)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(v1 + (547));
    if (a0 != 0) { v0 = 1; goto L_41e24; }
    goto L_41d8c;
L_41d8c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (64));
    *(volatile u16 *)(unsigned long)(v1 + (146)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (66));
    *(volatile u16 *)(unsigned long)(v1 + (148)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (68));
    *(volatile u16 *)(unsigned long)(v1 + (150)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (70));
    *(volatile u16 *)(unsigned long)(v1 + (152)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (72));
    *(volatile u16 *)(unsigned long)(v1 + (154)) = v0; goto L_41e20;
L_41ddc:
    *(volatile u16 *)(unsigned long)(s3 + (64)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (148));
    *(volatile u16 *)(unsigned long)(v1 + (66)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (150));
    *(volatile u16 *)(unsigned long)(v1 + (68)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (152));
    *(volatile u16 *)(unsigned long)(v1 + (70)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (154));
    *(volatile u16 *)(unsigned long)(v1 + (72)) = v0;
L_41e20:
    v0 = 1;
L_41e24:
    branch = (s8 == v0); v0 = s0 + s6;
    if (branch) goto L_41ec8;
    goto L_41e2c;
L_41e2c:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (64));
    *(volatile u16 *)(unsigned long)(v1 + (2)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (66));
    *(volatile u16 *)(unsigned long)(v1 + (4)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (68));
    *(volatile u16 *)(unsigned long)(v1 + (6)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (70));
    *(volatile u16 *)(unsigned long)(v1 + (8)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (72));
    *(volatile u16 *)(unsigned long)(v1 + (10)) = v0; goto L_41ef8;
L_41e84:
    *(volatile u16 *)(unsigned long)(s3 + (64)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (4));
    *(volatile u16 *)(unsigned long)(v1 + (66)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (6));
    *(volatile u16 *)(unsigned long)(v1 + (68)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (8));
    *(volatile u16 *)(unsigned long)(v1 + (70)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (10));
    *(volatile u16 *)(unsigned long)(v1 + (72)) = v0;
L_41ec8:
    v0 = s0 + s6;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = 1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (547));
    if (a1 != a0) { v0 = s0 + s6; goto L_41efc; }
    goto L_41ee4;
L_41ee4:
    a0 = 2;
    if (s4 == a0) { a0 = *(volatile u32 *)(unsigned long)(v0 + (16)); goto L_41ff0; }
    goto L_41ef0;
L_41ef0:
    branch = (s4 == 0); ;
    if (branch) goto L_41fe4;
    goto L_41ef8;
L_41ef8:
    v0 = s0 + s6;
L_41efc:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(a2 + (4));
    branch = (v1 != 0); s3 = *(volatile u32 *)(unsigned long)(v0 + (8));
    if (branch) goto L_41f30;
    goto L_41f10;
L_41f10:
    v0 = hi_41f10;
    a2 = a2 + 519;
    a1 = s2;
    v0 = v0 - hi_41f10 + (u32)(unsigned long)ref_tisp_simple_intp_uint8;
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41f28;
L_41f28:
    *(volatile u8 *)(unsigned long)(s3 + (128)) = v0; goto L_41f38;
L_41f30:
    v0 = *(volatile u8 *)(unsigned long)(a2 + (530));
    *(volatile u8 *)(unsigned long)(s3 + (128)) = v0;
L_41f38:
    s0 = s0 + s6;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    s0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u16 *)(unsigned long)(s0 + (66));
    a0 = *(volatile u16 *)(unsigned long)(s0 + (64));
    v0 = (u32)a0 < (u32)(v1);
    if (v0 != 0) a0 = v1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (68));
    v0 = (u32)v1 < (u32)(a0);
    if (v0 == 0) a0 = v1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (70));
    v0 = (u32)v1 < (u32)(a0);
    if (v0 == 0) a0 = v1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (72));
    v0 = (u32)v1 < (u32)(a0);
    if (v0 == 0) a0 = v1;
    v0 = a0 >> (0xb & 31);
    branch = (v0 != 0); v0 = 8191;
    if (branch) goto L_41fac;
    goto L_41f84;
L_41f84:
    v0 = 4096;
    a0 = v0 - a0;
    v0 = 0x200U << 16;
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    v0 = hi_41f94;
    a2 = 1;
    a1 = 0;
    v0 = v0 - hi_41f94 + (u32)(unsigned long)ref_tisp_round_int64;
    callee = v0; a0 = lo;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41fac;
L_41fac:
    *(volatile u16 *)(unsigned long)(s0 + (74)) = v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
    s8 = *(volatile u32 *)(unsigned long)(sp + (56));
    s7 = *(volatile u32 *)(unsigned long)(sp + (52));
    s6 = *(volatile u32 *)(unsigned long)(sp + (48));
    s5 = *(volatile u32 *)(unsigned long)(sp + (44));
    s4 = *(volatile u32 *)(unsigned long)(sp + (40));
    s3 = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    v0 = 0;
    sp = sp + 64;
    return ((u64)v1 << 32) | v0;
L_41fe4:
    if (s7 != a0) { v0 = s0 + s6; goto L_41efc; }
    goto L_41fec;
L_41fec:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
L_41ff0:
    a0 = *(volatile u16 *)(unsigned long)(a0 + (2));
    *(volatile u16 *)(unsigned long)(v1 + (146)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (4));
    *(volatile u16 *)(unsigned long)(v1 + (148)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (6));
    *(volatile u16 *)(unsigned long)(v1 + (150)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (8));
    *(volatile u16 *)(unsigned long)(v1 + (152)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (10));
    *(volatile u16 *)(unsigned long)(v1 + (154)) = v0; goto L_41ef8;
}
