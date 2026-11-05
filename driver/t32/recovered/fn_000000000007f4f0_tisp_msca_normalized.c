/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_bfc10[] __asm__("t32_data_bfc10");
extern unsigned char ref_t32_data_bfc28[] __asm__("t32_data_bfc28");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_c9eac[] __asm__("t32_data_c9eac");
extern unsigned char ref_printk[] __asm__("printk");
u64 tisp_msca_normalized(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[128] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_7f4fc = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_7f4f4 = ((u32)(unsigned long)ref_t32_data_bfc10 + 0x8000U) & 0xffff0000U;
    const u32 hi_7f53c = ((u32)(unsigned long)ref_t32_data_bfc28 + 0x8000U) & 0xffff0000U;
    const u32 hi_7f558 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_7f738 = ((u32)(unsigned long)ref_t32_data_c9eac + 0x8000U) & 0xffff0000U;
    const u32 hi_7f74c = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[64];
L_7f4f0:
    sp = sp + -256;
    a1 = hi_7f4f4;
    *(volatile u32 *)(unsigned long)(sp + (228)) = s2;
    s2 = hi_7f4fc;
    *(volatile u32 *)(unsigned long)(sp + (252)) = ra;
    s2 = s2 - hi_7f4fc + ((u32)(unsigned long)ref_memcpy + (0));
    *(volatile u32 *)(unsigned long)(sp + (224)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (220)) = s0;
    s1 = a0;
    a1 = a1 - hi_7f4f4 + (u32)(unsigned long)ref_t32_data_bfc10;
    a0 = sp + 140;
    *(volatile u32 *)(unsigned long)(sp + (248)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (244)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (240)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (236)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (232)) = s3;
    s0 = a2;
    callee = s2; a2 = 24;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7f53c;
L_7f53c:
    a1 = hi_7f53c;
    a2 = 24;
    a1 = a1 - hi_7f53c + (u32)(unsigned long)ref_t32_data_bfc28;
    callee = s2; a0 = sp + 116;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7f550;
L_7f550:
    s2 = 6;
    s2 = s1 * s2;
    v0 = hi_7f558;
    a0 = sp + 16;
    a2 = 100;
    v0 = v0 - hi_7f558 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7f570;
L_7f570:
    v0 = -s1;
    v0 = v0 << (0x1 & 31);
    v1 = 0;
    a0 = 24;
    s2 = s2 >> (0x1 & 31);
L_7f584:
    a1 = sp + 164;
    a1 = a1 + v1;
    v1 = v1 + 4;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v0;
    branch = (v1 != a0); v0 = v0 + s1;
    if (branch) goto L_7f584;
    goto L_7f59c;
L_7f59c:
    a0 = 0;
    a1 = 24;
    a2 = 2;
L_7f5a8:
    branch = (a0 == s1); v1 = 0;
    if (branch) goto L_7f738;
    goto L_7f5b0;
L_7f5b0:
    t0 = 0;
L_7f5b4:
    v0 = sp + 164;
    v0 = v0 + v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = v1 + 4;
    v0 = v0 - a0;
    a3 = (s32)v0 >> (0x1f & 31);
    v0 = a3 ^ v0;
    v0 = v0 - a3;
    v0 = v0 << (0x1 & 31);
    v0 = s0 + v0;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    branch = (v1 != a1); t0 = t0 + v0;
    if (branch) goto L_7f5b4;
    goto L_7f5e8;
L_7f5e8:
    if (t0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)t0 / (s32)a2; hi = (s32)t0 % (s32)a2; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t2 = sp + 188;
    t3 = 0;
    t1 = 0;
    a3 = t2;
    t4 = lo;
L_7f600:
    v0 = sp + 164;
    v0 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 - a0;
    v1 = (s32)v0 >> (0x1f & 31);
    v0 = v1 ^ v0;
    v0 = v0 - v1;
    v1 = v0 << (0x1 & 31);
    v1 = s0 + v1;
    t5 = *(volatile s16 *)(unsigned long)(v1 + (0));
    v0 = v0 << (0x2 & 31);
    branch = ((s32)t5 >= 0); v1 = t5 << (0xb & 31);
    if (branch) goto L_7f63c;
    goto L_7f634;
L_7f634:
    v1 = v1 - t4; goto L_7f640;
L_7f63c:
    v1 = v1 + t4;
L_7f640:
    if (v1 == 0x80000000U && t0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t0) { lo = (s32)v1 / (s32)t0; hi = (s32)v1 % (s32)t0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    t5 = sp + 16;
    v0 = t5 + v0;
    t3 = t3 + 4;
    t2 = t2 + 4;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    *(volatile u32 *)(unsigned long)(t2 + (-4)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(t2 + (-4));
    branch = (t3 != a1); t1 = t1 + v0;
    if (branch) goto L_7f600;
    goto L_7f66c;
L_7f66c:
    v0 = t1 + -2048;
    branch = ((s32)v0 < 0); t1 = sp + 116;
    if (branch) goto L_7f680;
    goto L_7f678;
L_7f678:
    t0 = 0; goto L_7f6c4;
L_7f680:
    t1 = sp + 140;
    t0 = 0;
    v0 = -v0;
L_7f68c:
    v1 = (s32)t0 < (s32)(v0);
    branch = (v1 == 0); t2 = sp + 16;
    if (branch) goto L_7f6bc;
    goto L_7f698;
L_7f698:
    v1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t0 = t0 + 1;
    v1 = v1 << (0x2 & 31);
    v1 = t2 + v1;
    t2 = *(volatile u32 *)(unsigned long)(v1 + (172));
    t1 = t1 + 4;
    t2 = t2 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (172)) = t2; goto L_7f68c;
L_7f6bc:
    v1 = 0; goto L_7f6f4;
L_7f6c4:
    v1 = (s32)t0 < (s32)(v0);
    branch = (v1 == 0); t2 = sp + 16;
    if (branch) goto L_7f6bc;
    goto L_7f6d0;
L_7f6d0:
    v1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t0 = t0 + 1;
    v1 = v1 << (0x2 & 31);
    v1 = t2 + v1;
    t2 = *(volatile u32 *)(unsigned long)(v1 + (172));
    t1 = t1 + 4;
    t2 = t2 + -1;
    *(volatile u32 *)(unsigned long)(v1 + (172)) = t2; goto L_7f6c4;
L_7f6f4:
    v0 = sp + 164;
    v0 = v0 + v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 - a0;
    t0 = (s32)v0 >> (0x1f & 31);
    v0 = t0 ^ v0;
    v0 = v0 - t0;
    v0 = v0 << (0x2 & 31);
    t0 = sp + 16;
    v0 = t0 + v0;
    t0 = a3 + v1;
    t0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v1 = v1 + 4;
    branch = (v1 != a1); *(volatile u32 *)(unsigned long)(v0 + (0)) = t0;
    if (branch) goto L_7f6f4;
    goto L_7f730;
L_7f730:
    a0 = a0 + 1; goto L_7f5a8;
L_7f738:
    s4 = hi_7f738;
    s3 = 0;
    s5 = 24;
    s6 = 2048;
    s4 = s4 - hi_7f738 + (u32)(unsigned long)ref_t32_data_c9eac;
    s7 = hi_7f74c;
L_7f750:
    branch = (s3 == s1); v1 = 0;
    if (branch) goto L_7f7d0;
    goto L_7f758;
L_7f758:
    a1 = 0;
L_7f75c:
    v0 = sp + 164;
    v0 = v0 + v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = v1 + 4;
    v0 = v0 - s3;
    a0 = (s32)v0 >> (0x1f & 31);
    v0 = a0 ^ v0;
    v0 = v0 - a0;
    v0 = v0 << (0x2 & 31);
    a0 = sp + 16;
    v0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (v1 != s5); a1 = a1 + v0;
    if (branch) goto L_7f75c;
    goto L_7f794;
L_7f794:
    branch = (s3 == 0); v0 = a1 + -2047;
    if (branch) goto L_7f7a4;
    goto L_7f79c;
L_7f79c:
    branch = (s1 != s3); ;
    if (branch) goto L_7f7b4;
    goto L_7f7a4;
L_7f7a4:
    v1 = -3;
    v0 = v0 & v1;
    if (v0 == 0) { s3 = s3 + 1; goto L_7f750; }
    goto L_7f7b4;
L_7f7b4:
    if (a1 == s6) { s3 = s3 + 1; goto L_7f750; }
    goto L_7f7bc;
L_7f7bc:
    v0 = s7 - hi_7f74c + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7f7c8;
L_7f7c8:
    s3 = s3 + 1; goto L_7f750;
L_7f7d0:
    v0 = sp + 16;
L_7f7d4:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    v0 = v0 + 4;
    *(volatile u16 *)(unsigned long)(s0 + (0)) = a0;
    a0 = (s32)s2 < (s32)(v1);
    branch = (a0 == 0); s0 = s0 + 2;
    if (branch) goto L_7f7d4;
    goto L_7f7f0;
L_7f7f0:
    ra = *(volatile u32 *)(unsigned long)(sp + (252));
    s7 = *(volatile u32 *)(unsigned long)(sp + (248));
    s6 = *(volatile u32 *)(unsigned long)(sp + (244));
    s5 = *(volatile u32 *)(unsigned long)(sp + (240));
    s4 = *(volatile u32 *)(unsigned long)(sp + (236));
    s3 = *(volatile u32 *)(unsigned long)(sp + (232));
    s2 = *(volatile u32 *)(unsigned long)(sp + (228));
    s1 = *(volatile u32 *)(unsigned long)(sp + (224));
    s0 = *(volatile u32 *)(unsigned long)(sp + (220));
    sp = sp + 256;
    return ((u64)v1 << 32) | v0;
}
