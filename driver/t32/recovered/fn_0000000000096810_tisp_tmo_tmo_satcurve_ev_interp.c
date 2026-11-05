/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
u64 tisp_tmo_tmo_satcurve_ev_interp(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[66] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_96810 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[2];
L_96810:
    v0 = hi_96810;
    sp = sp + -8;
    v0 = v0 - hi_96810 + (u32)(unsigned long)ref_t32_data_e35e0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v1 + (4));
    t3 = *(volatile u32 *)(unsigned long)(v1 + (24));
    t4 = *(volatile u32 *)(unsigned long)(v1 + (28));
    t2 = *(volatile u32 *)(unsigned long)(v1 + (32));
    v1 = *(volatile u8 *)(unsigned long)(v0 + (10931));
    t5 = a3 + 268;
    t1 = a3 + 154;
    t0 = a3 + 182;
    branch = (v1 != 0); a3 = a3 + 210;
    if (branch) goto L_968ec;
    goto L_96858;
L_96858:
    a0 = v0 + 888;
    t6 = 0;
    a2 = 9;
L_96864:
    branch = (t4 != 0); v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    if (branch) goto L_96878;
    goto L_9686c;
L_9686c:
    a1 = (u32)t3 < (u32)(v1);
    if (a1 != 0) { t6 = t6 + 1; goto L_968ac; }
    goto L_96878;
L_96878:
    branch = (t4 != 0); a1 = *(volatile u32 *)(unsigned long)(a0 + (4));
    if (branch) goto L_968a8;
    goto L_96880;
L_96880:
    t7 = (u32)t3 < (u32)(a1);
    if (t7 == 0) { t6 = t6 + 1; goto L_968ac; }
    goto L_9688c;
L_9688c:
    a2 = a1 - t3;
    a2 = a2 << (0x8 & 31);
    a1 = a1 - v1;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    v1 = a1 & 0xffff; goto L_968bc;
L_968a8:
    t6 = t6 + 1;
L_968ac:
    t6 = t6 & 0xff;
    branch = (t6 != a2); a0 = a0 + 4;
    if (branch) goto L_96864;
    goto L_968b8;
L_968b8:
    v1 = 0;
L_968bc:
    branch = (t4 != 0); a0 = *(volatile u32 *)(unsigned long)(v0 + (924));
    if (branch) goto L_968d0;
    goto L_968c4;
L_968c4:
    a0 = (u32)t3 < (u32)(a0);
    if (a0 != 0) { a0 = *(volatile u32 *)(unsigned long)(v0 + (888)); goto L_968dc; }
    goto L_968d0;
L_968d0:
    v1 = 0;
    t6 = 9;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (888));
L_968dc:
    branch = (t4 == 0); a0 = (u32)t3 < (u32)(a0);
    if (branch) goto L_96960;
    goto L_968e4;
L_968e4:
    ; goto L_96968;
L_968ec:
    a0 = v0 + 1008;
    t6 = 0;
    a2 = 9;
L_968f8:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = (u32)a1 < (u32)(t2);
    if (v1 != 0) { t6 = t6 + 1; goto L_96934; }
    goto L_96908;
L_96908:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (4));
    t7 = (u32)v1 < (u32)(t2);
    if (t7 == 0) { t6 = t6 + 1; goto L_96934; }
    goto L_96918;
L_96918:
    a2 = a1 - t2;
    a2 = a2 << (0x8 & 31);
    a1 = a1 - v1;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    v1 = a1 & 0xffff; goto L_96944;
L_96934:
    t6 = t6 & 0xff;
    branch = (t6 != a2); a0 = a0 + 4;
    if (branch) goto L_968f8;
    goto L_96940;
L_96940:
    v1 = 0;
L_96944:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1044));
    a1 = 9;
    a0 = (u32)a0 < (u32)(t2);
    if (a0 == 0) v1 = 0;
    if (a0 == 0) t6 = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1008));
    a0 = (u32)a0 < (u32)(t2);
L_96960:
    if (a0 != 0) { v1 = 256; goto L_96978; }
    goto L_96968;
L_96968:
    if (t6 != 0) { a0 = 1; goto L_96984; }
    goto L_96970;
L_96970:
    a1 = v0 + 1136; goto L_9697c;
L_96978:
    a1 = v0 + 1136;
L_9697c:
    a0 = v0 + 1186; goto L_96a14;
L_96984:
    if (t6 != a0) { a0 = 2; goto L_96998; }
    goto L_9698c;
L_9698c:
    a1 = v0 + 1186;
    a0 = v0 + 1236; goto L_96a14;
L_96998:
    if (t6 != a0) { a0 = 3; goto L_969ac; }
    goto L_969a0;
L_969a0:
    a1 = v0 + 1236;
    a0 = v0 + 1286; goto L_96a14;
L_969ac:
    if (t6 != a0) { a0 = 4; goto L_969c0; }
    goto L_969b4;
L_969b4:
    a1 = v0 + 1286;
    a0 = v0 + 1336; goto L_96a14;
L_969c0:
    if (t6 != a0) { a0 = 5; goto L_969d4; }
    goto L_969c8;
