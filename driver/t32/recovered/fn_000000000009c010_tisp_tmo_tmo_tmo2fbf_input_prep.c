/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_tisp_tmo_tmo_interplate[] __asm__("tisp_tmo_tmo_interplate");
extern unsigned char ref_memset[] __asm__("memset");
u64 tisp_tmo_tmo_tmo2fbf_input_prep(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[98] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_9c010 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9c0d0 = ((u32)(unsigned long)ref_tisp_tmo_tmo_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_9c584 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[34];
L_9c010:
    v0 = hi_9c010;
    sp = sp + -136;
    v0 = v0 - hi_9c010 + (u32)(unsigned long)ref_t32_data_e35e0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (132)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (128)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (124)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (120)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (116)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (112)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (108)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (104)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (100)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (96)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = 2;
    *(volatile u32 *)(unsigned long)(sp + (24)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    s6 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    *(volatile u32 *)(unsigned long)(sp + (28)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (32)) = 0;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (18));
    *(volatile u32 *)(unsigned long)(sp + (36)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (40)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (64)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(v1 + (10928));
    branch = (v0 != a0); a0 = 1;
    if (branch) goto L_9c574;
    goto L_9c08c;
L_9c08c:
    v0 = v1 + 8202;
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
    v0 = v1 + 8218;
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    v0 = v1 + 10906;
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v0 = v1 + 10914;
    *(volatile u32 *)(unsigned long)(sp + (60)) = v0;
    v0 = v1 + 10908;
    *(volatile u32 *)(unsigned long)(sp + (84)) = v0;
    v0 = v1 + 8216;
    s2 = s0 + 25;
    t5 = 0;
    t0 = 0;
    t9 = 0;
    s7 = s6 + 15000;
    s3 = 100;
    t2 = hi_9c0d0;
    *(volatile u32 *)(unsigned long)(sp + (88)) = v0;
L_9c0d8:
    v0 = t5 + 250;
    v0 = v0 & 0xffff;
    *(volatile u32 *)(unsigned long)(sp + (68)) = v0;
    v0 = t5 + 260;
    t8 = s2;
    t3 = 0;
    *(volatile u32 *)(unsigned long)(sp + (80)) = v0;
L_9c0f4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (80));
    s4 = t5 + t3;
    s5 = sp + 24;
    v0 = t3 + v0;
    v0 = v0 & 0xffff;
    s1 = 0;
    a1 = 0;
    t1 = 0;
    a0 = 0;
    s4 = s4 - v0;
L_9c11c:
    a3 = v0 << (0x2 & 31);
    a2 = s7 + a3;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    a3 = s6 + a3;
    a3 = *(volatile u32 *)(unsigned long)(a3 + (0));
    t6 = a2 * s1;
    t4 = a2 & 0xffff;
    a3 = a3 << (0x9 & 31);
    *(volatile u16 *)(unsigned long)(s5 + (0)) = t4;
    t4 = (u32)t4 < (u32)(151);
    a3 = t6 + a3;
    t6 = *(volatile u32 *)(unsigned long)(sp + (64));
    a3 = a3 >> (t6 & 31);
    branch = (t4 != 0); a1 = a1 + a3;
    if (branch) goto L_9c160;
    goto L_9c158;
L_9c158:
    t1 = t1 + 1;
    t1 = t1 & 0xff;
L_9c160:
    t4 = v0 + s4;
    a3 = 0;
    a2 = a2 & 0xffff;
    *(volatile u32 *)(unsigned long)(sp + (76)) = t4;
    t6 = *(volatile u32 *)(unsigned long)(sp + (76));
L_9c174:
    t4 = 0;
    t6 = a3 + t6;
    *(volatile u32 *)(unsigned long)(sp + (72)) = t6;
L_9c180:
    t6 = *(volatile u32 *)(unsigned long)(sp + (72));
    t6 = t4 + t6;
    t6 = t6 & 0xffff;
    t6 = t6 << (0x2 & 31);
    t6 = s7 + t6;
    t7 = *(volatile u16 *)(unsigned long)(t6 + (0));
    t4 = t4 + 10;
    t4 = t4 & 0xffff;
    t6 = (u32)t7 < (u32)(a2);
    s8 = a2 - t7;
    t7 = t7 - a2;
    if (t6 != 0) t7 = s8;
    t7 = t7 & 0xffff;
    t6 = 30;
    branch = (t4 != t6); a0 = a0 + t7;
    if (branch) goto L_9c180;
    goto L_9c1c0;
L_9c1c0:
    a3 = a3 + 250;
    a3 = a3 & 0xffff;
    t4 = 750;
    branch = (a3 != t4); t6 = *(volatile u32 *)(unsigned long)(sp + (76));
    if (branch) goto L_9c174;
    goto L_9c1d4;
L_9c1d4:
    v0 = v0 + 1;
    s1 = s1 + 819;
    a2 = 8190;
    v0 = v0 & 0xffff;
    branch = (s1 != a2); s5 = s5 + 2;
    if (branch) goto L_9c11c;
    goto L_9c1ec;
L_9c1ec:
    s1 = a0 >> (0x6 & 31);
    v0 = *(volatile u16 *)(unsigned long)(sp + (24));
    a0 = *(volatile u16 *)(unsigned long)(sp + (26));
    t4 = *(volatile u16 *)(unsigned long)(sp + (42));
    t6 = *(volatile u8 *)(unsigned long)(v1 + (10894));
    v0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(sp + (28));
    t7 = a1 >> (0xc & 31);
    v0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(sp + (30));
    v0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(sp + (32));
    v0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(sp + (34));
    v0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(sp + (36));
    v0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(sp + (40));
    v0 = v0 & 0xffff;
    t4 = a0 + t4;
    a0 = *(volatile u16 *)(unsigned long)(sp + (38));
    t4 = t4 & 0xffff;
    a0 = t4 + a0;
    a0 = v0 + a0;
    v0 = v0 * s3;
    a0 = a0 & 0xffff;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    a2 = v0 & 0xff;
    t4 = t4 * s3;
    if (t4 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)t4 / (s32)a0; hi = (s32)t4 % (s32)a0; } else { lo = (s32)t4 < 0 ? 1 : ~0U; hi = t4; }
    a0 = (u32)a2 < (u32)(t6);
    t4 = lo;
    branch = (a0 == 0); s4 = t4 & 0xff;
    if (branch) goto L_9c280;
    goto L_9c278;
L_9c278:
    t6 = *(volatile u8 *)(unsigned long)(v1 + (10900)); goto L_9c2d8;
L_9c280:
    a0 = *(volatile u8 *)(unsigned long)(v1 + (10895));
    a1 = (u32)a2 < (u32)(a0);
    if (a1 == 0) { a1 = *(volatile u8 *)(unsigned long)(v1 + (10896)); goto L_9c2ac; }
    goto L_9c290;
L_9c290:
    v0 = v0 & 0xff;
    a3 = *(volatile u8 *)(unsigned long)(v1 + (10901));
    a2 = *(volatile u8 *)(unsigned long)(v1 + (10900));
    a1 = a0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    a0 = t6; goto L_9c2c8;
L_9c2ac:
    a2 = (u32)a2 < (u32)(a1);
    branch = (a2 == 0); t6 = *(volatile u8 *)(unsigned long)(v1 + (10902));
    if (branch) goto L_9c2d8;
    goto L_9c2b8;
L_9c2b8:
    v0 = v0 & 0xff;
    a2 = *(volatile u8 *)(unsigned long)(v1 + (10901));
    a3 = t6;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
L_9c2c8:
    v0 = t2 - hi_9c0d0 + (u32)(unsigned long)ref_tisp_tmo_tmo_interplate;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c2d4;
L_9c2d4:
    t6 = v0 & 0xff;
L_9c2d8:
    a0 = *(volatile u8 *)(unsigned long)(v1 + (10897));
    v0 = (u32)s4 < (u32)(a0);
    if (v0 == 0) { v0 = *(volatile u8 *)(unsigned long)(v1 + (10898)); goto L_9c2f0; }
    goto L_9c2e8;
L_9c2e8:
    a3 = *(volatile u8 *)(unsigned long)(v1 + (10903)); goto L_9c340;
L_9c2f0:
    a1 = (u32)s4 < (u32)(v0);
    if (a1 == 0) { a1 = *(volatile u8 *)(unsigned long)(v1 + (10899)); goto L_9c314; }
    goto L_9c2fc;
L_9c2fc:
    t4 = t4 & 0xff;
    a3 = *(volatile u8 *)(unsigned long)(v1 + (10904));
    a2 = *(volatile u8 *)(unsigned long)(v1 + (10903));
    a1 = v0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t4; goto L_9c330;
L_9c314:
    s4 = (u32)s4 < (u32)(a1);
    branch = (s4 == 0); a3 = *(volatile u8 *)(unsigned long)(v1 + (10905));
    if (branch) goto L_9c340;
    goto L_9c320;
L_9c320:
    t4 = t4 & 0xff;
    a2 = *(volatile u8 *)(unsigned long)(v1 + (10904));
    a0 = v0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t4;
L_9c330:
    v0 = t2 - hi_9c0d0 + (u32)(unsigned long)ref_tisp_tmo_tmo_interplate;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c33c;
L_9c33c:
    a3 = v0 & 0xff;
L_9c340:
    v0 = *(volatile u8 *)(unsigned long)(v1 + (10906));
    t6 = t6 + a3;
    t6 = t6 + 8;
    v0 = (u32)t1 < (u32)(v0);
    branch = (v0 == 0); t6 = (s32)t6 >> (0x4 & 31);
    if (branch) goto L_9c360;
    goto L_9c358;
L_9c358:
    t9 = *(volatile u8 *)(unsigned long)(v1 + (10914)); goto L_9c3c8;
L_9c360:
    v0 = *(volatile u8 *)(unsigned long)(v1 + (10908));
    v0 = (u32)t1 < (u32)(v0);
    if (v0 == 0) { t9 = *(volatile u8 *)(unsigned long)(v1 + (10916)); goto L_9c3c8; }
    goto L_9c370;
L_9c370:
    t4 = *(volatile u32 *)(unsigned long)(sp + (56));
    s4 = *(volatile u32 *)(unsigned long)(sp + (60));
    a0 = *(volatile u8 *)(unsigned long)(t4 + (0));
L_9c37c:
    v0 = (u32)t1 < (u32)(a0);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(sp + (84));
    if (branch) goto L_9c3b4;
    goto L_9c388;
L_9c388:
    a1 = *(volatile u8 *)(unsigned long)(t4 + (1));
    v0 = (u32)t1 < (u32)(a1);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (84));
    if (branch) goto L_9c3b4;
    goto L_9c398;
