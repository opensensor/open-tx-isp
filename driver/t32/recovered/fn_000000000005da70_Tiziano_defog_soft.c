/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref___ashrdi3[] __asm__("__ashrdi3");
extern unsigned char ref_tisp_defog_max_filter[] __asm__("tisp_defog_max_filter");
extern unsigned char ref_tisp_defog_img_filter9[] __asm__("tisp_defog_img_filter9");
extern unsigned char ref_tisp_defog_img_filter25[] __asm__("tisp_defog_img_filter25");
extern unsigned char ref_memcpy[] __asm__("memcpy");
u64 Tiziano_defog_soft(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[266] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_5db38 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_5dc78 = (((u32)(unsigned long)ref___ashrdi3 + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_5e428 = ((u32)(unsigned long)ref_tisp_defog_max_filter + 0x8000U) & 0xffff0000U;
    const u32 hi_5e440 = ((u32)(unsigned long)ref_tisp_defog_img_filter9 + 0x8000U) & 0xffff0000U;
    const u32 hi_5e494 = ((u32)(unsigned long)ref_tisp_defog_img_filter25 + 0x8000U) & 0xffff0000U;
    const u32 hi_5e4e4 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[202];
L_5da70:
    sp = sp + -808;
    v0 = a0 + 720;
    *(volatile u32 *)(unsigned long)(sp + (620)) = v0;
    v0 = a0 + 1440;
    *(volatile u32 *)(unsigned long)(sp + (624)) = v0;
    v0 = a0 + 2184;
    *(volatile u32 *)(unsigned long)(sp + (628)) = v0;
    v0 = a0 + 2364;
    *(volatile u32 *)(unsigned long)(sp + (804)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (800)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (796)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (784)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (780)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (772)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (768)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (792)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (788)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (776)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (560)) = v0;
    v0 = a0 + 2381;
    *(volatile u32 *)(unsigned long)(sp + (632)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2455));
    t7 = a0 + 3178;
    t2 = a0 + 3434;
    *(volatile u32 *)(unsigned long)(sp + (636)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2456));
    a3 = *(volatile u32 *)(unsigned long)(a0 + (2176));
    s5 = *(volatile u32 *)(unsigned long)(a0 + (2180));
    *(volatile u32 *)(unsigned long)(sp + (640)) = v0;
    v0 = a0 + 2638;
    *(volatile u32 *)(unsigned long)(sp + (568)) = v0;
    v0 = a0 + 2818;
    *(volatile u32 *)(unsigned long)(sp + (572)) = v0;
    v0 = a0 + 2998;
    *(volatile u32 *)(unsigned long)(sp + (588)) = v0;
    v0 = a0 + 3690;
    *(volatile u32 *)(unsigned long)(sp + (644)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2415));
    s2 = *(volatile u8 *)(unsigned long)(a0 + (2457));
    *(volatile u32 *)(unsigned long)(sp + (700)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (648)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2416));
    *(volatile u32 *)(unsigned long)(sp + (684)) = t2;
    s1 = sp + 16;
    *(volatile u32 *)(unsigned long)(sp + (592)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2420));
    s4 = *(volatile u8 *)(unsigned long)(a0 + (2417));
    *(volatile u32 *)(unsigned long)(sp + (584)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (652)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2421));
    s3 = hi_5db38;
    a2 = 360;
    v0 = v0 << (0x4 & 31);
    *(volatile u32 *)(unsigned long)(sp + (596)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2422));
    a1 = 0;
    s3 = s3 - hi_5db38 + ((u32)(unsigned long)ref_memset + (0));
    v0 = v0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (576)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2423));
    v1 = *(volatile u32 *)(unsigned long)(sp + (576));
    s0 = a0;
    v0 = v0 << (0x6 & 31);
    *(volatile u32 *)(unsigned long)(sp + (600)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2424));
    s8 = a0 + 2390;
    s7 = a0 + 2458;
    *(volatile u32 *)(unsigned long)(sp + (656)) = v0;
    v0 = 31;
    v0 = v0 - s2;
    *(volatile u32 *)(unsigned long)(sp + (580)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (2418));
    a0 = s1;
    v0 = v0 - s4;
    *(volatile u32 *)(unsigned long)(sp + (564)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (600));
    v0 = v0 - v1;
    *(volatile u32 *)(unsigned long)(sp + (660)) = v0;
    v1 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v0 = *(volatile u8 *)(unsigned long)(a3 + (1));
    v1 = v0 - v1;
    *(volatile u32 *)(unsigned long)(sp + (604)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a3 + (2));
    v0 = v1 - v0;
    *(volatile u32 *)(unsigned long)(sp + (608)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a3 + (3));
    v1 = v0 - v1;
    *(volatile u32 *)(unsigned long)(sp + (612)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a3 + (4));
    v0 = v1 - v0;
    *(volatile u32 *)(unsigned long)(sp + (616)) = v0;
    v1 = *(volatile u8 *)(unsigned long)(s5 + (0));
    v0 = *(volatile u8 *)(unsigned long)(s5 + (1));
    v1 = v0 - v1;
    *(volatile u32 *)(unsigned long)(sp + (664)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(s5 + (2));
    v0 = v1 - v0;
    *(volatile u32 *)(unsigned long)(sp + (668)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s5 + (3));
    v1 = v0 - v1;
    *(volatile u32 *)(unsigned long)(sp + (672)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(s5 + (4));
    v0 = v1 - v0;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (676)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5dc14;
L_5dc14:
    a2 = 180;
    a1 = 0;
    callee = s3; a0 = sp + 376;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5dc24;
L_5dc24:
    v0 = *(volatile u32 *)(unsigned long)(sp + (604));
    a3 = *(volatile u32 *)(unsigned long)(sp + (584));
    t2 = *(volatile u32 *)(unsigned long)(sp + (684));
    v0 = (s32)v0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(sp + (680)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (608));
    t7 = *(volatile u32 *)(unsigned long)(sp + (700));
    t9 = s4 << (0x10 & 31);
    v0 = (s32)v0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(sp + (688)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (612));
    t3 = 0;
    *(volatile u32 *)(unsigned long)(sp + (720)) = s1;
    v0 = (s32)v0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(sp + (692)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (616));
    v0 = (s32)v0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(sp + (696)) = v0;
    v0 = 30;
    v0 = v0 - s2;
    *(volatile u32 *)(unsigned long)(sp + (712)) = v0;
    v0 = hi_5dc78;
    *(volatile u32 *)(unsigned long)(sp + (716)) = v0;
    v0 = 18;
L_5dc84:
    s1 = t3 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (628));
    t4 = 0;
    t8 = v0 + s1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (588));
    t0 = v0 + s1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (572));
    t6 = v0 + s1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (568));
    t5 = v0 + s1;
    v0 = 72;
    v0 = t3 * v0;
    s1 = s7 + s1;
    *(volatile u32 *)(unsigned long)(sp + (700)) = v0;
    v0 = 36;
    v0 = t3 * v0;
    *(volatile u32 *)(unsigned long)(sp + (684)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (636));
    v0 = (s32)t3 < (s32)(v0);
    *(volatile u32 *)(unsigned long)(sp + (708)) = v0;