L_969c8:
    a1 = v0 + 1336;
    a0 = v0 + 1386; goto L_96a14;
L_969d4:
    if (t6 != a0) { a0 = 6; goto L_969e8; }
    goto L_969dc;
L_969dc:
    a1 = v0 + 1386;
    a0 = v0 + 1436; goto L_96a14;
L_969e8:
    if (t6 != a0) { a1 = 7; goto L_969fc; }
    goto L_969f0;
L_969f0:
    a1 = v0 + 1436;
    a0 = v0 + 1486; goto L_96a14;
L_969fc:
    branch = (t6 != a1); a0 = v0 + 1536;
    if (branch) goto L_96a0c;
    goto L_96a04;
L_96a04:
    a1 = v0 + 1486; goto L_96a14;
L_96a0c:
    a1 = a0;
    a0 = v0 + 1586;
L_96a14:
    t7 = 256;
    t6 = t5;
    t8 = a1 + 50;
    t9 = t7 - v1;
L_96a24:
    a2 = *(volatile u16 *)(unsigned long)(a1 + (0));
    t5 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a1 = a1 + 2;
    product = (s64)(s32)a2 * (s32)v1; lo = product; hi = product >> 32;
    a0 = a0 + 2;
    t6 = t6 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t9 * (s32)t5); lo = product; hi = product >> 32;
    a2 = lo;
    if (a2 == 0x80000000U && t7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t7) { lo = (s32)a2 / (s32)t7; hi = (s32)a2 % (s32)t7; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    branch = (a1 != t8); *(volatile u16 *)(unsigned long)(t6 + (-2)) = a2;
    if (branch) goto L_96a24;
    goto L_96a54;
L_96a54:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (10931));
    if (v1 != 0) { a0 = v0 + 1048; goto L_96afc; }
    goto L_96a60;
L_96a60:
    a1 = v0 + 968;
    t5 = 0;
    a2 = 9;
L_96a6c:
    branch = (t4 != 0); v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    if (branch) goto L_96a80;
    goto L_96a74;
L_96a74:
    a0 = (u32)t3 < (u32)(v1);
    if (a0 != 0) { t5 = t5 + 1; goto L_96ab4; }
    goto L_96a80;
L_96a80:
    branch = (t4 != 0); a0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    if (branch) goto L_96ab0;
    goto L_96a88;
L_96a88:
    t2 = (u32)t3 < (u32)(a0);
    if (t2 == 0) { t5 = t5 + 1; goto L_96ab4; }
    goto L_96a94;
L_96a94:
    a1 = a0 - t3;
    a1 = a1 << (0x8 & 31);
    a0 = a0 - v1;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    v1 = a0 & 0xffff; goto L_96ac4;
L_96ab0:
    t5 = t5 + 1;
L_96ab4:
    t5 = t5 & 0xff;
    branch = (t5 != a2); a1 = a1 + 4;
    if (branch) goto L_96a6c;
    goto L_96ac0;
L_96ac0:
    v1 = 0;
L_96ac4:
    branch = (t4 != 0); a0 = *(volatile u32 *)(unsigned long)(v0 + (1004));
    if (branch) goto L_96ad8;
    goto L_96acc;
L_96acc:
    a0 = (u32)t3 < (u32)(a0);
    branch = (a0 != 0); ;
    if (branch) goto L_96ae0;
    goto L_96ad8;
L_96ad8:
    v1 = 0;
    t5 = 9;
L_96ae0:
    branch = (t4 != 0); a0 = *(volatile u32 *)(unsigned long)(v0 + (968));
    if (branch) goto L_96b74;
    goto L_96ae8;
L_96ae8:
    t3 = (u32)t3 < (u32)(a0);
    if (t3 != 0) { v1 = 256; goto L_96b84; }
    goto L_96af4;
L_96af4:
    ; goto L_96b74;
L_96afc:
    t5 = 0;
    a2 = 9;
L_96b04:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = (u32)a1 < (u32)(t2);
    if (v1 != 0) { t5 = t5 + 1; goto L_96b40; }
    goto L_96b14;
L_96b14:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (4));
    t3 = (u32)v1 < (u32)(t2);
    if (t3 == 0) { t5 = t5 + 1; goto L_96b40; }
    goto L_96b24;
L_96b24:
    a2 = a1 - t2;
    a2 = a2 << (0x8 & 31);
    a1 = a1 - v1;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    v1 = a1 & 0xffff; goto L_96b50;
L_96b40:
    t5 = t5 & 0xff;
    branch = (t5 != a2); a0 = a0 + 4;
    if (branch) goto L_96b04;
    goto L_96b4c;
L_96b4c:
    v1 = 0;
L_96b50:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1084));
    a1 = 9;
    a0 = (u32)a0 < (u32)(t2);
    if (a0 == 0) v1 = 0;
    if (a0 == 0) t5 = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1048));
    a0 = (u32)a0 < (u32)(t2);
    if (a0 != 0) { v1 = 256; goto L_96b84; }
    goto L_96b74;
L_96b74:
    branch = (t5 != 0); a0 = 1;
    if (branch) goto L_96ba0;
    goto L_96b7c;
