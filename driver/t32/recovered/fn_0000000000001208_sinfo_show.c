/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_mutex_lock[] __asm__("mutex_lock");
extern unsigned char ref_mutex_unlock[] __asm__("mutex_unlock");
extern unsigned char ref_t32_data_ce270[] __asm__("t32_data_ce270");
extern unsigned char ref_t32_data_bd550[] __asm__("t32_data_bd550");
extern unsigned char ref_t32_data_c3788[] __asm__("t32_data_c3788");
extern unsigned char ref_t32_data_c378c[] __asm__("t32_data_c378c");
extern unsigned char ref_seq_printf[] __asm__("seq_printf");
extern unsigned char ref_t32_data_c373c[] __asm__("t32_data_c373c");
extern unsigned char ref_t32_data_c3794[] __asm__("t32_data_c3794");
extern unsigned char ref_t32_data_c3778[] __asm__("t32_data_c3778");
extern unsigned char ref_t32_data_c3780[] __asm__("t32_data_c3780");
extern unsigned char ref_t32_data_c3798[] __asm__("t32_data_c3798");
extern unsigned char ref_t32_data_c379c[] __asm__("t32_data_c379c");
extern unsigned char ref_t32_data_c37a0[] __asm__("t32_data_c37a0");
u64 sinfo_show(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_120c = (((u32)(unsigned long)ref_mutex_lock + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_122c = (((u32)(unsigned long)ref_mutex_unlock + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1214 = ((u32)(unsigned long)ref_t32_data_ce270 + 0x8000U) & 0xffff0000U;
    const u32 hi_12a8 = ((u32)(unsigned long)ref_t32_data_bd550 + 0x8000U) & 0xffff0000U;
    const u32 hi_12dc = ((u32)(unsigned long)ref_t32_data_c3788 + 0x8000U) & 0xffff0000U;
    const u32 hi_1300 = ((u32)(unsigned long)ref_t32_data_c378c + 0x8000U) & 0xffff0000U;
    const u32 hi_130c = (((u32)(unsigned long)ref_seq_printf + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_131c = (((u32)(unsigned long)ref_seq_printf + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1320 = ((u32)(unsigned long)ref_t32_data_c378c + 0x8000U) & 0xffff0000U;
    const u32 hi_1350 = (((u32)(unsigned long)ref_seq_printf + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1354 = ((u32)(unsigned long)ref_t32_data_c373c + 0x8000U) & 0xffff0000U;
    const u32 hi_1394 = ((u32)(unsigned long)ref_t32_data_c373c + 0x8000U) & 0xffff0000U;
    const u32 hi_13d0 = ((u32)(unsigned long)ref_t32_data_c3794 + 0x8000U) & 0xffff0000U;
    const u32 hi_13e4 = ((u32)(unsigned long)ref_t32_data_c3778 + 0x8000U) & 0xffff0000U;
    const u32 hi_13e8 = ((u32)(unsigned long)ref_t32_data_c3780 + 0x8000U) & 0xffff0000U;
    const u32 hi_1420 = (((u32)(unsigned long)ref_seq_printf + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_142c = ((u32)(unsigned long)ref_t32_data_c373c + 0x8000U) & 0xffff0000U;
    const u32 hi_1448 = ((u32)(unsigned long)ref_t32_data_c3798 + 0x8000U) & 0xffff0000U;
    const u32 hi_1464 = ((u32)(unsigned long)ref_t32_data_c379c + 0x8000U) & 0xffff0000U;
    const u32 hi_1474 = (((u32)(unsigned long)ref_seq_printf + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_14a0 = ((u32)(unsigned long)ref_t32_data_c37a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_1490 = ((u32)(unsigned long)ref_t32_data_c379c + 0x8000U) & 0xffff0000U;
    const u32 hi_14b8 = ((u32)(unsigned long)ref_t32_data_c37a0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_1208:
    sp = sp + -48;
    v0 = hi_120c;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    s2 = hi_1214;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    v0 = v0 - hi_120c + ((u32)(unsigned long)ref_mutex_lock + (0));
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    s0 = a0;
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    s1 = hi_122c;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s3;
    s1 = s1 - hi_122c + ((u32)(unsigned long)ref_mutex_unlock + (0));
    s4 = *(volatile u32 *)(unsigned long)(a0 + (72));
    a0 = s2 - hi_1214 + (u32)(unsigned long)ref_t32_data_ce270;
    callee = v0; s3 = *(volatile u32 *)(unsigned long)(s4 + (0));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_124c;
L_124c:
    v0 = *(volatile u8 *)(unsigned long)(s3 + (0));
    branch = (v0 != 0); ;
    if (branch) goto L_1284;
    goto L_1258;
L_1258:
    callee = s1; a0 = s2 - hi_1214 + (u32)(unsigned long)ref_t32_data_ce270;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1260;
L_1260:
    v0 = 0;
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s4 = *(volatile u32 *)(unsigned long)(sp + (40));
    s3 = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
L_1284:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (16));
    branch = (v0 == 0); a0 = 0;
    if (branch) goto L_12c0;
    goto L_1290;
L_1290:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (880));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (280));
L_1298:
    a1 = *(volatile u32 *)(unsigned long)(s4 + (4));
    a2 = (u32)a1 < (u32)(15);
    branch = (a2 == 0); a2 = a1 << (0x2 & 31);
    if (branch) goto L_1258;
    goto L_12a8;
L_12a8:
    a1 = hi_12a8;
    a1 = a1 - hi_12a8 + (u32)(unsigned long)ref_t32_data_bd550;
    a1 = a1 + a2;
    a1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    callee = a1; ;
    switch (callee) { case 0x1208: goto L_1208; case 0x12c8: goto L_12c8; case 0x12fc: goto L_12fc; case 0x131c: goto L_131c; case 0x1350: goto L_1350; case 0x1380: goto L_1380; case 0x13a0: goto L_13a0; case 0x13b0: goto L_13b0; case 0x13e4: goto L_13e4; case 0x1400: goto L_1400; case 0x1410: goto L_1410; case 0x1420: goto L_1420; case 0x1460: goto L_1460; case 0x148c: goto L_148c; case 0x149c: goto L_149c; case 0x14b4: goto L_14b4; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_12c0:
    v1 = 0; goto L_1298;
L_12c8:
    branch = (a0 == 0); ;
    if (branch) goto L_12e8;
    goto L_12d0;
L_12d0:
    a2 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (a2 == 0); ;
    if (branch) goto L_12e8;
    goto L_12dc;
L_12dc:
    a1 = hi_12dc;
    a1 = a1 - hi_12dc + (u32)(unsigned long)ref_t32_data_c3788; goto L_130c;
L_12e8:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (4));
    branch = (v0 == 0); ;
    if (branch) goto L_1258;
    goto L_12f4;
L_12f4:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (28)); goto L_12dc;
L_12fc:
    branch = (a0 == 0); a1 = hi_1300;
    if (branch) goto L_1258;
    goto L_1304;
L_1304:
    a2 = *(volatile u32 *)(unsigned long)(a0 + (4));
    a1 = a1 - hi_1300 + (u32)(unsigned long)ref_t32_data_c378c;
L_130c:
    v0 = hi_130c;
    a0 = s0;
    v0 = v0 - hi_130c + ((u32)(unsigned long)ref_seq_printf + (0)); goto L_1338;
L_131c:
    v0 = hi_131c;
    a1 = hi_1320;
    branch = (v1 == 0); v0 = v0 - hi_131c + ((u32)(unsigned long)ref_seq_printf + (0));
    if (branch) goto L_1348;
    goto L_132c;
L_132c:
    a2 = *(volatile u16 *)(unsigned long)(v1 + (2));
L_1330:
    a1 = a1 - hi_1320 + (u32)(unsigned long)ref_t32_data_c378c;
L_1334:
    a0 = s0;
L_1338:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1340;
L_1340:
    ; goto L_1258;
L_1348:
    a2 = *(volatile u16 *)(unsigned long)(s3 + (12)); goto L_1330;
L_1350:
    v0 = hi_1350;
    a1 = hi_1354;
    branch = (v1 == 0); v0 = v0 - hi_1350 + ((u32)(unsigned long)ref_seq_printf + (0));
    if (branch) goto L_1378;
    goto L_1360;
L_1360:
    v1 = *(volatile u32 *)(unsigned long)(v1 + (24));
    branch = (v1 == 0); a2 = 0;
    if (branch) goto L_1370;
    goto L_136c;
L_136c:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (248));
L_1370:
    a1 = a1 - hi_1354 + (u32)(unsigned long)ref_t32_data_c373c; goto L_1334;
L_1378:
    a2 = 0; goto L_1370;
L_1380:
    branch = (v0 == 0); ;
    if (branch) goto L_1258;
    goto L_1388;
L_1388:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (828));
L_138c:
    branch = (a2 == 0); ;
    if (branch) goto L_1258;
    goto L_1394;
L_1394:
    a1 = hi_1394;
    a1 = a1 - hi_1394 + (u32)(unsigned long)ref_t32_data_c373c; goto L_130c;
L_13a0:
    branch = (v0 == 0); ;
    if (branch) goto L_1258;
    goto L_13a8;
L_13a8:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (832)); goto L_138c;
L_13b0:
    branch = (v0 == 0); ;
    if (branch) goto L_1258;
    goto L_13b8;
L_13b8:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (896));
L_13bc:
    branch = (v0 == 0); v1 = v0 >> (0x10 & 31);
    if (branch) goto L_1258;
    goto L_13c4;
L_13c4:
    a0 = 1;
    v0 = v0 & 0xffff;
    if (v0 == 0) v0 = a0;
    a1 = hi_13d0;
    a1 = a1 - hi_13d0 + (u32)(unsigned long)ref_t32_data_c3794;
    if (v0) { lo = v1 / v0; hi = v1 % v0; } else { lo = ~0U; hi = v1; }
    a2 = lo; goto L_130c;
L_13e4:
    a2 = hi_13e4;
    v1 = hi_13e8;
    a2 = a2 - hi_13e4 + (u32)(unsigned long)ref_t32_data_c3778;
    v1 = v1 - hi_13e8 + (u32)(unsigned long)ref_t32_data_c3780;
    if (v0 == 0) a2 = v1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1; goto L_12dc;
L_1400:
    branch = (v0 == 0); ;
    if (branch) goto L_1258;
    goto L_1408;
L_1408:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (900)); goto L_13bc;
L_1410:
    branch = (v0 == 0); ;
    if (branch) goto L_1258;
    goto L_1418;
L_1418:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (904)); goto L_13bc;
L_1420:
    v1 = hi_1420;
    branch = (v0 == 0); v1 = v1 - hi_1420 + ((u32)(unsigned long)ref_seq_printf + (0));
    if (branch) goto L_1448;
    goto L_142c;
L_142c:
    a1 = hi_142c;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (412));
    a0 = s0;
    callee = v1; a1 = a1 - hi_142c + (u32)(unsigned long)ref_t32_data_c373c;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1440;
L_1440:
    ; goto L_1258;
L_1448:
    a1 = hi_1448;
    a0 = s0;
    callee = v1; a1 = a1 - hi_1448 + (u32)(unsigned long)ref_t32_data_c3798;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1458;
L_1458:
    ; goto L_1258;
L_1460:
    branch = (v0 == 0); a1 = hi_1464;
    if (branch) goto L_1470;
    goto L_1468;
L_1468:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (416)); goto L_1394;
L_1470:
    a1 = a1 - hi_1464 + (u32)(unsigned long)ref_t32_data_c379c;
L_1474:
    v0 = hi_1474;
    v0 = v0 - hi_1474 + ((u32)(unsigned long)ref_seq_printf + (0));
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1484;
L_1484:
    ; goto L_1258;
L_148c:
    branch = (v0 == 0); a1 = hi_1490;
    if (branch) goto L_1470;
    goto L_1494;
L_1494:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (408)); goto L_1394;
L_149c:
    branch = (v0 == 0); a1 = hi_14a0;
    if (branch) goto L_14ac;
    goto L_14a4;
L_14a4:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (384)); goto L_1394;
L_14ac:
    a1 = a1 - hi_14a0 + (u32)(unsigned long)ref_t32_data_c37a0; goto L_1474;
L_14b4:
    branch = (v0 == 0); a1 = hi_14b8;
    if (branch) goto L_14ac;
    goto L_14bc;
L_14bc:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (388)); goto L_1394;
}
