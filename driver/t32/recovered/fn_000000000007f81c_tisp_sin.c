/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_bfc40[] __asm__("t32_data_bfc40");
extern unsigned char ref_memcpy[] __asm__("memcpy");
u64 tisp_sin(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[202] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_7f834 = ((u32)(unsigned long)ref_t32_data_bfc40 + 0x8000U) & 0xffff0000U;
    const u32 hi_7f828 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[138];
L_7f81c:
    a0 = a0 << (0x3 & 31);
    if (a1) { lo = a0 / a1; hi = a0 % a1; } else { lo = ~0U; hi = a0; }
    sp = sp + -552;
    v0 = hi_7f828;
    *(volatile u32 *)(unsigned long)(sp + (536)) = s0;
    s0 = a1;
    a1 = hi_7f834;
    *(volatile u32 *)(unsigned long)(sp + (544)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (540)) = s1;
    a1 = a1 - hi_7f834 + (u32)(unsigned long)ref_t32_data_bfc40;
    a0 = sp + 16;
    *(volatile u32 *)(unsigned long)(sp + (548)) = ra;
    s1 = a2;
    v0 = v0 - hi_7f828 + ((u32)(unsigned long)ref_memcpy + (0));
    a2 = 514;
    s0 = s0 + 1;
    callee = v0; s2 = lo;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7f864;
L_7f864:
    a0 = 1024;
    t1 = 0;
    t0 = 0;
    a1 = 0;
    t2 = 1024;
L_7f878:
    v0 = (u32)a1 < (u32)(s0);
    branch = (v0 == 0); a3 = a1 * s2;
    if (branch) goto L_7f8f4;
    goto L_7f884;
L_7f884:
    v0 = (s32)a3 < (s32)(a0);
    branch = (v0 == 0); a2 = t0 + 1;
    if (branch) goto L_7f8e4;
    goto L_7f890;
L_7f890:
    a2 = a2 << (0x1 & 31);
    t3 = sp + 16;
    a2 = t3 + a2;
    a2 = *(volatile s16 *)(unsigned long)(a2 + (0));
    a3 = a3 - t1;
    v1 = sp + 16;
    product = (s64)(s32)a2 * (s32)a3; lo = product; hi = product >> 32;
    v0 = t0 << (0x1 & 31);
    v0 = v1 + v0;
    v1 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = t2 - a3;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)v0); lo = product; hi = product >> 32;
    v1 = a1 << (0x1 & 31);
    v1 = s1 + v1;
    a1 = a1 + 1;
    v0 = lo;
    a2 = (s32)v0 >> (0xa & 31);
    v0 = (v0 >> 0x9) & ((1U << 0x1) - 1);
    v0 = a2 + v0;
    *(volatile u16 *)(unsigned long)(v1 + (0)) = v0; goto L_7f878;
L_7f8e4:
    t1 = a0;
    t0 = a2;
    a0 = a0 + 1024; goto L_7f878;
L_7f8f4:
    ra = *(volatile u32 *)(unsigned long)(sp + (548));
    s2 = *(volatile u32 *)(unsigned long)(sp + (544));
    s1 = *(volatile u32 *)(unsigned long)(sp + (540));
    s0 = *(volatile u32 *)(unsigned long)(sp + (536));
    sp = sp + 552;
    return ((u64)v1 << 32) | v0;
}
