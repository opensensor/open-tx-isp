/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_d9698[] __asm__("t32_data_d9698");
extern unsigned char ref___wake_up[] __asm__("__wake_up");
extern unsigned char ref_t32_data_d9694[] __asm__("t32_data_d9694");
extern unsigned char ref_t32_data_cf134[] __asm__("t32_data_cf134");
extern unsigned char ref_t32_data_d9690[] __asm__("t32_data_d9690");
extern unsigned char ref_t32_data_cf12c[] __asm__("t32_data_cf12c");
u64 isp_frame_done_wakeup(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_c368 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_c388 = ((u32)(unsigned long)ref_t32_data_d9698 + 0x8000U) & 0xffff0000U;
    const u32 hi_c3b8 = (((u32)(unsigned long)ref___wake_up + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_c3c4 = ((u32)(unsigned long)ref_t32_data_d9694 + 0x8000U) & 0xffff0000U;
    const u32 hi_c3cc = ((u32)(unsigned long)ref_t32_data_cf134 + 0x8000U) & 0xffff0000U;
    const u32 hi_c3e4 = ((u32)(unsigned long)ref_t32_data_d9690 + 0x8000U) & 0xffff0000U;
    const u32 hi_c3ec = ((u32)(unsigned long)ref_t32_data_cf12c + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_c364:
    sp = sp + -32;
    v0 = hi_c368;
    a1 = a0;
    a2 = 8;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    v0 = v0 - hi_c368 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_c384;
L_c384:
    a1 = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = hi_c388;
    v0 = v0 - hi_c388 + (u32)(unsigned long)ref_t32_data_d9698;
    v1 = a1 << (0x3 & 31);
    v0 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = 1;
    a2 = v1 + 1;
    v1 = (u32)a2 < (u32)(v1);
    v1 = v1 + a3;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a2;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
    v0 = hi_c3b8;
    branch = (a1 != 0); v0 = v0 - hi_c3b8 + ((u32)(unsigned long)ref___wake_up + (0));
    if (branch) goto L_c3e4;
    goto L_c3c4;
L_c3c4:
    v1 = hi_c3c4;
    *(volatile u32 *)(unsigned long)(v1 - hi_c3c4 + (u32)(unsigned long)ref_t32_data_d9694) = a0;
    a0 = hi_c3cc;
    a3 = 0;
    a2 = 1;
    a1 = 3;
    a0 = a0 - hi_c3cc + (u32)(unsigned long)ref_t32_data_cf134; goto L_c400;
L_c3e4:
    v1 = hi_c3e4;
    *(volatile u32 *)(unsigned long)(v1 - hi_c3e4 + (u32)(unsigned long)ref_t32_data_d9690) = a0;
    a0 = hi_c3ec;
    a3 = 0;
    a2 = 1;
    a1 = 3;
    a0 = a0 - hi_c3ec + (u32)(unsigned long)ref_t32_data_cf12c;
L_c400:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_c408;
L_c408:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