L_5dcd4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (640));
    v1 = *(volatile u32 *)(unsigned long)(sp + (708));
    branch = (v1 == 0); v0 = (s32)t4 < (s32)(v0);
    if (branch) goto L_5dcf4;
    goto L_5dce4;
L_5dce4:
    if (v0 == 0) { s4 = *(volatile u32 *)(unsigned long)(s0 + (2164)); goto L_5dd00; }
    goto L_5dcec;
L_5dcec:
    s4 = *(volatile u32 *)(unsigned long)(s0 + (2160)); goto L_5dd00;
L_5dcf4:
    if (v0 == 0) { s4 = *(volatile u32 *)(unsigned long)(s0 + (2172)); goto L_5dd00; }
    goto L_5dcfc;
L_5dcfc:
    s4 = *(volatile u32 *)(unsigned long)(s0 + (2168));
L_5dd00:
    v0 = (s32)s4 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(sp + (704)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (712));
    t1 = t4 << (0x2 & 31);
    v1 = (s32)s4 >> (0x1f & 31);
    s6 = (s32)s4 >> (v0 & 31);
    v0 = *(volatile u32 *)(unsigned long)(sp + (700));
    *(volatile u32 *)(unsigned long)(sp + (764)) = t6;
    *(volatile u32 *)(unsigned long)(sp + (760)) = t5;
    t1 = t1 + v0;
    v0 = s0 + t1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (756)) = t8;
    *(volatile u32 *)(unsigned long)(sp + (752)) = t0;
    product = (u64)(u32)v0 * (u32)s4; lo = product; hi = product >> 32;
    *(volatile u32 *)(unsigned long)(sp + (748)) = t9;
    *(volatile u32 *)(unsigned long)(sp + (744)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (740)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (736)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (732)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (728)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (724)) = t1;
    s6 = s6 & 0x1;
    a0 = lo;
    a1 = hi;
    a2 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (716));
    v0 = v0 - hi_5dc78 + ((u32)(unsigned long)ref___ashrdi3 + (0));
    *(volatile u32 *)(unsigned long)(sp + (584)) = v0;
    a1 = a2 + a1;
    callee = v0; a2 = *(volatile u32 *)(unsigned long)(sp + (580));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5dd80;
