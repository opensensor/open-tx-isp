/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_t32_data_c029c[] __asm__("t32_data_c029c");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_tisp_tmo_tmo_detail_ev_interp[] __asm__("tisp_tmo_tmo_detail_ev_interp");
extern unsigned char ref_tisp_tmo_tmo_dark_protect[] __asm__("tisp_tmo_tmo_dark_protect");
u64 tisp_tmo_tmo_ev_interp(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[180] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_96edc = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_96f1c = ((u32)(unsigned long)ref_t32_data_c029c + 0x8000U) & 0xffff0000U;
    const u32 hi_96f3c = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_97170 = ((u32)(unsigned long)ref_tisp_tmo_tmo_detail_ev_interp + 0x8000U) & 0xffff0000U;
    const u32 hi_971ac = ((u32)(unsigned long)ref_tisp_tmo_tmo_dark_protect + 0x8000U) & 0xffff0000U;
    const u32 hi_971c0 = ((u32)(unsigned long)ref_tisp_tmo_tmo_detail_ev_interp + 0x8000U) & 0xffff0000U;
    const u32 hi_97368 = ((u32)(unsigned long)ref_tisp_tmo_tmo_detail_ev_interp + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[116];
L_96edc:
    v0 = hi_96edc;
    sp = sp + -464;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_96edc + (u32)(unsigned long)ref_t32_data_e35e0;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (448)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (436)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (432)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (460)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (456)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (452)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (444)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (440)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (428)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (424)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = hi_96f1c;
    s6 = a0;
    s0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    s5 = *(volatile u32 *)(unsigned long)(v0 + (24));
    s8 = *(volatile u16 *)(unsigned long)(s0 + (4138));
    s7 = *(volatile u32 *)(unsigned long)(v0 + (28));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (32));
    v0 = hi_96f3c;
    a2 = 402;
    a1 = a1 - hi_96f1c + (u32)(unsigned long)ref_t32_data_c029c;
    a0 = sp + 16;
    v0 = v0 - hi_96f3c + ((u32)(unsigned long)ref_memcpy + (0));
    s3 = s0 + 888;
    callee = v0; s2 = s0 + 1008;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_96f5c;
L_96f5c:
    branch = (s8 != 0); v0 = 1;
    if (branch) goto L_971bc;
    goto L_96f64;
L_96f64:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (10931));
    branch = (v0 != 0); v1 = s2;
    if (branch) goto L_9700c;
    goto L_96f70;
L_96f70:
    v1 = s3;
    a1 = 0;
    a2 = 9;
L_96f7c:
    branch = (s7 != 0); v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    if (branch) goto L_96f90;
    goto L_96f84;
L_96f84:
    a0 = (u32)s5 < (u32)(v0);
    if (a0 != 0) { a1 = a1 + 1; goto L_96fc4; }
    goto L_96f90;
L_96f90:
    branch = (s7 != 0); a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    if (branch) goto L_96fc0;
    goto L_96f98;
L_96f98:
    a3 = (u32)s5 < (u32)(a0);
    if (a3 == 0) { a1 = a1 + 1; goto L_96fc4; }
    goto L_96fa4;
L_96fa4:
    v1 = a0 - s5;
    v1 = v1 << (0x8 & 31);
    a0 = a0 - v0;
    if (a0) { lo = v1 / a0; hi = v1 % a0; } else { lo = ~0U; hi = v1; }
    a0 = lo;
    v0 = a0 & 0xffff; goto L_96fd4;
L_96fc0:
    a1 = a1 + 1;
L_96fc4:
    a1 = a1 & 0xff;
    branch = (a1 != a2); v1 = v1 + 4;
    if (branch) goto L_96f7c;
    goto L_96fd0;
L_96fd0:
    v0 = 0;
L_96fd4:
    branch = (s7 != 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (924));
    if (branch) goto L_96fe8;
    goto L_96fdc;
L_96fdc:
    v1 = (u32)s5 < (u32)(v1);
    branch = (v1 != 0); ;
    if (branch) goto L_96ff0;
    goto L_96fe8;
L_96fe8:
    v0 = 0;
    a1 = 9;
L_96ff0:
    branch = (s7 != 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (888));
    if (branch) goto L_97084;
    goto L_96ff8;
L_96ff8:
    s5 = (u32)s5 < (u32)(v1);
    if (s5 != 0) { v0 = 256; goto L_97094; }
    goto L_97004;
L_97004:
    ; goto L_97084;
L_9700c:
    a1 = 0;
    a2 = 9;
L_97014:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = (u32)a0 < (u32)(s1);
    if (v0 != 0) { a1 = a1 + 1; goto L_97050; }
    goto L_97024;
L_97024:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a3 = (u32)v0 < (u32)(s1);
    if (a3 == 0) { a1 = a1 + 1; goto L_97050; }
    goto L_97034;
