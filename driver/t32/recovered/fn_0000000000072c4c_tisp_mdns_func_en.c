/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e22c8[] __asm__("t32_data_e22c8");
extern unsigned char ref_t32_data_d03a0[] __asm__("t32_data_d03a0");
extern unsigned char ref_tisp_reg_write[] __asm__("tisp_reg_write");
extern unsigned char ref_t32_data_dc074[] __asm__("t32_data_dc074");
extern unsigned char ref_tisp_mdns_reg_trig[] __asm__("tisp_mdns_reg_trig");
u64 tisp_mdns_func_en(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_72c54 = ((u32)(unsigned long)ref_t32_data_e22c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_72c7c = ((u32)(unsigned long)ref_t32_data_d03a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_72c98 = ((u32)(unsigned long)ref_tisp_reg_write + 0x8000U) & 0xffff0000U;
    const u32 hi_72cb0 = ((u32)(unsigned long)ref_t32_data_dc074 + 0x8000U) & 0xffff0000U;
    const u32 hi_72e68 = ((u32)(unsigned long)ref_tisp_mdns_reg_trig + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
L_72c4c:
    sp = sp + -40;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    s4 = hi_72c54;
    v0 = a0 << (0x2 & 31);
    s4 = s4 - hi_72c54 + (u32)(unsigned long)ref_t32_data_e22c8;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    s4 = v0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(s4 + (0));
    s3 = hi_72c7c;
    a1 = *(volatile u8 *)(unsigned long)(s3 - hi_72c7c + (u32)(unsigned long)ref_t32_data_d03a0);
    s2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 977;
    v0 = 0xd01c;
    a2 = *(volatile u8 *)(unsigned long)(s2 + (314));
    if (a1 != 0) v0 = v1;
    s1 = hi_72c98;
    a1 = v0;
    s1 = s1 - hi_72c98 + (u32)(unsigned long)ref_tisp_reg_write;
    callee = s1; s0 = a0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_72cac;
L_72cac:
    v0 = *(volatile u32 *)(unsigned long)(s4 + (0));
    v1 = hi_72cb0;
    a2 = 1;
    a3 = *(volatile u32 *)(unsigned long)(v0 + (44));
    v1 = v1 - hi_72cb0 + (u32)(unsigned long)ref_t32_data_dc074;
    a0 = *(volatile u8 *)(unsigned long)(s2 + (274));
    v0 = *(volatile u8 *)(unsigned long)(s2 + (275));
    t3 = *(volatile u8 *)(unsigned long)(s2 + (276));
    t2 = *(volatile u8 *)(unsigned long)(s2 + (277));
    t1 = *(volatile u8 *)(unsigned long)(s2 + (279));
    branch = (a3 != a2); a1 = 76;
    if (branch) goto L_72d84;
    goto L_72cdc;
L_72cdc:
    a2 = s0 * a1;
    v1 = a2 + v1;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (11));
    branch = (v1 == a3); a3 = 0x3000U << 16;
    if (branch) goto L_72d4c;
    goto L_72cf0;
L_72cf0:
    v0 = v0 & 0x1;
    a0 = a0 & 0x1;
    a0 = a0 | a3;
    a3 = v0 << (0x4 & 31);
    v0 = t3 & 0x1;
    a3 = a0 | a3;
    v0 = v0 << (0x8 & 31);
    a0 = a3 | v0;
    a3 = t2 & 0x1;
    a3 = a3 << (0xc & 31);
    v0 = a0 | a3;
    a3 = *(volatile u8 *)(unsigned long)(s2 + (278));
    t0 = *(volatile u8 *)(unsigned long)(s3 - hi_72c7c + (u32)(unsigned long)ref_t32_data_d03a0);
    a2 = t1 & 0xf;
    a3 = a3 & 0x3;
    a3 = a3 << (0x10 & 31);
    a3 = v0 | a3;
    a2 = a2 << (0x14 & 31);
    v0 = 0xd024;
    a1 = 979;
    a2 = a3 | a2;
    if (t0 == 0) a1 = v0; goto L_72e44;
L_72d4c:
    a3 = v0 & 0x1;
    t0 = a3 << (0x4 & 31);
    a0 = a0 & 0x1;
    a3 = 0x3000U << 16;
    a0 = a0 | a3;
    v0 = t3 & 0x1;
    v0 = v0 << (0x8 & 31);
    a3 = t0 | a0;
    a0 = a3 | v0;
    v0 = t2 & 0x1;
    v0 = v0 << (0xc & 31);
    a1 = *(volatile u8 *)(unsigned long)(s3 - hi_72c7c + (u32)(unsigned long)ref_t32_data_d03a0);
    v0 = a0 | v0; goto L_72e28;
L_72d84:
    a3 = s0 * a1;
    v1 = a3 + v1;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (11));
    branch = (v1 == a2); a3 = v0 & 0x1;
    if (branch) goto L_72df4;
    goto L_72d98;
L_72d98:
    t0 = a3 << (0x4 & 31);
    a0 = a0 & 0x1;
    a3 = 0x2000U << 16;
    a0 = a0 | a3;
    v0 = t3 & 0x1;
    v1 = v0 << (0x8 & 31);
    a3 = t0 | a0;
    v0 = t2 & 0x1;
    v0 = v0 << (0xc & 31);
    a0 = a3 | v1;
    v1 = a0 | v0;
    v0 = *(volatile u8 *)(unsigned long)(s2 + (278));
    t4 = *(volatile u8 *)(unsigned long)(s3 - hi_72c7c + (u32)(unsigned long)ref_t32_data_d03a0);
    a2 = t1 & 0xf;
    v0 = v0 & 0x3;
    v0 = v0 << (0x10 & 31);
    v0 = v1 | v0;
    a2 = a2 << (0x14 & 31);
    a2 = v0 | a2;
    a1 = 979;
    v0 = 0xd024;
    if (t4 == 0) a1 = v0; goto L_72e44;
L_72df4:
    v0 = v0 & 0x1;
    v1 = 0x2000U << 16;
    a0 = a0 & 0x1;
    a3 = v0 << (0x4 & 31);
    a0 = a0 | v1;
    v0 = t3 & 0x1;
    v0 = v0 << (0x8 & 31);
    a0 = a3 | a0;
    v1 = a0 | v0;
    a1 = *(volatile u8 *)(unsigned long)(s3 - hi_72c7c + (u32)(unsigned long)ref_t32_data_d03a0);
    v0 = t2 & 0x1;
    v0 = v0 << (0xc & 31);
    v0 = v1 | v0;
L_72e28:
    a2 = t1 & 0xf;
    a2 = a2 << (0x14 & 31);
    a2 = v0 | a2;
    v1 = 979;
    v0 = 0xd024;
    if (a1 != 0) v0 = v1;
    a1 = v0;
L_72e44:
    callee = s1; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_72e4c;
L_72e4c:
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    a0 = s0;
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    t9 = hi_72e68;
    t9 = t9 - hi_72e68 + (u32)(unsigned long)ref_tisp_mdns_reg_trig;
    callee = t9; sp = sp + 40;
    switch (callee) { case 0x72c4c: goto L_72c4c; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
}