L_5dd80:
    v0 = s6 + v0;
    s3 = (s32)v0 < (s32)(256);
    v1 = 255;
    t1 = *(volatile u32 *)(unsigned long)(sp + (724));
    if (s3 != 0) v1 = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (620));
    s3 = v1;
    v1 = (s32)s4 >> (0x1f & 31);
    v0 = v0 + t1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    product = (u64)(u32)v0 * (u32)s4; lo = product; hi = product >> 32;
    a0 = lo;
    a1 = hi;
    a2 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (584));
    a1 = a2 + a1;
    callee = v0; a2 = *(volatile u32 *)(unsigned long)(sp + (580));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5ddc8;
L_5ddc8:
    v0 = s6 + v0;
    s2 = (s32)v0 < (s32)(256);
    v1 = 255;
    if (s2 != 0) v1 = v0;
    t1 = *(volatile u32 *)(unsigned long)(sp + (724));
    v0 = *(volatile u32 *)(unsigned long)(sp + (624));
    s2 = v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (704));
    t1 = v0 + t1;
    v0 = *(volatile u32 *)(unsigned long)(t1 + (0));
    product = (u64)(u32)v0 * (u32)s4; lo = product; hi = product >> 32;
    a0 = lo;
    a1 = hi;
    a2 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (584));
    a1 = a2 + a1;
    callee = v0; a2 = *(volatile u32 *)(unsigned long)(sp + (580));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5de10;
L_5de10:
    v0 = s6 + v0;
    s6 = (s32)v0 < (s32)(256);
    v1 = 255;
    if (s6 != 0) v1 = v0;
    v0 = 38;
    product = (s64)(s32)s2 * (s32)v0; lo = product; hi = product >> 32;
    v0 = 19;
    s6 = v1;
    a0 = 255;
    t4 = *(volatile u32 *)(unsigned long)(sp + (728));
    t8 = *(volatile u32 *)(unsigned long)(sp + (756));
    a3 = *(volatile u32 *)(unsigned long)(sp + (732));
    t7 = *(volatile u32 *)(unsigned long)(sp + (736));
    t2 = *(volatile u32 *)(unsigned long)(sp + (740));
    t3 = *(volatile u32 *)(unsigned long)(sp + (744));
    t9 = *(volatile u32 *)(unsigned long)(sp + (748));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s3 * (s32)v0); lo = product; hi = product >> 32;
    v0 = s6 << (0x3 & 31);
    v0 = v0 - s6;
    v1 = lo;
    v1 = v1 + v0;
    v0 = (s32)v1 >> (0x6 & 31);
    v1 = (s32)v0 < (s32)(256);
    if (v1 != 0) a0 = v0;
    v1 = a0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (684));
    v0 = t4 << (0x1 & 31);
    v0 = v0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (720));
    v0 = a0 + v0;
    a0 = *(volatile u8 *)(unsigned long)(t8 + (0));
    *(volatile u8 *)(unsigned long)(t8 + (0)) = v1;
    a0 = v1 - a0;
    *(volatile u16 *)(unsigned long)(v0 + (0)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (648));
    t0 = *(volatile u32 *)(unsigned long)(sp + (752));
    t5 = *(volatile u32 *)(unsigned long)(sp + (760));
    branch = (v0 != 0); t6 = *(volatile u32 *)(unsigned long)(sp + (764));
    if (branch) goto L_5e1f0;
    goto L_5deac;
