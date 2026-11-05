/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d9694[] __asm__("t32_data_d9694");
extern unsigned char ref_t32_data_d9698[] __asm__("t32_data_d9698");
extern unsigned char ref_t32_data_d9690[] __asm__("t32_data_d9690");
extern unsigned char ref_t32_data_cf134[] __asm__("t32_data_cf134");
extern unsigned char ref_prepare_to_wait_event[] __asm__("prepare_to_wait_event");
extern unsigned char ref_finish_wait[] __asm__("finish_wait");
extern unsigned char ref_schedule_timeout[] __asm__("schedule_timeout");
extern unsigned char ref_t32_data_cf12c[] __asm__("t32_data_cf12c");
extern unsigned char ref_t32_data_d969c[] __asm__("t32_data_d969c");
u64 isp_frame_done_wait(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[82] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b210 = ((u32)(unsigned long)ref_t32_data_d9694 + 0x8000U) & 0xffff0000U;
    const u32 hi_b22c = ((u32)(unsigned long)ref_t32_data_d9698 + 0x8000U) & 0xffff0000U;
    const u32 hi_b238 = ((u32)(unsigned long)ref_t32_data_d9690 + 0x8000U) & 0xffff0000U;
    const u32 hi_b254 = ((u32)(unsigned long)ref_t32_data_d9698 + 0x8000U) & 0xffff0000U;
    const u32 hi_b26c = ((u32)(unsigned long)ref_t32_data_cf134 + 0x8000U) & 0xffff0000U;
    const u32 hi_b280 = (((u32)(unsigned long)ref_prepare_to_wait_event + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b2b0 = ((u32)(unsigned long)ref_t32_data_cf134 + 0x8000U) & 0xffff0000U;
    const u32 hi_b2bc = (((u32)(unsigned long)ref_finish_wait + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b2cc = ((u32)(unsigned long)ref_t32_data_d9698 + 0x8000U) & 0xffff0000U;
    const u32 hi_b284 = (((u32)(unsigned long)ref_schedule_timeout + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b334 = ((u32)(unsigned long)ref_t32_data_cf12c + 0x8000U) & 0xffff0000U;
    const u32 hi_b348 = (((u32)(unsigned long)ref_prepare_to_wait_event + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b378 = ((u32)(unsigned long)ref_t32_data_cf12c + 0x8000U) & 0xffff0000U;
    const u32 hi_b34c = (((u32)(unsigned long)ref_schedule_timeout + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b308 = ((u32)(unsigned long)ref_t32_data_cf134 + 0x8000U) & 0xffff0000U;
    const u32 hi_b38c = ((u32)(unsigned long)ref_t32_data_cf12c + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[18];
L_b1dc:
    sp = sp + -72;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (68)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s2;
    s1 = a0;
    s0 = a1;
    branch = (a0 != 0); s3 = a2;
    if (branch) goto L_b238;
    goto L_b210;
L_b210:
    v0 = hi_b210;
    *(volatile u32 *)(unsigned long)(v0 - hi_b210 + (u32)(unsigned long)ref_t32_data_d9694) = 0;
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_b210 + (u32)(unsigned long)ref_t32_data_d9694);
    v1 = 1;
    branch = (a0 != v1); s4 = v0;
    if (branch) goto L_b260;
    goto L_b228;
L_b228:
    branch = (a1 == 0); v0 = hi_b22c;
    if (branch) goto L_b3ac;
    goto L_b230;
L_b230:
    v0 = v0 - hi_b22c + (u32)(unsigned long)ref_t32_data_d9698; goto L_b2d4;
L_b238:
    v0 = hi_b238;
    *(volatile u32 *)(unsigned long)(v0 - hi_b238 + (u32)(unsigned long)ref_t32_data_d9690) = 0;
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_b238 + (u32)(unsigned long)ref_t32_data_d9690);
    v1 = 1;
    branch = (a0 != v1); s2 = v0;
    if (branch) goto L_b328;
    goto L_b250;
L_b250:
    branch = (a1 == 0); v0 = hi_b254;
    if (branch) goto L_b3b8;
    goto L_b258;
L_b258:
    v0 = v0 - hi_b254 + (u32)(unsigned long)ref_t32_data_d9698; goto L_b2d4;
L_b260:
    if (a1 == 0) { s0 = 0; goto L_b2cc; }
    goto L_b268;
L_b268:
    v0 = sp + 28;
    s2 = hi_b26c;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    s2 = s2 - hi_b26c + (u32)(unsigned long)ref_t32_data_cf134;
    s5 = hi_b280;
    s6 = hi_b284;
L_b288:
    a0 = s2;
    a2 = 1;
    v0 = s5 - hi_b280 + ((u32)(unsigned long)ref_prepare_to_wait_event + (0));
    callee = v0; a1 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b29c;
L_b29c:
    v1 = *(volatile u32 *)(unsigned long)(s4 - hi_b210 + (u32)(unsigned long)ref_t32_data_d9694);
    a0 = 1;
    branch = (v1 != a0); ;
    if (branch) goto L_b304;
    goto L_b2ac;
L_b2ac:
    if (s0 == 0) s0 = v1;
    a0 = hi_b2b0;
L_b2b4:
    a1 = sp + 16;
    a0 = a0 - hi_b2b0 + (u32)(unsigned long)ref_t32_data_cf134;
L_b2bc:
    v0 = hi_b2bc;
    v0 = v0 - hi_b2bc + ((u32)(unsigned long)ref_finish_wait + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b2cc;
L_b2cc:
    v0 = hi_b2cc;
    v0 = v0 - hi_b2cc + (u32)(unsigned long)ref_t32_data_d9698;
L_b2d4:
    s1 = s1 << (0x3 & 31);
    s1 = s1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    *(volatile u32 *)(unsigned long)(s3 + (4)) = v1;
    v1 = -512;
    *(volatile u32 *)(unsigned long)(s3 + (0)) = v0;
    branch = (s0 == v1); v0 = -512;
    if (branch) goto L_b3d8;
    goto L_b2f8;
L_b2f8:
    v0 = -145;
    if (s0 != 0) v0 = 0; goto L_b3d8;
L_b304:
    branch = (s0 == 0); a0 = hi_b308;
    if (branch) goto L_b2b4;
    goto L_b30c;
L_b30c:
    if (v0 != 0) { s0 = v0; goto L_b2b4; }
    goto L_b314;
L_b314:
    v0 = s6 - hi_b284 + ((u32)(unsigned long)ref_schedule_timeout + (0));
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b320;
L_b320:
    s0 = v0; goto L_b288;
L_b328:
    if (a1 == 0) { s0 = 0; goto L_b2cc; }
    goto L_b330;
L_b330:
    v0 = sp + 28;
    s4 = hi_b334;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    s4 = s4 - hi_b334 + (u32)(unsigned long)ref_t32_data_cf12c;
    s5 = hi_b348;
    s6 = hi_b34c;
L_b350:
    a0 = s4;
    a2 = 1;
    v0 = s5 - hi_b348 + ((u32)(unsigned long)ref_prepare_to_wait_event + (0));
    callee = v0; a1 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b364;
L_b364:
    v1 = *(volatile u32 *)(unsigned long)(s2 - hi_b238 + (u32)(unsigned long)ref_t32_data_d9690);
    a0 = 1;
    branch = (v1 != a0); ;
    if (branch) goto L_b388;
    goto L_b374;
L_b374:
    if (s0 == 0) s0 = v1;
L_b378:
    a0 = hi_b378;
L_b37c:
    a1 = sp + 16;
    a0 = a0 - hi_b378 + (u32)(unsigned long)ref_t32_data_cf12c; goto L_b2bc;
L_b388:
    branch = (s0 == 0); a0 = hi_b38c;
    if (branch) goto L_b37c;
    goto L_b390;
L_b390:
    if (v0 != 0) { s0 = v0; goto L_b378; }
    goto L_b398;
L_b398:
    v0 = s6 - hi_b34c + ((u32)(unsigned long)ref_schedule_timeout + (0));
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b3a4;
L_b3a4:
    s0 = v0; goto L_b350;
L_b3ac:
    v1 = *(volatile u32 *)(unsigned long)(v0 - hi_b2cc + (u32)(unsigned long)ref_t32_data_d969c);
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_b2cc + (u32)(unsigned long)ref_t32_data_d9698); goto L_b3cc;
L_b3b8:
    v0 = v0 - hi_b2cc + (u32)(unsigned long)ref_t32_data_d9698;
    s1 = s1 << (0x3 & 31);
    s1 = s1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s1 + (4));
L_b3cc:
    *(volatile u32 *)(unsigned long)(s3 + (0)) = v0;
    *(volatile u32 *)(unsigned long)(s3 + (4)) = v1;
    v0 = 0;
L_b3d8:
    ra = *(volatile u32 *)(unsigned long)(sp + (68));
    s6 = *(volatile u32 *)(unsigned long)(sp + (64));
    s5 = *(volatile u32 *)(unsigned long)(sp + (60));
    s4 = *(volatile u32 *)(unsigned long)(sp + (56));
    s3 = *(volatile u32 *)(unsigned long)(sp + (52));
    s2 = *(volatile u32 *)(unsigned long)(sp + (48));
    s1 = *(volatile u32 *)(unsigned long)(sp + (44));
    s0 = *(volatile u32 *)(unsigned long)(sp + (40));
    sp = sp + 72;
    return ((u64)v1 << 32) | v0;
}
