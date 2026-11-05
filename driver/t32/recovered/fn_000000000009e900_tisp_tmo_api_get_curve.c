/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c04c8[] __asm__("t32_data_c04c8");
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_memcpy[] __asm__("memcpy");
u64 tisp_tmo_api_get_curve(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_9e914 = ((u32)(unsigned long)ref_t32_data_c04c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_9e928 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9e934 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_9e900:
    a1 = a1 & 0xff;
    v1 = (u32)a1 < (u32)(10);
    a3 = a2;
    branch = (v1 == 0); a0 = a0 & 0xff;
    if (branch) goto L_9e9ec;
    goto L_9e914;
L_9e914:
    v1 = hi_9e914;
    v1 = v1 - hi_9e914 + (u32)(unsigned long)ref_t32_data_c04c8;
    a1 = a1 << (0x2 & 31);
    a1 = v1 + a1;
    a1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v1 = hi_9e928;
    a0 = a0 << (0x2 & 31);
    v0 = v1 - hi_9e928 + (u32)(unsigned long)ref_t32_data_e35e0;
    t9 = hi_9e934;
    v0 = v0 + a0;
    t9 = t9 - hi_9e934 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = a1; v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    switch (callee) { case 0x9e900: goto L_9e900; case 0x9e948: goto L_9e948; case 0x9e958: goto L_9e958; case 0x9e968: goto L_9e968; case 0x9e978: goto L_9e978; case 0x9e988: goto L_9e988; case 0x9e998: goto L_9e998; case 0x9e9a8: goto L_9e9a8; case 0x9e9b8: goto L_9e9b8; case 0x9e9c8: goto L_9e9c8; case 0x9e9d8: goto L_9e9d8; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_9e948:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 7398; goto L_9e9e4;
L_9e958:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 7800; goto L_9e9e4;
L_9e968:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 4182; goto L_9e9e4;
L_9e978:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 4584; goto L_9e9e4;
L_9e988:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 4986; goto L_9e9e4;
L_9e998:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 5388; goto L_9e9e4;
L_9e9a8:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 5790; goto L_9e9e4;
L_9e9b8:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 6192; goto L_9e9e4;
L_9e9c8:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 6594; goto L_9e9e4;
L_9e9d8:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 402;
    a1 = a1 + 6996;
L_9e9e4:
    callee = t9; a0 = a3;
    switch (callee) { case 0x9e900: goto L_9e900; case 0x9e948: goto L_9e948; case 0x9e958: goto L_9e958; case 0x9e968: goto L_9e968; case 0x9e978: goto L_9e978; case 0x9e988: goto L_9e988; case 0x9e998: goto L_9e998; case 0x9e9a8: goto L_9e9a8; case 0x9e9b8: goto L_9e9b8; case 0x9e9c8: goto L_9e9c8; case 0x9e9d8: goto L_9e9d8; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_9e9ec:
    ;
    return ((u64)v1 << 32) | v0;
}