L_5deac:
    v0 = *(volatile u32 *)(unsigned long)(sp + (592));
    branch = (v0 != 0); a0 = t7 + v1;
    if (branch) goto L_5e030;
    goto L_5deb8;
L_5deb8:
    a1 = t7 + s3;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v0 = v0 & 0x1;
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (560));
    if (branch) goto L_5dedc;
    goto L_5decc;
L_5decc:
    s3 = t2 + s3;
    v0 = *(volatile u8 *)(unsigned long)(s3 + (0));
    *(volatile u8 *)(unsigned long)(s1 + (0)) = v0; goto L_5df38;
L_5dedc:
    a0 = (s32)s3 >> (0x4 & 31);
    a2 = s3 & 0xf;
    a0 = v0 + a0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (1));
    s3 = t2 + s3;
    a0 = a0 - v0;
    a0 = a0 * a2;
    a0 = a0 + 8;
    a0 = (s32)a0 >> (0x4 & 31);
    v0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (564));
    v0 = v0 * a0;
    v0 = v0 + 127;
    a0 = v0 << (0x8 & 31);
    a0 = v0 + a0;
    a0 = a0 + t9;
    a0 = (a0 >> 0x10) & ((1U << 0x8) - 1);
    *(volatile u8 *)(unsigned long)(s3 + (0)) = a0;
    *(volatile u8 *)(unsigned long)(s1 + (0)) = a0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(a1 + (0)) = v0;
L_5df38:
    a0 = t7 + s2;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (0));
    v0 = v0 & 0x1;
    branch = (v0 == 0); a1 = *(volatile u32 *)(unsigned long)(sp + (560));
    if (branch) goto L_5df5c;
    goto L_5df4c;
L_5df4c:
    s2 = t2 + s2;
    v0 = *(volatile u8 *)(unsigned long)(s2 + (0));
    *(volatile u8 *)(unsigned long)(t5 + (0)) = v0; goto L_5dfb8;
L_5df5c:
    v0 = (s32)s2 >> (0x4 & 31);
    a2 = s2 & 0xf;
    v0 = a1 + v0;
    a1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (1));
    s2 = t2 + s2;
    v0 = v0 - a1;
    v0 = v0 * a2;
    v0 = v0 + 8;
    v0 = (s32)v0 >> (0x4 & 31);
    a1 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (564));
    a1 = a1 * v0;
    a1 = a1 + 127;
    v0 = a1 << (0x8 & 31);
    a1 = a1 + v0;
    a1 = t9 + a1;
    a1 = (a1 >> 0x10) & ((1U << 0x8) - 1);
    *(volatile u8 *)(unsigned long)(s2 + (0)) = a1;
    *(volatile u8 *)(unsigned long)(t5 + (0)) = a1;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (0));
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(a0 + (0)) = v0;
L_5dfb8:
    a0 = t7 + s6;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (0));
    v0 = v0 & 0x1;
    if (v0 == 0) { a1 = *(volatile u32 *)(unsigned long)(sp + (560)); goto L_5dfdc; }
    goto L_5dfcc;
L_5dfcc:
    s6 = t2 + s6;
    v0 = *(volatile u8 *)(unsigned long)(s6 + (0));
    *(volatile u8 *)(unsigned long)(t6 + (0)) = v0; goto L_5e0bc;