L_9c398:
    a3 = *(volatile u8 *)(unsigned long)(s4 + (1));
    a2 = *(volatile u8 *)(unsigned long)(s4 + (0));
    v0 = t2 - hi_9c0d0 + (u32)(unsigned long)ref_tisp_tmo_tmo_interplate;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = t1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c3ac;
L_9c3ac:
    t9 = v0 & 0xff;
    v0 = *(volatile u32 *)(unsigned long)(sp + (84));
L_9c3b4:
    t4 = t4 + 1;
    branch = (t4 == v0); s4 = s4 + 1;
    if (branch) goto L_9c3c8;
    goto L_9c3c0;
L_9c3c0:
    a0 = *(volatile u8 *)(unsigned long)(t4 + (0)); goto L_9c37c;
L_9c3c8:
    a0 = *(volatile u8 *)(unsigned long)(v1 + (10922));
    v0 = (u32)a0 < (u32)(t7);
    if (v0 != 0) { v0 = *(volatile u8 *)(unsigned long)(v1 + (10923)); goto L_9c3e0; }
    goto L_9c3d8;
L_9c3d8:
    t1 = *(volatile u8 *)(unsigned long)(v1 + (10925)); goto L_9c42c;
L_9c3e0:
    a1 = (u32)v0 < (u32)(t7);
    if (a1 != 0) { a1 = *(volatile u8 *)(unsigned long)(v1 + (10924)); goto L_9c400; }
    goto L_9c3ec;
