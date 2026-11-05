/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dc074[] __asm__("t32_data_dc074");
extern unsigned char ref_t32_data_bfb8c[] __asm__("t32_data_bfb8c");
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_c9b9c[] __asm__("t32_data_c9b9c");
extern unsigned char ref_t32_data_c9bd8[] __asm__("t32_data_c9bd8");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
u64 tisp_mdns_get_mem_size(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_7303c = ((u32)(unsigned long)ref_t32_data_dc074 + 0x8000U) & 0xffff0000U;
    const u32 hi_730c8 = ((u32)(unsigned long)ref_t32_data_bfb8c + 0x8000U) & 0xffff0000U;
    const u32 hi_730d0 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_730cc = ((u32)(unsigned long)ref_t32_data_c9b9c + 0x8000U) & 0xffff0000U;
    const u32 hi_730e8 = ((u32)(unsigned long)ref_t32_data_c9bd8 + 0x8000U) & 0xffff0000U;
    const u32 hi_730ec = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
    stack[10] = arg4;
L_73030:
    v0 = 76;
    a0 = a0 & 0xff;
    v1 = a0 * v0;
    t1 = hi_7303c;
    sp = sp + -24;
    t1 = t1 - hi_7303c + (u32)(unsigned long)ref_t32_data_dc074;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    a1 = a1 & 0xffff;
    t0 = a1 + 31;
    a2 = a2 & 0xffff;
    a3 = a3 & 0xff;
    t2 = *(volatile u8 *)(unsigned long)(sp + (40));
    v0 = v1 + t1;
    t3 = *(volatile u16 *)(unsigned long)(v0 + (8));
    v0 = (u32)t3 < (u32)(1001);
    branch = (v0 == 0); t0 = (s32)t0 >> (0x5 & 31);
    if (branch) goto L_730bc;
    goto L_73074;
L_73074:
    v0 = a1 + 15;
    v0 = (s32)v0 >> (0x4 & 31);
    v0 = v0 << (0x4 & 31);
    v0 = v0 * a2;
    t4 = t0 << (0x5 & 31);
    t4 = t4 * a2;
    t3 = v0 >> (0x5 & 31);
    v0 = v0 + 1023;
    v1 = t3 + v0;
    v0 = v1 >> (0xa & 31);
    t5 = t4 >> (0x1 & 31);
    v1 = t5 + 1023;
    t4 = t4 >> (0x7 & 31);
    v1 = t4 + v1;
    v1 = v1 >> (0xa & 31);
    v1 = v0 + v1;
    v1 = v1 << (0xa & 31); goto L_7313c;
L_730bc:
    v0 = (u32)t3 < (u32)(2001);
    branch = (v0 != 0); v1 = 0x5U << 16;
    if (branch) goto L_7310c;
    goto L_730c8;
L_730c8:
    a1 = hi_730c8;
    a0 = hi_730cc;
    v0 = hi_730d0;
    a2 = 6554;
    a1 = a1 - hi_730c8 + (u32)(unsigned long)ref_t32_data_bfb8c;
    v0 = v0 - hi_730d0 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_730cc + (u32)(unsigned long)ref_t32_data_c9b9c;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_730e8;
L_730e8:
    a1 = hi_730e8;
    v0 = hi_730ec;
    a1 = a1 - hi_730e8 + (u32)(unsigned long)ref_t32_data_c9bd8;
    v0 = v0 - hi_730ec + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_73100;
L_73100:
    v0 = 0x8003U << 16;
    v0 = v0 + 8194; goto L_731c0;
L_7310c:
    v1 = v1 | 0xdc00;
    v0 = a2 * t0;
    if (v1 == 0x80000000U && t3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t3) { lo = (s32)v1 / (s32)t3; hi = (s32)v1 % (s32)t3; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    v1 = v0 * v1;
    v1 = v1 + 63;
    v1 = v1 >> (0x6 & 31);
    v1 = v1 << (0x3 & 31);
    v1 = v1 + 255;
    v1 = v1 >> (0x8 & 31);
    v1 = v1 + 2;
    v1 = v1 << (0x8 & 31);
L_7313c:
    a1 = a1 + 7;
    a1 = (s32)a1 >> (0x3 & 31);
    v0 = 12;
    a1 = a1 + 11;
    if (a1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a1 / (s32)v0; hi = (s32)a1 % (s32)v0; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    v0 = lo;
    v0 = v0 << (0x3 & 31);
    v0 = v0 * a2;
    v0 = v0 >> (0x3 & 31);
    v0 = v0 + 1023;
    v0 = v0 >> (0xa & 31);
    v0 = v0 << (0xa & 31);
    v1 = v0 + v1;
    v0 = 1;
    branch = (a3 == v0); v0 = t0 << (0x4 & 31);
    if (branch) goto L_73194;
    goto L_7317c;
L_7317c:
    v0 = v0 * a2;
    v0 = v0 >> (0x1 & 31);
    v0 = v0 + 1023;
    v0 = v0 >> (0xa & 31);
    v0 = v0 << (0xa & 31);
    v1 = v1 + v0;
L_73194:
    a1 = v1 & 0xfff;
    v0 = 4096;
    v0 = v0 - a1;
    a1 = v0 & 0xffff;
    v0 = t2 << (0x14 & 31);
    v0 = v0 + v1;
    v1 = 76;
    v0 = a1 + v0;
    a1 = a0 * v1;
    a0 = a1 + t1;
    *(volatile u32 *)(unsigned long)(a0 + (32)) = v0;
L_731c0:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