L_5dfdc:
    v0 = (s32)s6 >> (0x4 & 31);
    a2 = s6 & 0xf;
    v0 = a1 + v0;
    a1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (1));
    s6 = t2 + s6;
    v0 = v0 - a1;
    v0 = v0 * a2;
    v0 = v0 + 8;
    v0 = (s32)v0 >> (0x4 & 31);
    a1 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (564));
    a1 = a1 * v0;
    a1 = a1 + 127;
    v0 = a1 << (0x8 & 31);
    a1 = a1 + v0;
    a1 = t9 + a1;
    a1 = (a1 >> 0x10) & ((1U << 0x8) - 1);
    *(volatile u8 *)(unsigned long)(s6 + (0)) = a1;
    *(volatile u8 *)(unsigned long)(t6 + (0)) = a1; goto L_5e0b0;
L_5e030:
    v0 = *(volatile u8 *)(unsigned long)(a0 + (0));
    v0 = v0 & 0x1;
    if (v0 == 0) { a1 = *(volatile u32 *)(unsigned long)(sp + (560)); goto L_5e058; }
    goto L_5e040;
L_5e040:
    v0 = t2 + v1;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    *(volatile u8 *)(unsigned long)(t6 + (0)) = v0;
    *(volatile u8 *)(unsigned long)(t5 + (0)) = v0;
    *(volatile u8 *)(unsigned long)(s1 + (0)) = v0; goto L_5e0bc;
L_5e058:
    v0 = (s32)v1 >> (0x4 & 31);
    a2 = v1 & 0xf;
    v0 = a1 + v0;
    a1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (1));
    v0 = v0 - a1;
    v0 = v0 * a2;
    v0 = v0 + 8;
    v0 = (s32)v0 >> (0x4 & 31);
    v0 = v0 + a1;
    a1 = *(volatile u32 *)(unsigned long)(sp + (564));
    v0 = v0 * a1;
    v0 = v0 + 127;
    a1 = v0 << (0x8 & 31);
    v0 = v0 + a1;
    v0 = t9 + v0;
    v0 = (v0 >> 0x10) & ((1U << 0x8) - 1);
    a1 = t2 + v1;
    *(volatile u8 *)(unsigned long)(a1 + (0)) = v0;
    *(volatile u8 *)(unsigned long)(s1 + (0)) = v0;
    *(volatile u8 *)(unsigned long)(t5 + (0)) = v0;
    *(volatile u8 *)(unsigned long)(t6 + (0)) = v0;
L_5e0b0:
    v0 = *(volatile u8 *)(unsigned long)(a0 + (0));
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(a0 + (0)) = v0;
L_5e0bc:
    a2 = t7 + v1;
    v0 = *(volatile u8 *)(unsigned long)(a2 + (0));
    a0 = *(volatile u32 *)(unsigned long)(sp + (644));
    v0 = v0 & 0x10;
    branch = (v0 == 0); a1 = a0 + v1;
    if (branch) goto L_5e0e0;
    goto L_5e0d4;
L_5e0d4:
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v0; goto L_5e1f0;
L_5e0e0:
    v0 = *(volatile u8 *)(unsigned long)(a3 + (0));
    a0 = (s32)v1 < (s32)(v0);
    if (a0 == 0) { a0 = *(volatile u8 *)(unsigned long)(a3 + (1)); goto L_5e0f8; }
    goto L_5e0f0;
L_5e0f0:
    v0 = *(volatile u8 *)(unsigned long)(s5 + (0)); goto L_5e1dc;
L_5e0f8:
    t1 = (s32)v1 < (s32)(a0);
    if (t1 == 0) { v0 = *(volatile u8 *)(unsigned long)(a3 + (2)); goto L_5e12c; }
    goto L_5e104;
L_5e104:
    v1 = v1 - v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (664));
    a0 = *(volatile u32 *)(unsigned long)(sp + (680));
    t1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (604));
    v1 = t1 + a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = *(volatile u8 *)(unsigned long)(s5 + (0));
    v1 = lo; goto L_5e190;