L_9c3ec:
    a3 = *(volatile u8 *)(unsigned long)(v1 + (10926));
    a2 = *(volatile u8 *)(unsigned long)(v1 + (10925));
    a1 = v0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t7; goto L_9c41c;
L_9c400:
    a0 = (u32)a1 < (u32)(t7);
    branch = (a0 != 0); t1 = *(volatile u8 *)(unsigned long)(v1 + (10927));
    if (branch) goto L_9c42c;
    goto L_9c40c;
L_9c40c:
    a2 = *(volatile u8 *)(unsigned long)(v1 + (10926));
    a3 = t1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t7;
    a0 = v0;
L_9c41c:
    v0 = t2 - hi_9c0d0 + (u32)(unsigned long)ref_tisp_tmo_tmo_interplate;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c428;
L_9c428:
    t1 = v0 & 0xff;
L_9c42c:
    v0 = *(volatile u16 *)(unsigned long)(v1 + (8202));
    v0 = (u32)s1 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u16 *)(unsigned long)(v1 + (8216)); goto L_9c444; }
    goto L_9c43c;
L_9c43c:
    t0 = *(volatile u16 *)(unsigned long)(v1 + (8218)); goto L_9c4b8;
L_9c444:
    v0 = (u32)s1 < (u32)(v0);
    if (v0 == 0) { t0 = *(volatile u16 *)(unsigned long)(v1 + (8232)); goto L_9c4b8; }
    goto L_9c450;