L_97034:
    v1 = a0 - s1;
    v1 = v1 << (0x8 & 31);
    a0 = a0 - v0;
    if (a0) { lo = v1 / a0; hi = v1 % a0; } else { lo = ~0U; hi = v1; }
    a0 = lo;
    v0 = a0 & 0xffff; goto L_97060;
L_97050:
    a1 = a1 & 0xff;
    branch = (a1 != a2); v1 = v1 + 4;
    if (branch) goto L_97014;
    goto L_9705c;
L_9705c:
    v0 = 0;
L_97060:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (1044));
    a0 = 9;
    v1 = (u32)v1 < (u32)(s1);
    if (v1 == 0) v0 = 0;
    if (v1 == 0) a1 = a0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (1008));
    s1 = (u32)v1 < (u32)(s1);
    if (s1 != 0) { v0 = 256; goto L_97094; }
    goto L_97084;
L_97084:
    branch = (a1 != 0); v1 = 1;
    if (branch) goto L_970a0;
    goto L_9708c;
L_9708c:
    a0 = s0 + 7398; goto L_97098;
L_97094:
    a0 = s0 + 7398;
L_97098:
    s0 = s0 + 7800; goto L_97134;
L_970a0:
    branch = (a1 != v1); v1 = 2;
    if (branch) goto L_970b4;
    goto L_970a8;
L_970a8:
    a0 = s0 + 7800;
    s0 = s0 + 4182; goto L_97134;
L_970b4:
    branch = (a1 != v1); v1 = 3;
    if (branch) goto L_970c8;
    goto L_970bc;
L_970bc:
    a0 = s0 + 4182;
    s0 = s0 + 4584; goto L_97134;
L_970c8:
    branch = (a1 != v1); v1 = 4;
    if (branch) goto L_970dc;
    goto L_970d0;
L_970d0:
    a0 = s0 + 4584;
    s0 = s0 + 4986; goto L_97134;
L_970dc:
    branch = (a1 != v1); v1 = 5;
    if (branch) goto L_970f0;
    goto L_970e4;
L_970e4:
    a0 = s0 + 4986;
    s0 = s0 + 5388; goto L_97134;
L_970f0:
    branch = (a1 != v1); v1 = 6;
    if (branch) goto L_97104;
    goto L_970f8;
L_970f8:
    a0 = s0 + 5388;
    s0 = s0 + 5790; goto L_97134;
L_97104:
    if (a1 != v1) { a0 = 7; goto L_97118; }
    goto L_9710c;
L_9710c:
    a0 = s0 + 5790;
    s0 = s0 + 6192; goto L_97134;
L_97118:
    branch = (a1 != a0); v1 = s0 + 6594;
    if (branch) goto L_9712c;
    goto L_97120;
L_97120:
    a0 = s0 + 6192;
    s0 = v1; goto L_97134;
L_9712c:
    a0 = v1;
    s0 = s0 + 6996;
L_97134:
    a2 = 256;
    a3 = a0 + 402;
    t0 = a2 - v0;
