/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_f3310[] __asm__("t32_data_f3310");
extern unsigned char ref_t32_data_c3100[] __asm__("t32_data_c3100");
extern unsigned char ref_tx_isp_core_shvflip[] __asm__("tx_isp_core_shvflip");
extern unsigned char ref_ispcore_sensor_ops_ioctl[] __asm__("ispcore_sensor_ops_ioctl");
u64 ispcore_irq_fd_work3(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b54d0 = ((u32)(unsigned long)ref_t32_data_f3310 + 0x8000U) & 0xffff0000U;
    const u32 hi_b5544 = ((u32)(unsigned long)ref_t32_data_c3100 + 0x8000U) & 0xffff0000U;
    const u32 hi_b555c = ((u32)(unsigned long)ref_tx_isp_core_shvflip + 0x8000U) & 0xffff0000U;
    const u32 hi_b5554 = ((u32)(unsigned long)ref_ispcore_sensor_ops_ioctl + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
L_b54d0:
    v0 = hi_b54d0;
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_b54d0 + (u32)(unsigned long)ref_t32_data_f3310);
    sp = sp + -64;
    v1 = 3;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (60)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s0;
    s1 = *(volatile u32 *)(unsigned long)(a0 + (280));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    branch = (a0 == 0); s2 = v0;
    if (branch) goto L_b5540;
    goto L_b5518;
L_b5518:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (264));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    branch = (v0 == 0); ;
    if (branch) goto L_b5540;
    goto L_b5528;
L_b5528:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    branch = (v0 == 0); a2 = sp + 16;
    if (branch) goto L_b5540;
    goto L_b5534;
L_b5534:
    a1 = 0x200U << 16;
    callee = v0; a1 = a1 + 22;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b5540;
L_b5540:
    branch = (s1 == 0); s3 = hi_b5544;
    if (branch) goto L_b5648;
    goto L_b5548;
L_b5548:
    s7 = s1 + 1592;
    s0 = 0;
    s6 = 0;
    s4 = hi_b5554;
    s3 = s3 - hi_b5544 + (u32)(unsigned long)ref_t32_data_c3100;
    s5 = hi_b555c;
L_b5560:
    v0 = *(volatile u32 *)(unsigned long)(s7 + (0));
    branch = (v0 == 0); v0 = s6 + 1;
    if (branch) goto L_b5618;
    goto L_b556c;
L_b556c:
    v0 = (u32)s6 < (u32)(7);
    branch = (v0 == 0); v0 = s6 << (0x2 & 31);
    if (branch) goto L_b55c0;
    goto L_b5578;
L_b5578:
    v0 = s3 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    callee = v0; ;
    switch (callee) { case 0xb54d0: goto L_b54d0; case 0xb5588: goto L_b5588; case 0xb5594: goto L_b5594; case 0xb55a0: goto L_b55a0; case 0xb55ac: goto L_b55ac; case 0xb55d4: goto L_b55d4; case 0xb5630: goto L_b5630; case 0xb563c: goto L_b563c; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_b5588:
    s0 = 0x200U << 16;
    s0 = s0 + 9; goto L_b55dc;
L_b5594:
    s0 = 0x200U << 16;
    s0 = s0 + 6; goto L_b55dc;
L_b55a0:
    s0 = 0x200U << 16;
    s0 = s0 + 23; goto L_b55dc;
L_b55ac:
    v0 = s5 - hi_b555c + (u32)(unsigned long)ref_tx_isp_core_shvflip;
    callee = v0; a0 = 3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b55b8;
L_b55b8:
    v0 = s6 + 1; goto L_b5618;
L_b55c0:
    v0 = 5;
    if (s6 != v0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (688)); goto L_b55e0; }
    goto L_b55cc;
L_b55cc:
    v0 = s6 + 1; goto L_b5618;
L_b55d4:
    s0 = 0x200U << 16;
    s0 = s0 + 7;
L_b55dc:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (688));
L_b55e0:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (256));
    branch = (v0 != 0); v0 = s6 + 1;
    if (branch) goto L_b5618;
    goto L_b55ec;
L_b55ec:
    v0 = *(volatile u32 *)(unsigned long)(s7 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s2 - hi_b54d0 + (u32)(unsigned long)ref_t32_data_f3310);
    v1 = 3;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    a2 = sp + 16;
    a1 = s0;
    v0 = s4 - hi_b5554 + (u32)(unsigned long)ref_ispcore_sensor_ops_ioctl;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b5610;
L_b5610:
    *(volatile u32 *)(unsigned long)(s7 + (0)) = 0;
    v0 = s6 + 1;
L_b5618:
    s6 = v0 & 0xff;
    v0 = 12;
    branch = (s6 != v0); s7 = s7 + 8;
    if (branch) goto L_b5560;
    goto L_b5628;
L_b5628:
    ra = *(volatile u32 *)(unsigned long)(sp + (60)); goto L_b564c;
L_b5630:
    s0 = 0x200U << 16;
    s0 = s0 + 8; goto L_b55dc;
L_b563c:
    s0 = 0x200U << 16;
    s0 = s0 + 5; goto L_b55dc;
L_b5648:
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
L_b564c:
    s7 = *(volatile u32 *)(unsigned long)(sp + (56));
    s6 = *(volatile u32 *)(unsigned long)(sp + (52));
    s5 = *(volatile u32 *)(unsigned long)(sp + (48));
    s4 = *(volatile u32 *)(unsigned long)(sp + (44));
    s3 = *(volatile u32 *)(unsigned long)(sp + (40));
    s2 = *(volatile u32 *)(unsigned long)(sp + (36));
    s1 = *(volatile u32 *)(unsigned long)(sp + (32));
    s0 = *(volatile u32 *)(unsigned long)(sp + (28));
    sp = sp + 64;
    return ((u64)v1 << 32) | v0;
}