L_9c450:
    t4 = *(volatile u32 *)(unsigned long)(sp + (48));
    t7 = *(volatile u32 *)(unsigned long)(sp + (52));
L_9c458:
    a0 = *(volatile u16 *)(unsigned long)(t4 + (0));
    v0 = (u32)s1 < (u32)(a0);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(sp + (88));
    if (branch) goto L_9c4a4;
    goto L_9c468;
L_9c468:
    a1 = *(volatile u16 *)(unsigned long)(t4 + (2));
    v0 = (u32)s1 < (u32)(a1);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (88));
    if (branch) goto L_9c4a4;
    goto L_9c478;
L_9c478:
    a3 = *(volatile u16 *)(unsigned long)(t7 + (2));
    a2 = *(volatile u16 *)(unsigned long)(t7 + (0));
    v0 = t2 - hi_9c0d0 + (u32)(unsigned long)ref_tisp_tmo_tmo_interplate;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c48c;
L_9c48c:
    v0 = v0 + 32;
    a0 = 64;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    t0 = lo;
    t0 = t0 & 0xff;
    v0 = *(volatile u32 *)(unsigned long)(sp + (88));
L_9c4a4:
    t4 = t4 + 2;
    branch = (t4 != v0); t7 = t7 + 2;
    if (branch) goto L_9c458;
    goto L_9c4b0;
L_9c4b0:
    *(volatile u8 *)(unsigned long)(t8 + (419)) = t0; goto L_9c4c0;
L_9c4b8:
    t0 = (t0 >> 0x6) & ((1U << 0x8) - 1);
    *(volatile u8 *)(unsigned long)(t8 + (419)) = t0;
L_9c4c0:
    a0 = *(volatile u8 *)(unsigned long)(v1 + (10892));
    v0 = *(volatile u8 *)(unsigned long)(v1 + (10891));
    t3 = t3 + 10;
    product = (s64)(s32)a0 * (s32)t9; lo = product; hi = product >> 32;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (10893));
    t3 = t3 & 0xffff;
    t8 = t8 + 1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)t6); lo = product; hi = product >> 32;
    v0 = 230;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)t1); lo = product; hi = product >> 32;
    t1 = lo;
    t1 = t1 + 8;
    t1 = (s32)t1 >> (0x4 & 31);
    branch = (t3 != v0); *(volatile u8 *)(unsigned long)(t8 + (793)) = t1;
    if (branch) goto L_9c0f4;
    goto L_9c4fc;
