/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e17c0[] __asm__("t32_data_e17c0");
extern unsigned char ref_tisp_simple_intp_uint16[] __asm__("tisp_simple_intp_uint16");
extern unsigned char ref_tisp_round_int64[] __asm__("tisp_round_int64");
u64 tisp_gib_interp_by_again_s(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4185c = ((u32)(unsigned long)ref_t32_data_e17c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_418e4 = ((u32)(unsigned long)ref_tisp_simple_intp_uint16 + 0x8000U) & 0xffff0000U;
    const u32 hi_41b80 = ((u32)(unsigned long)ref_tisp_round_int64 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
L_41854:
    sp = sp + -64;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    s0 = hi_4185c;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s4;
    s0 = s0 - hi_4185c + (u32)(unsigned long)ref_t32_data_e17c0;
    s4 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (60)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    v0 = s4 + s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = 1;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    s6 = *(volatile u8 *)(unsigned long)(a2 + (544));
    s7 = *(volatile u8 *)(unsigned long)(a2 + (545));
    branch = (s6 == a0); s8 = *(volatile u16 *)(unsigned long)(v1 + (0));
    if (branch) goto L_418d0;
    goto L_418b4;
L_418b4:
    branch = (s6 != 0); ;
    if (branch) goto L_418c8;
    goto L_418bc;
L_418bc:
    a0 = (u32)s7 < (u32)(2);
    branch = (a0 != 0); a0 = 1;
    if (branch) goto L_418d0;
    goto L_418c8;
L_418c8:
    if (s8 == a0) { v1 = *(volatile u16 *)(unsigned long)(v1 + (14)); goto L_41ab0; }
    goto L_418d0;
L_418d0:
    v1 = *(volatile u32 *)(unsigned long)(a2 + (4));
    if (v1 != 0) { v1 = *(volatile u16 *)(unsigned long)(a2 + (266)); goto L_41a08; }
    goto L_418dc;
L_418dc:
    s2 = a1 >> (0x10 & 31);
    s5 = a1 & 0xffff;
    s3 = hi_418e4;
    s3 = s3 - hi_418e4 + (u32)(unsigned long)ref_tisp_simple_intp_uint16;
    a2 = a2 + 156;
    a1 = s5;
    callee = s3; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_418fc;
L_418fc:
    *(volatile u16 *)(unsigned long)(s1 + (76)) = v0;
    s1 = s0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a1 = s5;
    a0 = s2;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = a2 + 178;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41924;
L_41924:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a1 = s5;
    a0 = s2;
    *(volatile u16 *)(unsigned long)(v1 + (78)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = a2 + 200;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4194c;
L_4194c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a1 = s5;
    a0 = s2;
    *(volatile u16 *)(unsigned long)(v1 + (80)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = a2 + 222;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41974;
L_41974:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a0 = s2;
    a1 = s5;
    *(volatile u16 *)(unsigned long)(v1 + (82)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = a2 + 244;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4199c;
L_4199c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    *(volatile u16 *)(unsigned long)(v1 + (84)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(v1 + (547));
    if (a0 != 0) { v0 = 1; goto L_41a50; }
    goto L_419b8;
L_419b8:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (76));
    *(volatile u16 *)(unsigned long)(v1 + (266)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (78));
    *(volatile u16 *)(unsigned long)(v1 + (268)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (80));
    *(volatile u16 *)(unsigned long)(v1 + (270)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (82));
    *(volatile u16 *)(unsigned long)(v1 + (272)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (84));
    *(volatile u16 *)(unsigned long)(v1 + (274)) = v0; goto L_41a4c;
L_41a08:
    *(volatile u16 *)(unsigned long)(s1 + (76)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (268));
    *(volatile u16 *)(unsigned long)(v1 + (78)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (270));
    *(volatile u16 *)(unsigned long)(v1 + (80)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (272));
    *(volatile u16 *)(unsigned long)(v1 + (82)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (274));
    *(volatile u16 *)(unsigned long)(v1 + (84)) = v0;
L_41a4c:
    v0 = 1;
L_41a50:
    branch = (s8 == v0); v0 = s0 + s4;
    if (branch) goto L_41af4;
    goto L_41a58;
L_41a58:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (76));
    *(volatile u16 *)(unsigned long)(v1 + (14)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (78));
    *(volatile u16 *)(unsigned long)(v1 + (16)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (80));
    *(volatile u16 *)(unsigned long)(v1 + (18)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (82));
    *(volatile u16 *)(unsigned long)(v1 + (20)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (84));
    *(volatile u16 *)(unsigned long)(v1 + (22)) = v0; goto L_41b24;
L_41ab0:
    *(volatile u16 *)(unsigned long)(s1 + (76)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (16));
    *(volatile u16 *)(unsigned long)(v1 + (78)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (18));
    *(volatile u16 *)(unsigned long)(v1 + (80)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (20));
    *(volatile u16 *)(unsigned long)(v1 + (82)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (22));
    *(volatile u16 *)(unsigned long)(v1 + (84)) = v0;
L_41af4:
    v0 = s0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = 1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (547));
    if (a1 != a0) { s0 = s0 + s4; goto L_41b28; }
    goto L_41b10;
L_41b10:
    a0 = 2;
    if (s6 == a0) { a0 = *(volatile u32 *)(unsigned long)(v0 + (16)); goto L_41bdc; }
    goto L_41b1c;
L_41b1c:
    branch = (s6 == 0); ;
    if (branch) goto L_41bd0;
    goto L_41b24;
L_41b24:
    s0 = s0 + s4;
L_41b28:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    s0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u16 *)(unsigned long)(s0 + (78));
    a0 = *(volatile u16 *)(unsigned long)(s0 + (76));
    v0 = (u32)a0 < (u32)(v1);
    if (v0 != 0) a0 = v1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (80));
    v0 = (u32)v1 < (u32)(a0);
    if (v0 == 0) a0 = v1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (82));
    v0 = (u32)v1 < (u32)(a0);
    if (v0 == 0) a0 = v1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (84));
    v0 = (u32)v1 < (u32)(a0);
    if (v0 == 0) a0 = v1;
    v0 = a0 >> (0xb & 31);
    branch = (v0 != 0); v0 = 8191;
    if (branch) goto L_41b98;
    goto L_41b70;
L_41b70:
    v0 = 4096;
    a0 = v0 - a0;
    v0 = 0x200U << 16;
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    v0 = hi_41b80;
    a2 = 1;
    a1 = 0;
    v0 = v0 - hi_41b80 + (u32)(unsigned long)ref_tisp_round_int64;
    callee = v0; a0 = lo;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_41b98;
L_41b98:
    *(volatile u16 *)(unsigned long)(s0 + (86)) = v0;
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
L_41bd0:
    if (s7 != a0) { s0 = s0 + s4; goto L_41b28; }
    goto L_41bd8;
L_41bd8:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
L_41bdc:
    a0 = *(volatile u16 *)(unsigned long)(a0 + (14));
    *(volatile u16 *)(unsigned long)(v1 + (266)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (16));
    *(volatile u16 *)(unsigned long)(v1 + (268)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (18));
    *(volatile u16 *)(unsigned long)(v1 + (270)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (20));
    *(volatile u16 *)(unsigned long)(v1 + (272)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (22));
    *(volatile u16 *)(unsigned long)(v1 + (274)) = v0; goto L_41b24;
}