L_5e12c:
    t1 = (s32)v1 < (s32)(v0);
    if (t1 == 0) { a0 = *(volatile u8 *)(unsigned long)(a3 + (3)); goto L_5e160; }
    goto L_5e138;
L_5e138:
    v0 = *(volatile u32 *)(unsigned long)(sp + (668));
    v1 = v1 - a0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (688));
    t1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (608));
    v1 = t1 + a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u8 *)(unsigned long)(s5 + (1));
    v1 = lo; goto L_5e1c8;
L_5e160:
    t1 = (s32)v1 < (s32)(a0);
    if (t1 == 0) { v0 = *(volatile u8 *)(unsigned long)(a3 + (4)); goto L_5e198; }
    goto L_5e16c;
L_5e16c:
    v1 = v1 - v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (672));
    a0 = *(volatile u32 *)(unsigned long)(sp + (692));
    t1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (612));
    v1 = t1 + a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = *(volatile u8 *)(unsigned long)(s5 + (2));
    v1 = lo;
L_5e190:
    v1 = v0 + v1; goto L_5e1cc;
L_5e198:
    v0 = (s32)v1 < (s32)(v0);
    if (v0 == 0) { v0 = *(volatile u8 *)(unsigned long)(s5 + (4)); goto L_5e1dc; }
    goto L_5e1a4;
L_5e1a4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (676));
    v1 = v1 - a0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (696));
    t1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (616));
    v1 = t1 + a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u8 *)(unsigned long)(s5 + (3));
    v1 = lo;
L_5e1c8:
    v1 = a0 + v1;
L_5e1cc:
    v1 = v1 & 0xff;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1;
    *(volatile u8 *)(unsigned long)(a1 + (0)) = v1; goto L_5e1e4;
L_5e1dc:
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v0;
    *(volatile u8 *)(unsigned long)(a1 + (0)) = v0;
L_5e1e4:
    v0 = *(volatile u8 *)(unsigned long)(a2 + (0));
    v0 = v0 + 16;
    *(volatile u8 *)(unsigned long)(a2 + (0)) = v0;
L_5e1f0:
    t4 = t4 + 1;
    v0 = 18;
    t8 = t8 + 1;
    t0 = t0 + 1;
    t6 = t6 + 1;
    t5 = t5 + 1;
    branch = (t4 != v0); s1 = s1 + 1;
    if (branch) goto L_5dcd4;
    goto L_5e210;
L_5e210:
    t3 = t3 + 1;
    v0 = 10;
    branch = (t3 != v0); v0 = 18;
    if (branch) goto L_5dc84;
    goto L_5e220;
L_5e220:
    v1 = *(volatile u32 *)(unsigned long)(sp + (652));
    v0 = 1;
    branch = (v1 == v0); v1 = *(volatile u32 *)(unsigned long)(sp + (656));
    if (branch) goto L_5e244;
    goto L_5e230;
L_5e230:
    v0 = 1;
    branch = (v1 != v0); ra = *(volatile u32 *)(unsigned long)(sp + (804));
    if (branch) goto L_5e50c;
    goto L_5e23c;
L_5e23c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (592)); goto L_5e494;
L_5e244:
    a0 = 0;
    t1 = 18;
    s3 = -1;
    s2 = 10;
    v0 = (s32)a0 < (s32)(3);
L_5e258:
    branch = (v0 != 0); v0 = (s32)a0 < (s32)(7);
    if (branch) goto L_5e274;
    goto L_5e260;
L_5e260:
    a2 = a0 + -2;
    branch = (v0 != 0); t4 = 9;
    if (branch) goto L_5e278;
    goto L_5e26c;
L_5e26c:
    v1 = a0 * t1; goto L_5e280;
L_5e274:
    a2 = 0;
L_5e278:
    t4 = a0 + 2;
    v1 = a0 * t1;
L_5e280:
    s1 = t4 - a2;
    v0 = sp + 376;
    s1 = s1 + 1;
    a1 = 0;
    s4 = a2 * t1;
    t2 = v1 + v0;
L_5e298:
    v0 = (s32)a1 < (s32)(3);
    branch = (v0 != 0); v0 = (s32)a1 < (s32)(15);
    if (branch) goto L_5e2b8;
    goto L_5e2a4;