L_9c4fc:
    t5 = *(volatile u32 *)(unsigned long)(sp + (68));
    v0 = 3250;
    branch = (t5 != v0); s2 = s2 + 25;
    if (branch) goto L_9c0d8;
    goto L_9c50c;
L_9c50c:
    v0 = s0 + 443;
    v1 = s0 + 468;
L_9c514:
    a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(v0 + (-26)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (374));
    *(volatile u8 *)(unsigned long)(v0 + (349)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (299));
    *(volatile u8 *)(unsigned long)(v0 + (324)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (674));
    branch = (v0 != v1); *(volatile u8 *)(unsigned long)(v0 + (699)) = a0;
    if (branch) goto L_9c514;
    goto L_9c53c;
L_9c53c:
    v0 = s0 + 419;
    s0 = s0 + 794;
L_9c544:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = v0 + 25;
    *(volatile u8 *)(unsigned long)(v0 + (-26)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (350));
    *(volatile u8 *)(unsigned long)(v0 + (349)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (-3));
    *(volatile u8 *)(unsigned long)(v0 + (-2)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (372));
    branch = (s0 != v0); *(volatile u8 *)(unsigned long)(v0 + (373)) = v1;
    if (branch) goto L_9c544;
    goto L_9c56c;
L_9c56c:
    ra = *(volatile u32 *)(unsigned long)(sp + (132)); goto L_9c5d8;
L_9c574:
    branch = (v0 != a0); ra = *(volatile u32 *)(unsigned long)(sp + (132));
    if (branch) goto L_9c5d8;
    goto L_9c57c;
L_9c57c:
    s2 = *(volatile u8 *)(unsigned long)(v1 + (10929));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (10930));
    s1 = hi_9c584;
    a0 = s0 + 418;
    s1 = s1 - hi_9c584 + ((u32)(unsigned long)ref_memset + (0));
    callee = s1; a2 = 375;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c598;
L_9c598:
    ra = *(volatile u32 *)(unsigned long)(sp + (132));
    s8 = *(volatile u32 *)(unsigned long)(sp + (128));
    s7 = *(volatile u32 *)(unsigned long)(sp + (124));
    s6 = *(volatile u32 *)(unsigned long)(sp + (120));
    s5 = *(volatile u32 *)(unsigned long)(sp + (116));
    s4 = *(volatile u32 *)(unsigned long)(sp + (112));
    s3 = *(volatile u32 *)(unsigned long)(sp + (108));
    a1 = s2;
    a0 = s0 + 793;
    s2 = *(volatile u32 *)(unsigned long)(sp + (104));
    s0 = *(volatile u32 *)(unsigned long)(sp + (96));
    t9 = s1;
    s1 = *(volatile u32 *)(unsigned long)(sp + (100));
    a2 = 375;
    callee = t9; sp = sp + 136;
    switch (callee) { case 0x9c010: goto L_9c010; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_9c5d8:
    s8 = *(volatile u32 *)(unsigned long)(sp + (128));
    s7 = *(volatile u32 *)(unsigned long)(sp + (124));
    s6 = *(volatile u32 *)(unsigned long)(sp + (120));
    s5 = *(volatile u32 *)(unsigned long)(sp + (116));
    s4 = *(volatile u32 *)(unsigned long)(sp + (112));
    s3 = *(volatile u32 *)(unsigned long)(sp + (108));
    s2 = *(volatile u32 *)(unsigned long)(sp + (104));
    s1 = *(volatile u32 *)(unsigned long)(sp + (100));
    s0 = *(volatile u32 *)(unsigned long)(sp + (96));
    sp = sp + 136;
    return ((u64)v1 << 32) | v0;
}