L_97140:
    v1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a1 = *(volatile u16 *)(unsigned long)(s0 + (0));
    a0 = a0 + 2;
    product = (s64)(s32)v1 * (s32)v0; lo = product; hi = product >> 32;
    s0 = s0 + 2;
    s4 = s4 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)a1); lo = product; hi = product >> 32;
    v1 = lo;
    if (v1 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v1 / (s32)a2; hi = (s32)v1 % (s32)a2; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    branch = (a3 != a0); *(volatile u16 *)(unsigned long)(s4 + (-2)) = v1;
    if (branch) goto L_97140;
    goto L_97170;
L_97170:
    v0 = hi_97170;
L_97174:
    v0 = v0 - hi_97170 + (u32)(unsigned long)ref_tisp_tmo_tmo_detail_ev_interp;
    callee = v0; a0 = s6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_97180;
L_97180:
    ra = *(volatile u32 *)(unsigned long)(sp + (460));
    s8 = *(volatile u32 *)(unsigned long)(sp + (456));
    s7 = *(volatile u32 *)(unsigned long)(sp + (452));
    s5 = *(volatile u32 *)(unsigned long)(sp + (444));
    s4 = *(volatile u32 *)(unsigned long)(sp + (440));
    s3 = *(volatile u32 *)(unsigned long)(sp + (436));
    s2 = *(volatile u32 *)(unsigned long)(sp + (432));
    s1 = *(volatile u32 *)(unsigned long)(sp + (428));
    s0 = *(volatile u32 *)(unsigned long)(sp + (424));
    a0 = s6;
    s6 = *(volatile u32 *)(unsigned long)(sp + (448));
    t9 = hi_971ac;
    t9 = t9 - hi_971ac + (u32)(unsigned long)ref_tisp_tmo_tmo_dark_protect;
    callee = t9; sp = sp + 464;
    switch (callee) { case 0x96edc: goto L_96edc; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_971bc:
    branch = (s8 != v0); v0 = hi_971c0;
    if (branch) goto L_97174;
    goto L_971c4;
L_971c4:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (10931));
    branch = (v0 != 0); t1 = s0 + 4118;
    if (branch) goto L_97288;
    goto L_971d0;
L_971d0:
    v1 = s3;
    a0 = 0;
    a2 = 9;
L_971dc:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    branch = (s7 != 0); a3 = a0 + 1;
    if (branch) goto L_971f4;
    goto L_971e8;
L_971e8:
    a1 = (u32)s5 < (u32)(v0);
    if (a1 != 0) { a0 = a3; goto L_97248; }
    goto L_971f4;
L_971f4:
    branch = (s7 != 0); a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    if (branch) goto L_97244;
    goto L_971fc;
L_971fc:
    t0 = (u32)s5 < (u32)(a1);
    if (t0 == 0) { a0 = a3; goto L_97248; }
    goto L_97208;
L_97208:
    a0 = a0 << (0x1 & 31);
    a3 = a3 << (0x1 & 31);
    a0 = t1 + a0;
    a2 = t1 + a3;
    t0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a0 = t0 - v1;
    v1 = s5 - v0;
    v1 = a0 * v1;
    v0 = a1 - v0;
    if (v0) { lo = v1 / v0; hi = v1 % v0; } else { lo = ~0U; hi = v1; }
    v1 = lo;
    v1 = t0 - v1;
    v0 = v1 & 0xffff; goto L_97254;
L_97244:
    a0 = a3;
L_97248:
    branch = (a3 != a2); v1 = v1 + 4;
    if (branch) goto L_971dc;
    goto L_97250;
L_97250:
    v0 = 0;
L_97254:
    branch = (s7 != 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (924));
    if (branch) goto L_97268;
    goto L_9725c;
L_9725c:
    v1 = (u32)s5 < (u32)(v1);
    branch = (v1 != 0); ;
    if (branch) goto L_9726c;
    goto L_97268;
L_97268:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (4136));
L_9726c:
    branch = (s7 != 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (888));
    if (branch) goto L_97320;
    goto L_97274;
L_97274:
    s5 = (u32)s5 < (u32)(v1);
    branch = (s5 == 0); a3 = 256;
    if (branch) goto L_97324;
    goto L_97280;
L_97280:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (4118)); goto L_97324;
L_97288:
    v1 = s2;
    a0 = 0;
    v0 = 9;
L_97294:
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = (u32)a1 < (u32)(s1);
    branch = (a3 != 0); a2 = a0 + 1;
    if (branch) goto L_972f0;
    goto L_972a4;
L_972a4:
    a3 = *(volatile u32 *)(unsigned long)(v1 + (4));
    t0 = (u32)a3 < (u32)(s1);
    if (t0 == 0) { a0 = a2; goto L_972f4; }
    goto L_972b4;
L_972b4:
    a0 = a0 << (0x1 & 31);
    a2 = a2 << (0x1 & 31);
    a0 = t1 + a0;
    a2 = t1 + a2;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a0 = v0 - v1;
    v1 = a1 - s1;
    v1 = a0 * v1;
    a1 = a1 - a3;
    if (a1) { lo = v1 / a1; hi = v1 % a1; } else { lo = ~0U; hi = v1; }
    v1 = lo;
    v1 = v0 - v1;
    v0 = v1 & 0xffff; goto L_97300;
L_972f0:
    a0 = a2;
L_972f4:
    branch = (a2 != v0); v1 = v1 + 4;
    if (branch) goto L_97294;
    goto L_972fc;
L_972fc:
    v0 = 0;
L_97300:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (1044));
    v1 = (u32)v1 < (u32)(s1);
    if (v1 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (4136)); goto L_97310; }
    goto L_97310;
L_97310:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (1008));
    s1 = (u32)v1 < (u32)(s1);
    if (s1 != 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (4118)); goto L_97320; }
    goto L_97320;
L_97320:
    a3 = 256;
L_97324:
    a2 = s0 + 7398;
    v1 = sp + 16;
    s0 = s0 + 7800;
    t0 = a3 - v0;
L_97334:
    a0 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a2 = a2 + 2;
    product = (s64)(s32)a0 * (s32)v0; lo = product; hi = product >> 32;
    v1 = v1 + 2;
    s4 = s4 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)a1); lo = product; hi = product >> 32;
    a0 = lo;
    if (a0 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)a0 / (s32)a3; hi = (s32)a0 % (s32)a3; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    branch = (a2 != s0); *(volatile u16 *)(unsigned long)(s4 + (-2)) = a0;
    if (branch) goto L_97334;
    goto L_97364;
L_97364:
    v0 = hi_97368; goto L_97174;
}
