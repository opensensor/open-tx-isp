/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d80f8[] __asm__("t32_data_d80f8");
extern unsigned char ref_t32_data_d80ec[] __asm__("t32_data_d80ec");
extern unsigned char ref_t32_data_d80e0[] __asm__("t32_data_d80e0");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_bfee0[] __asm__("t32_data_bfee0");
extern unsigned char ref_t32_data_bfee4[] __asm__("t32_data_bfee4");
u64 tisp_csccr_para_refresh_by_mode(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_8efc8 = ((u32)(unsigned long)ref_t32_data_d80f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_8eff4 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_8f008 = ((u32)(unsigned long)ref_t32_data_bfee0 + 0x8000U) & 0xffff0000U;
    const u32 hi_8f01c = ((u32)(unsigned long)ref_t32_data_bfee4 + 0x8000U) & 0xffff0000U;
    const u32 hi_8efb4 = ((u32)(unsigned long)ref_t32_data_d80f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_8efbc = ((u32)(unsigned long)ref_t32_data_d80f8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_8ef98:
    v0 = a0;
    a1 = a1 & 0xff;
    a0 = a2;
    a2 = 1;
    branch = (a1 != a2); v1 = (u32)v0 < (u32)(4);
    if (branch) goto L_8f004;
    goto L_8efb0;
L_8efb0:
    if (v0 == a1) { a1 = hi_8efb4; goto L_8efe0; }
    goto L_8efb8;
L_8efb8:
    if (v0 == 0) { a1 = hi_8efbc; goto L_8efd4; }
    goto L_8efc0;
L_8efc0:
    v1 = 2;
    branch = (v0 == v1); a1 = hi_8efc8;
    if (branch) goto L_8efec;
    goto L_8efcc;
L_8efcc:
    ;
    return ((u64)v1 << 32) | v0;
L_8efd4:
    a2 = 12;
    a1 = a1 - hi_8efc8 + (u32)(unsigned long)ref_t32_data_d80f8; goto L_8eff4;
L_8efe0:
    a2 = 12;
    a1 = a1 - hi_8efc8 + (u32)(unsigned long)ref_t32_data_d80ec; goto L_8eff4;
L_8efec:
    a2 = 12;
    a1 = a1 - hi_8efc8 + (u32)(unsigned long)ref_t32_data_d80e0;
L_8eff4:
    t9 = hi_8eff4;
    t9 = t9 - hi_8eff4 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = t9; ;
    switch (callee) { case 0x8ef98: goto L_8ef98; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_8f004:
    branch = (v1 == 0); v1 = hi_8f008;
    if (branch) goto L_8efcc;
    goto L_8f00c;
L_8f00c:
    v1 = v1 - hi_8f008 + (u32)(unsigned long)ref_t32_data_bfee0;
    v1 = v0 + v1;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    branch = (v1 != a2); v1 = hi_8f01c;
    if (branch) goto L_8efcc;
    goto L_8f020;
L_8f020:
    v1 = v1 - hi_8f01c + (u32)(unsigned long)ref_t32_data_bfee4;
    v0 = v0 << (0x2 & 31);
    v0 = v0 + v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (4)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (4));
    *(volatile u8 *)(unsigned long)(a0 + (5)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (5));
    *(volatile u8 *)(unsigned long)(a0 + (6)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (6));
    *(volatile u8 *)(unsigned long)(a0 + (7)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (7));
    *(volatile u8 *)(unsigned long)(a0 + (8)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (8));
    *(volatile u8 *)(unsigned long)(a0 + (9)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (9));
    *(volatile u8 *)(unsigned long)(a0 + (10)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (10));
    *(volatile u8 *)(unsigned long)(a0 + (11)) = v1;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (11));
    *(volatile u8 *)(unsigned long)(a0 + (12)) = v0;
    ;
    return ((u64)v1 << 32) | v0;
}