L_5e2a4:
    a3 = a1 + -2;
    branch = (v0 != 0); t6 = 17;
    if (branch) goto L_5e2bc;
    goto L_5e2b0;
L_5e2b0:
    v0 = t6 - a3; goto L_5e2c4;
L_5e2b8:
    a3 = 0;
L_5e2bc:
    t6 = a1 + 2;
    v0 = t6 - a3;
L_5e2c4:
    v0 = v0 + 1;
    v0 = v0 * s1;
    t5 = s4 + a3;
    t8 = a2;
    t0 = 0;
    v1 = 0;
    s5 = t5 - a3;
L_5e2e0:
    t3 = (s32)t4 < (s32)(t8);
    branch = (t3 != 0); t3 = t8 - a2;
    if (branch) goto L_5e33c;
    goto L_5e2ec;
L_5e2ec:
    t7 = t3 * t1;
    t3 = t7 + s5;
    t3 = t3 << (0x1 & 31);
    t7 = a3;
L_5e2fc:
    t9 = (s32)t6 < (s32)(t7);
    branch = (t9 != 0); t9 = t7 << (0x1 & 31);
    if (branch) goto L_5e334;
    goto L_5e308;
L_5e308:
    t9 = t9 + t3;
    ra = sp + 16;
    t9 = ra + t9;
    t9 = *(volatile s16 *)(unsigned long)(t9 + (0));
    t7 = t7 + 1;
    s6 = v1 + t9;
    t0 = t0 + t9;
    v1 = v1 - t9;
    t9 = (s32)t9 < (s32)(1);
    if (t9 == 0) v1 = s6; goto L_5e2fc;
L_5e334:
    t8 = t8 + 1; goto L_5e2e0;
L_5e33c:
    if (t0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)t0 / (s32)v0; hi = (s32)t0 % (s32)v0; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    v1 = v1 << (0x6 & 31);
    t9 = a2;
    t3 = 0;
    t5 = t5 - a3;
    t0 = lo;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
L_5e35c:
    t7 = (s32)t4 < (s32)(t9);
    branch = (t7 != 0); t7 = t9 - a2;
    if (branch) goto L_5e3ac;
    goto L_5e368;
L_5e368:
    t8 = t7 * t1;
    t7 = t8 + t5;
    t7 = t7 << (0x1 & 31);
    t8 = a3;
L_5e378:
    s5 = (s32)t6 < (s32)(t8);
    branch = (s5 != 0); ra = sp + 16;
    if (branch) goto L_5e3a4;
    goto L_5e384;
L_5e384:
    t3 = t8 << (0x1 & 31);
    t3 = t3 + t7;
    t3 = ra + t3;
    t3 = *(volatile s16 *)(unsigned long)(t3 + (0));
    t8 = t8 + 1;
    t3 = t3 - t0;
    t3 = t3 * t3; goto L_5e378;
L_5e3a4:
    t9 = t9 + 1; goto L_5e35c;
L_5e3ac:
    if (t3 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)t3 / (s32)v0; hi = (s32)t3 % (s32)v0; } else { lo = (s32)t3 < 0 ? 1 : ~0U; hi = t3; }
    a3 = *(volatile u32 *)(unsigned long)(sp + (596));
    v0 = lo;
    v0 = v0 + a3;
    v1 = v0 * v1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (600));
    if (v1 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)v1 / (s32)a3; hi = (s32)v1 % (s32)a3; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    v0 = (s32)v0 < (s32)(v1);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (576));
    if (branch) goto L_5e3e0;
    goto L_5e3d8;
L_5e3d8:
    *(volatile u8 *)(unsigned long)(t2 + (0)) = s3; goto L_5e40c;
L_5e3e0:
    v0 = (s32)v1 < (s32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (576));
    if (branch) goto L_5e3f4;
    goto L_5e3ec;
L_5e3ec:
    *(volatile u8 *)(unsigned long)(t2 + (0)) = 0; goto L_5e40c;