L_96b7c:
    t6 = v0 + 1652; goto L_96b88;
L_96b84:
    t6 = v0 + 1652;
L_96b88:
    t3 = v0 + 1680;
    t5 = v0 + 1932;
    t2 = v0 + 1960;
    t4 = v0 + 2212;
    v0 = v0 + 2240; goto L_96cb4;
L_96ba0:
    branch = (t5 != a0); a0 = 2;
    if (branch) goto L_96bc4;
    goto L_96ba8;
L_96ba8:
    t6 = v0 + 1680;
    t3 = v0 + 1708;
    t5 = v0 + 1960;
    t2 = v0 + 1988;
    t4 = v0 + 2240;
    v0 = v0 + 2268; goto L_96cb4;
L_96bc4:
    branch = (t5 != a0); a0 = 3;
    if (branch) goto L_96be8;
    goto L_96bcc;
L_96bcc:
    t6 = v0 + 1708;
    t3 = v0 + 1736;
    t5 = v0 + 1988;
    t2 = v0 + 2016;
    t4 = v0 + 2268;
    v0 = v0 + 2296; goto L_96cb4;
L_96be8:
    branch = (t5 != a0); a0 = 4;
    if (branch) goto L_96c0c;
    goto L_96bf0;
L_96bf0:
    t6 = v0 + 1736;
    t3 = v0 + 1764;
    t5 = v0 + 2016;
    t2 = v0 + 2044;
    t4 = v0 + 2296;
    v0 = v0 + 2324; goto L_96cb4;
L_96c0c:
    branch = (t5 != a0); a0 = 5;
    if (branch) goto L_96c30;
    goto L_96c14;
L_96c14:
    t6 = v0 + 1764;
    t3 = v0 + 1792;
    t5 = v0 + 2044;
    t2 = v0 + 2072;
    t4 = v0 + 2324;
    v0 = v0 + 2352; goto L_96cb4;
L_96c30:
    branch = (t5 != a0); a0 = 6;
    if (branch) goto L_96c54;
    goto L_96c38;
L_96c38:
    t6 = v0 + 1792;
    t3 = v0 + 1820;
    t5 = v0 + 2072;
    t2 = v0 + 2100;
    t4 = v0 + 2352;
    v0 = v0 + 2380; goto L_96cb4;
L_96c54:
    branch = (t5 != a0); a1 = 7;
    if (branch) goto L_96c78;
    goto L_96c5c;
L_96c5c:
    t6 = v0 + 1820;
    t3 = v0 + 1848;
    t5 = v0 + 2100;
    t2 = v0 + 2128;
    t4 = v0 + 2380;
    v0 = v0 + 2408; goto L_96cb4;
L_96c78:
    t3 = v0 + 1876;
    t2 = v0 + 2156;
    branch = (t5 != a1); a0 = v0 + 2436;
    if (branch) goto L_96c9c;
    goto L_96c88;
L_96c88:
    t6 = v0 + 1848;
    t5 = v0 + 2128;
    t4 = v0 + 2408;
    v0 = a0; goto L_96cb4;
L_96c9c:
    t6 = t3;
    t5 = t2;
    t3 = v0 + 1904;
    t2 = v0 + 2184;
    t4 = a0;
    v0 = v0 + 2464;
L_96cb4:
    t7 = 256;
    a2 = 0;
    t8 = t7 - v1;
    t9 = 28;
L_96cc4:
    a0 = t6 + a2;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = t3 + a2;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    s0 = t1 + a2;
    product = (s64)(s32)a0 * (s32)t8; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a1 * (s32)v1); lo = product; hi = product >> 32;
    a0 = lo;
    if (a0 == 0x80000000U && t7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t7) { lo = (s32)a0 / (s32)t7; hi = (s32)a0 % (s32)t7; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    *(volatile u16 *)(unsigned long)(s0 + (0)) = a0;
    a0 = t5 + a2;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = t2 + a2;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    s0 = t0 + a2;
    product = (s64)(s32)a0 * (s32)t8; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a1 * (s32)v1); lo = product; hi = product >> 32;
    a0 = lo;
    if (a0 == 0x80000000U && t7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t7) { lo = (s32)a0 / (s32)t7; hi = (s32)a0 % (s32)t7; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    *(volatile u16 *)(unsigned long)(s0 + (0)) = a0;
    a0 = t4 + a2;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = v0 + a2;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    s0 = a3 + a2;
    a2 = a2 + 2;
    product = (s64)(s32)a0 * (s32)t8; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a1 * (s32)v1); lo = product; hi = product >> 32;
    a0 = lo;
    if (a0 == 0x80000000U && t7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t7) { lo = (s32)a0 / (s32)t7; hi = (s32)a0 % (s32)t7; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    branch = (a2 != t9); *(volatile u16 *)(unsigned long)(s0 + (0)) = a0;
    if (branch) goto L_96cc4;
    goto L_96d50;
L_96d50:
    s0 = *(volatile u32 *)(unsigned long)(sp + (4));
    sp = sp + 8;
    return ((u64)v1 << 32) | v0;
}
