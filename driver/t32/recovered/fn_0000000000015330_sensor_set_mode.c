/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_da760[] __asm__("t32_data_da760");
extern unsigned char ref_t32_data_c6a9c[] __asm__("t32_data_c6a9c");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
u64 sensor_set_mode(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_1533c = ((u32)(unsigned long)ref_t32_data_da760 + 0x8000U) & 0xffff0000U;
    const u32 hi_15364 = ((u32)(unsigned long)ref_t32_data_c6a9c + 0x8000U) & 0xffff0000U;
    const u32 hi_15368 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_15330:
    sp = sp + -48;
    v0 = 1;
    *(volatile u8 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_1533c;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s3;
    s3 = a0 & 0xff;
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_1533c + (u32)(unsigned long)ref_t32_data_da760);
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s1;
    branch = (a0 != 0); *(volatile u32 *)(unsigned long)(sp + (28)) = s0;
    if (branch) goto L_15384;
    goto L_15360;
L_15360:
    a2 = *(volatile u8 *)(unsigned long)(sp + (16));
L_15364:
    a1 = hi_15364;
L_15368:
    v0 = hi_15368;
    a1 = a1 - hi_15364 + (u32)(unsigned long)ref_t32_data_c6a9c;
    v0 = v0 - hi_15368 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1537c;
L_1537c:
    ra = *(volatile u32 *)(unsigned long)(sp + (44)); goto L_15414;
L_15380:
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
L_15384:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (152));
    branch = (v1 == 0); s2 = 104;
    if (branch) goto L_15360;
    goto L_15390;
L_15390:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (8));
    s0 = a1;
    a1 = v0 * s2;
    a2 = sp + 16;
    s2 = a1 + a0;
    a1 = 0x200U << 16;
    a1 = a1 + 13;
    callee = v1; s1 = *(volatile u32 *)(unsigned long)(s2 + (376));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_153b4;
L_153b4:
    branch = (v0 != 0); a2 = *(volatile u8 *)(unsigned long)(sp + (16));
    if (branch) goto L_15364;
    goto L_153bc;
L_153bc:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (324));
    *(volatile u16 *)(unsigned long)(s0 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s2 + (328));
    *(volatile u16 *)(unsigned long)(s0 + (6)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s1 + (276));
    *(volatile u16 *)(unsigned long)(s0 + (0)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s1 + (278));
    *(volatile u16 *)(unsigned long)(s0 + (2)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (220));
    *(volatile u32 *)(unsigned long)(s0 + (68)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (224));
    *(volatile u32 *)(unsigned long)(s0 + (72)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (236));
    *(volatile u32 *)(unsigned long)(s0 + (88)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (240));
    *(volatile u32 *)(unsigned long)(s0 + (92)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (224));
    *(volatile u32 *)(unsigned long)(s0 + (76)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (224));
    *(volatile u8 *)(unsigned long)(s0 + (122)) = s3;
    *(volatile u32 *)(unsigned long)(s0 + (80)) = v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
L_15414:
    s3 = *(volatile u32 *)(unsigned long)(sp + (40));
    s2 = *(volatile u32 *)(unsigned long)(sp + (36));
    s1 = *(volatile u32 *)(unsigned long)(sp + (32));
    s0 = *(volatile u32 *)(unsigned long)(sp + (28));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
