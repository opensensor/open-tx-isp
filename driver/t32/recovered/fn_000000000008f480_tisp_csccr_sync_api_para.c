/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e3120[] __asm__("t32_data_e3120");
u64 tisp_csccr_sync_api_para(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_8f480 = ((u32)(unsigned long)ref_t32_data_e3120 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_8f480:
    v1 = hi_8f480;
    a0 = a0 & 0xff;
    v0 = v1 - hi_8f480 + (u32)(unsigned long)ref_t32_data_e3120;
    a0 = a0 << (0x2 & 31);
    v0 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 1;
    branch = (a1 != a2); v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    if (branch) goto L_8f540;
    goto L_8f4a4;
L_8f4a4:
    a0 = *(volatile u8 *)(unsigned long)(v1 + (15));
    branch = (a0 != a1); ;
    if (branch) goto L_8f5d8;
    goto L_8f4b0;
L_8f4b0:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (4));
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (5));
    *(volatile u8 *)(unsigned long)(v1 + (4)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (6));
    *(volatile u8 *)(unsigned long)(v1 + (5)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (7));
    *(volatile u8 *)(unsigned long)(v1 + (6)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (8));
    *(volatile u8 *)(unsigned long)(v1 + (7)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (9));
    *(volatile u8 *)(unsigned long)(v1 + (8)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (10));
    *(volatile u8 *)(unsigned long)(v1 + (9)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (11));
    *(volatile u8 *)(unsigned long)(v1 + (10)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (12));
    *(volatile u8 *)(unsigned long)(v1 + (11)) = v0; goto L_8f5d8;
L_8f540:
    a0 = *(volatile u8 *)(unsigned long)(v1 + (16));
    branch = (a0 != a2); ;
    if (branch) goto L_8f5d8;
    goto L_8f54c;
L_8f54c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (4)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (4));
    *(volatile u8 *)(unsigned long)(v1 + (5)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (5));
    *(volatile u8 *)(unsigned long)(v1 + (6)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (6));
    *(volatile u8 *)(unsigned long)(v1 + (7)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (7));
    *(volatile u8 *)(unsigned long)(v1 + (8)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (8));
    *(volatile u8 *)(unsigned long)(v1 + (9)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (9));
    *(volatile u8 *)(unsigned long)(v1 + (10)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (10));
    *(volatile u8 *)(unsigned long)(v1 + (11)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (11));
    *(volatile u8 *)(unsigned long)(v1 + (12)) = v0;
L_8f5d8:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
