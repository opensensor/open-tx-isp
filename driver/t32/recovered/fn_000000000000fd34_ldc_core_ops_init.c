/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_ldc_video_s_stream[] __asm__("ldc_video_s_stream");
u64 ldc_core_ops_init(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_fda4 = ((u32)(unsigned long)ref_ldc_video_s_stream + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_fd34:
    branch = (a0 == 0); a3 = -22;
    if (branch) goto L_fdf0;
    goto L_fd3c;
L_fd3c:
    a2 = (u32)a0 < (u32)(-4095);
    branch = (a2 == 0); ;
    if (branch) goto L_fdf0;
    goto L_fd48;
L_fd48:
    a2 = *(volatile u32 *)(unsigned long)(a0 + (280));
    branch = (a2 == 0); ;
    if (branch) goto L_fdf0;
    goto L_fd54;
L_fd54:
    v0 = (u32)a2 < (u32)(-4095);
    branch = (v0 == 0); ;
    if (branch) goto L_fdf0;
    goto L_fd60;
L_fd60:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    a3 = 1;
    v0 = v0 << (0x2 & 31);
    v0 = a2 + v0;
    t1 = *(volatile u32 *)(unsigned long)(v0 + (288));
    branch = (t1 == a3); a3 = 0;
    if (branch) goto L_fdf0;
    goto L_fd7c;
L_fd7c:
    a3 = *(volatile u32 *)(unsigned long)(a1 + (0));
    if (a3 == 0) { sp = sp + -24; goto L_fd94; }
    goto L_fd88;
L_fd88:
    v1 = 3;
    *(volatile u32 *)(unsigned long)(v0 + (288)) = v1; goto L_fdec;
L_fd94:
    v0 = 4;
    t0 = a1;
    branch = (t1 != v0); *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    if (branch) goto L_fdb4;
    goto L_fda4;
L_fda4:
    v0 = hi_fda4;
    v0 = v0 - hi_fda4 + (u32)(unsigned long)ref_ldc_video_s_stream;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_fdb4;
L_fdb4:
    v0 = *(volatile u32 *)(unsigned long)(t0 + (4));
    v0 = v0 << (0x2 & 31);
    a2 = a2 + v0;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (288));
    v0 = 3;
    branch = (v1 == v0); v0 = 2;
    if (branch) goto L_fdd8;
    goto L_fdd0;
L_fdd0:
    a3 = 0; goto L_fddc;
L_fdd8:
    *(volatile u32 *)(unsigned long)(a2 + (288)) = v0;
L_fddc:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = a3;
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
L_fdec:
    a3 = 0;
L_fdf0:
    v0 = a3;
    return ((u64)v1 << 32) | v0;
}