L_5e3f4:
    v1 = v1 - v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (660));
    v1 = v1 << (0x8 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    *(volatile u8 *)(unsigned long)(t2 + (0)) = v1;
L_5e40c:
    a1 = a1 + 1;
    branch = (a1 != t1); t2 = t2 + 1;
    if (branch) goto L_5e298;
    goto L_5e418;
L_5e418:
    a0 = a0 + 1;
    branch = (a0 != s2); v0 = (s32)a0 < (s32)(3);
    if (branch) goto L_5e258;
    goto L_5e424;
L_5e424:
    a1 = sp + 376;
    v0 = hi_5e428;
    v0 = v0 - hi_5e428 + (u32)(unsigned long)ref_tisp_defog_max_filter;
    callee = v0; a0 = a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5e438;
L_5e438:
    a2 = *(volatile u32 *)(unsigned long)(sp + (632));
    a1 = sp + 376;
    v0 = hi_5e440;
    v0 = v0 - hi_5e440 + (u32)(unsigned long)ref_tisp_defog_img_filter9;
    callee = v0; a0 = a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5e450;
L_5e450:
    v1 = *(volatile u32 *)(unsigned long)(sp + (588));
    v0 = sp + 376;
    s0 = s0 + 3178;
    a1 = 256;
L_5e460:
    a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    if (a0 == 0) { v1 = v1 + 1; goto L_5e484; }
    goto L_5e46c;
L_5e46c:
    a2 = *(volatile u8 *)(unsigned long)(v1 + (0));
    a0 = a1 - a0;
    a0 = a0 * a2;
    a0 = (s32)a0 >> (0x8 & 31);
    *(volatile u8 *)(unsigned long)(v1 + (0)) = a0;
    v1 = v1 + 1;
L_5e484:
    branch = (s0 != v1); v0 = v0 + 1;
    if (branch) goto L_5e460;
    goto L_5e48c;
L_5e48c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (656)); goto L_5e230;
L_5e494:
    s0 = hi_5e494;
    s0 = s0 - hi_5e494 + (u32)(unsigned long)ref_tisp_defog_img_filter25;
    a2 = s8;
    branch = (v0 != 0); a1 = s7;
    if (branch) goto L_5e4d8;
    goto L_5e4a8;
L_5e4a8:
    callee = s0; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5e4b0;
L_5e4b0:
    a1 = *(volatile u32 *)(unsigned long)(sp + (568));
    a2 = s8;
    callee = s0; a0 = a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5e4c0;
L_5e4c0:
    a1 = *(volatile u32 *)(unsigned long)(sp + (572));
    a2 = s8;
    callee = s0; a0 = a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5e4d0;
L_5e4d0:
    ra = *(volatile u32 *)(unsigned long)(sp + (804)); goto L_5e50c;
L_5e4d8:
    callee = s0; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5e4e0;
L_5e4e0:
    a0 = *(volatile u32 *)(unsigned long)(sp + (568));
    s0 = hi_5e4e4;
    a2 = 180;
    s0 = s0 - hi_5e4e4 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = s0; a1 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5e4f8;
L_5e4f8:
    a0 = *(volatile u32 *)(unsigned long)(sp + (572));
    a2 = 180;
    callee = s0; a1 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5e508;
L_5e508:
    ra = *(volatile u32 *)(unsigned long)(sp + (804));
L_5e50c:
    s8 = *(volatile u32 *)(unsigned long)(sp + (800));
    s7 = *(volatile u32 *)(unsigned long)(sp + (796));
    s6 = *(volatile u32 *)(unsigned long)(sp + (792));
    s5 = *(volatile u32 *)(unsigned long)(sp + (788));
    s4 = *(volatile u32 *)(unsigned long)(sp + (784));
    s3 = *(volatile u32 *)(unsigned long)(sp + (780));
    s2 = *(volatile u32 *)(unsigned long)(sp + (776));
    s1 = *(volatile u32 *)(unsigned long)(sp + (772));
    s0 = *(volatile u32 *)(unsigned long)(sp + (768));
    sp = sp + 808;
    return ((u64)v1 << 32) | v0;
}
