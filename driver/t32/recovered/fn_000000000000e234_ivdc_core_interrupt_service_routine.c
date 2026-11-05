/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d992c[] __asm__("t32_data_d992c");
extern unsigned char ref_t32_data_d9930[] __asm__("t32_data_d9930");
extern unsigned char ref_t32_data_d9924[] __asm__("t32_data_d9924");
extern unsigned char ref_t32_data_d9928[] __asm__("t32_data_d9928");
extern unsigned char ref_t32_data_d9920[] __asm__("t32_data_d9920");
extern unsigned char ref_t32_data_d991c[] __asm__("t32_data_d991c");
extern unsigned char ref_t32_data_d9918[] __asm__("t32_data_d9918");
extern unsigned char ref_t32_data_d9914[] __asm__("t32_data_d9914");
extern unsigned char ref_t32_data_d9910[] __asm__("t32_data_d9910");
extern unsigned char ref_t32_data_d990c[] __asm__("t32_data_d990c");
extern unsigned char ref_t32_data_d9908[] __asm__("t32_data_d9908");
extern unsigned char ref_t32_data_d9904[] __asm__("t32_data_d9904");
extern unsigned char ref_t32_data_d9900[] __asm__("t32_data_d9900");
extern unsigned char ref_t32_data_d98fc[] __asm__("t32_data_d98fc");
extern unsigned char ref_t32_data_d98f8[] __asm__("t32_data_d98f8");
extern unsigned char ref_t32_data_d98f4[] __asm__("t32_data_d98f4");
extern unsigned char ref_t32_data_d989c[] __asm__("t32_data_d989c");
extern unsigned char ref_tisp_get_fps[] __asm__("tisp_get_fps");
extern unsigned char ref_lib_tisp_api_get_csccr_output[] __asm__("lib_tisp_api_get_csccr_output");
extern unsigned char ref_tisp_csc_get_full_range[] __asm__("tisp_csc_get_full_range");
extern unsigned char ref_tx_isp_send_event_to_remote[] __asm__("tx_isp_send_event_to_remote");
extern unsigned char ref_t32_data_d98f0[] __asm__("t32_data_d98f0");
extern unsigned char ref_t32_data_d98ec[] __asm__("t32_data_d98ec");
extern unsigned char ref_t32_data_d98e8[] __asm__("t32_data_d98e8");
extern unsigned char ref_t32_data_d98e4[] __asm__("t32_data_d98e4");
extern unsigned char ref_t32_data_d98e0[] __asm__("t32_data_d98e0");
extern unsigned char ref_t32_data_d98dc[] __asm__("t32_data_d98dc");
extern unsigned char ref_t32_data_d98d8[] __asm__("t32_data_d98d8");
extern unsigned char ref_t32_data_d98d4[] __asm__("t32_data_d98d4");
extern unsigned char ref_t32_data_d98d0[] __asm__("t32_data_d98d0");
extern unsigned char ref_t32_data_d98cc[] __asm__("t32_data_d98cc");
extern unsigned char ref_t32_data_d98c8[] __asm__("t32_data_d98c8");
extern unsigned char ref_t32_data_d98c4[] __asm__("t32_data_d98c4");
extern unsigned char ref_t32_data_d98c0[] __asm__("t32_data_d98c0");
extern unsigned char ref_t32_data_d98bc[] __asm__("t32_data_d98bc");
u64 ivdc_core_interrupt_service_routine(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[86] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_e264 = ((u32)(unsigned long)ref_t32_data_d992c + 0x8000U) & 0xffff0000U;
    const u32 hi_e280 = ((u32)(unsigned long)ref_t32_data_d9930 + 0x8000U) & 0xffff0000U;
    const u32 hi_e29c = ((u32)(unsigned long)ref_t32_data_d9924 + 0x8000U) & 0xffff0000U;
    const u32 hi_e2b8 = ((u32)(unsigned long)ref_t32_data_d9928 + 0x8000U) & 0xffff0000U;
    const u32 hi_e2d4 = ((u32)(unsigned long)ref_t32_data_d9920 + 0x8000U) & 0xffff0000U;
    const u32 hi_e2f0 = ((u32)(unsigned long)ref_t32_data_d991c + 0x8000U) & 0xffff0000U;
    const u32 hi_e30c = ((u32)(unsigned long)ref_t32_data_d9918 + 0x8000U) & 0xffff0000U;
    const u32 hi_e328 = ((u32)(unsigned long)ref_t32_data_d9914 + 0x8000U) & 0xffff0000U;
    const u32 hi_e344 = ((u32)(unsigned long)ref_t32_data_d9910 + 0x8000U) & 0xffff0000U;
    const u32 hi_e360 = ((u32)(unsigned long)ref_t32_data_d990c + 0x8000U) & 0xffff0000U;
    const u32 hi_e37c = ((u32)(unsigned long)ref_t32_data_d9908 + 0x8000U) & 0xffff0000U;
    const u32 hi_e398 = ((u32)(unsigned long)ref_t32_data_d9904 + 0x8000U) & 0xffff0000U;
    const u32 hi_e3b4 = ((u32)(unsigned long)ref_t32_data_d9900 + 0x8000U) & 0xffff0000U;
    const u32 hi_e3d0 = ((u32)(unsigned long)ref_t32_data_d98fc + 0x8000U) & 0xffff0000U;
    const u32 hi_e3ec = ((u32)(unsigned long)ref_t32_data_d98f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_e408 = ((u32)(unsigned long)ref_t32_data_d98f4 + 0x8000U) & 0xffff0000U;
    const u32 hi_e43c = ((u32)(unsigned long)ref_t32_data_d989c + 0x8000U) & 0xffff0000U;
    const u32 hi_e454 = ((u32)(unsigned long)ref_tisp_get_fps + 0x8000U) & 0xffff0000U;
    const u32 hi_e46c = ((u32)(unsigned long)ref_lib_tisp_api_get_csccr_output + 0x8000U) & 0xffff0000U;
    const u32 hi_e480 = ((u32)(unsigned long)ref_tisp_csc_get_full_range + 0x8000U) & 0xffff0000U;
    const u32 hi_e4ac = ((u32)(unsigned long)ref_tx_isp_send_event_to_remote + 0x8000U) & 0xffff0000U;
    const u32 hi_e4bc = ((u32)(unsigned long)ref_t32_data_d98f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_e4d8 = ((u32)(unsigned long)ref_t32_data_d98ec + 0x8000U) & 0xffff0000U;
    const u32 hi_e4f4 = ((u32)(unsigned long)ref_t32_data_d98e8 + 0x8000U) & 0xffff0000U;
    const u32 hi_e510 = ((u32)(unsigned long)ref_t32_data_d98e4 + 0x8000U) & 0xffff0000U;
    const u32 hi_e52c = ((u32)(unsigned long)ref_t32_data_d98e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_e548 = ((u32)(unsigned long)ref_t32_data_d98dc + 0x8000U) & 0xffff0000U;
    const u32 hi_e564 = ((u32)(unsigned long)ref_t32_data_d98d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_e580 = ((u32)(unsigned long)ref_t32_data_d98d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_e59c = ((u32)(unsigned long)ref_t32_data_d98d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_e5b8 = ((u32)(unsigned long)ref_t32_data_d98cc + 0x8000U) & 0xffff0000U;
    const u32 hi_e5d4 = ((u32)(unsigned long)ref_t32_data_d98c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_e5f0 = ((u32)(unsigned long)ref_t32_data_d98c4 + 0x8000U) & 0xffff0000U;
    const u32 hi_e608 = ((u32)(unsigned long)ref_t32_data_d98c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_e620 = ((u32)(unsigned long)ref_t32_data_d98bc + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[22];
L_e234:
    sp = sp + -88;
    *(volatile u32 *)(unsigned long)(sp + (84)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (72)) = s0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (280));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (284));
    s0 = *(volatile u32 *)(unsigned long)(v0 + (68));
    *(volatile u32 *)(unsigned long)(v0 + (84)) = s0;
    v0 = s0 & 0x1;
    branch = (v0 == 0); v0 = s0 & 0x2;
    if (branch) goto L_e278;
    goto L_e264;
L_e264:
    a1 = hi_e264;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e264 + (u32)(unsigned long)ref_t32_data_d992c);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e264 + (u32)(unsigned long)ref_t32_data_d992c) = v0;
    v0 = s0 & 0x2;
L_e278:
    branch = (v0 == 0); v0 = s0 & 0x4;
    if (branch) goto L_e294;
    goto L_e280;
L_e280:
    a1 = hi_e280;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e280 + (u32)(unsigned long)ref_t32_data_d9930);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e280 + (u32)(unsigned long)ref_t32_data_d9930) = v0;
    v0 = s0 & 0x4;
L_e294:
    branch = (v0 == 0); v0 = s0 & 0x8;
    if (branch) goto L_e2b0;
    goto L_e29c;
L_e29c:
    a1 = hi_e29c;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e29c + (u32)(unsigned long)ref_t32_data_d9924);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e29c + (u32)(unsigned long)ref_t32_data_d9924) = v0;
    v0 = s0 & 0x8;
L_e2b0:
    branch = (v0 == 0); v0 = s0 & 0x10;
    if (branch) goto L_e2cc;
    goto L_e2b8;
L_e2b8:
    a1 = hi_e2b8;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e2b8 + (u32)(unsigned long)ref_t32_data_d9928);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e2b8 + (u32)(unsigned long)ref_t32_data_d9928) = v0;
    v0 = s0 & 0x10;
L_e2cc:
    branch = (v0 == 0); v0 = s0 & 0x20;
    if (branch) goto L_e2e8;
    goto L_e2d4;
L_e2d4:
    a1 = hi_e2d4;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e2d4 + (u32)(unsigned long)ref_t32_data_d9920);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e2d4 + (u32)(unsigned long)ref_t32_data_d9920) = v0;
    v0 = s0 & 0x20;
L_e2e8:
    branch = (v0 == 0); v0 = s0 & 0x40;
    if (branch) goto L_e304;
    goto L_e2f0;
L_e2f0:
    a1 = hi_e2f0;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e2f0 + (u32)(unsigned long)ref_t32_data_d991c);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e2f0 + (u32)(unsigned long)ref_t32_data_d991c) = v0;
    v0 = s0 & 0x40;
L_e304:
    branch = (v0 == 0); v0 = s0 & 0x80;
    if (branch) goto L_e320;
    goto L_e30c;
L_e30c:
    a1 = hi_e30c;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e30c + (u32)(unsigned long)ref_t32_data_d9918);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e30c + (u32)(unsigned long)ref_t32_data_d9918) = v0;
    v0 = s0 & 0x80;
L_e320:
    branch = (v0 == 0); v0 = s0 & 0x100;
    if (branch) goto L_e33c;
    goto L_e328;
L_e328:
    a1 = hi_e328;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e328 + (u32)(unsigned long)ref_t32_data_d9914);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e328 + (u32)(unsigned long)ref_t32_data_d9914) = v0;
    v0 = s0 & 0x100;
L_e33c:
    branch = (v0 == 0); v0 = s0 & 0x200;
    if (branch) goto L_e358;
    goto L_e344;
L_e344:
    a1 = hi_e344;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e344 + (u32)(unsigned long)ref_t32_data_d9910);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e344 + (u32)(unsigned long)ref_t32_data_d9910) = v0;
    v0 = s0 & 0x200;
L_e358:
    branch = (v0 == 0); v0 = s0 & 0x800;
    if (branch) goto L_e374;
    goto L_e360;
L_e360:
    a1 = hi_e360;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e360 + (u32)(unsigned long)ref_t32_data_d990c);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e360 + (u32)(unsigned long)ref_t32_data_d990c) = v0;
    v0 = s0 & 0x800;
L_e374:
    branch = (v0 == 0); v0 = s0 & 0x1000;
    if (branch) goto L_e390;
    goto L_e37c;
L_e37c:
    a1 = hi_e37c;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e37c + (u32)(unsigned long)ref_t32_data_d9908);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e37c + (u32)(unsigned long)ref_t32_data_d9908) = v0;
    v0 = s0 & 0x1000;
L_e390:
    branch = (v0 == 0); v0 = s0 & 0x2000;
    if (branch) goto L_e3ac;
    goto L_e398;
L_e398:
    a1 = hi_e398;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e398 + (u32)(unsigned long)ref_t32_data_d9904);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e398 + (u32)(unsigned long)ref_t32_data_d9904) = v0;
    v0 = s0 & 0x2000;
L_e3ac:
    branch = (v0 == 0); v0 = s0 & 0x4000;
    if (branch) goto L_e3c8;
    goto L_e3b4;
L_e3b4:
    a1 = hi_e3b4;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e3b4 + (u32)(unsigned long)ref_t32_data_d9900);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e3b4 + (u32)(unsigned long)ref_t32_data_d9900) = v0;
    v0 = s0 & 0x4000;
L_e3c8:
    branch = (v0 == 0); v0 = s0 & 0x8000;
    if (branch) goto L_e3e4;
    goto L_e3d0;
L_e3d0:
    a1 = hi_e3d0;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e3d0 + (u32)(unsigned long)ref_t32_data_d98fc);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e3d0 + (u32)(unsigned long)ref_t32_data_d98fc) = v0;
    v0 = s0 & 0x8000;
L_e3e4:
    branch = (v0 == 0); v0 = (s0 >> 0x10) & ((1U << 0x1) - 1);
    if (branch) goto L_e400;
    goto L_e3ec;
L_e3ec:
    a1 = hi_e3ec;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e3ec + (u32)(unsigned long)ref_t32_data_d98f8);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e3ec + (u32)(unsigned long)ref_t32_data_d98f8) = v0;
    v0 = (s0 >> 0x10) & ((1U << 0x1) - 1);
L_e400:
    branch = (v0 == 0); v0 = (s0 >> 0x11) & ((1U << 0x1) - 1);
    if (branch) goto L_e41c;
    goto L_e408;
L_e408:
    a1 = hi_e408;
    v0 = *(volatile u32 *)(unsigned long)(a1 - hi_e408 + (u32)(unsigned long)ref_t32_data_d98f4);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 - hi_e408 + (u32)(unsigned long)ref_t32_data_d98f4) = v0;
    v0 = (s0 >> 0x11) & ((1U << 0x1) - 1);
L_e41c:
    branch = (v0 == 0); v0 = (s0 >> 0x12) & ((1U << 0x1) - 1);
    if (branch) goto L_e4d0;
    goto L_e424;
L_e424:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (284));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (240));
    v0 = 0x8000U << 16;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = 0x8100U << 16;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = hi_e43c;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_e43c + (u32)(unsigned long)ref_t32_data_d989c);
    branch = (v0 == 0); s1 = s1 & 0x7;
    if (branch) goto L_e454;
    goto L_e44c;
L_e44c:
    v0 = 8;
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
L_e454:
    v0 = hi_e454;
L_e458:
    a1 = sp + 40;
    s2 = a0;
    v0 = v0 - hi_e454 + (u32)(unsigned long)ref_tisp_get_fps;
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e46c;
L_e46c:
    v0 = hi_e46c;
    v0 = v0 - hi_e46c + (u32)(unsigned long)ref_lib_tisp_api_get_csccr_output;
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e47c;
L_e47c:
    *(volatile u32 *)(unsigned long)(sp + (44)) = v0;
    v0 = hi_e480;
    v0 = v0 - hi_e480 + (u32)(unsigned long)ref_tisp_csc_get_full_range;
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e490;
L_e490:
    a0 = 36;
    v1 = s1 * a0;
    *(volatile u32 *)(unsigned long)(sp + (64)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s2 + (272));
    a1 = 0x300U << 16;
    a2 = sp + 16;
    a0 = v1 + v0;
    v0 = hi_e4ac;
    v0 = v0 - hi_e4ac + (u32)(unsigned long)ref_tx_isp_send_event_to_remote;
    callee = v0; a1 = a1 + 6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e4bc;
L_e4bc:
    v1 = hi_e4bc;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e4bc + (u32)(unsigned long)ref_t32_data_d98f0);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e4bc + (u32)(unsigned long)ref_t32_data_d98f0) = v0;
    v0 = (s0 >> 0x12) & ((1U << 0x1) - 1);
L_e4d0:
    branch = (v0 == 0); v0 = (s0 >> 0x13) & ((1U << 0x1) - 1);
    if (branch) goto L_e4ec;
    goto L_e4d8;
L_e4d8:
    v1 = hi_e4d8;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e4d8 + (u32)(unsigned long)ref_t32_data_d98ec);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e4d8 + (u32)(unsigned long)ref_t32_data_d98ec) = v0;
    v0 = (s0 >> 0x13) & ((1U << 0x1) - 1);
L_e4ec:
    branch = (v0 == 0); v0 = (s0 >> 0x14) & ((1U << 0x1) - 1);
    if (branch) goto L_e508;
    goto L_e4f4;
L_e4f4:
    v1 = hi_e4f4;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e4f4 + (u32)(unsigned long)ref_t32_data_d98e8);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e4f4 + (u32)(unsigned long)ref_t32_data_d98e8) = v0;
    v0 = (s0 >> 0x14) & ((1U << 0x1) - 1);
L_e508:
    branch = (v0 == 0); v0 = (s0 >> 0x15) & ((1U << 0x1) - 1);
    if (branch) goto L_e524;
    goto L_e510;
L_e510:
    v1 = hi_e510;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e510 + (u32)(unsigned long)ref_t32_data_d98e4);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e510 + (u32)(unsigned long)ref_t32_data_d98e4) = v0;
    v0 = (s0 >> 0x15) & ((1U << 0x1) - 1);
L_e524:
    branch = (v0 == 0); v0 = (s0 >> 0x17) & ((1U << 0x1) - 1);
    if (branch) goto L_e540;
    goto L_e52c;
L_e52c:
    v1 = hi_e52c;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e52c + (u32)(unsigned long)ref_t32_data_d98e0);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e52c + (u32)(unsigned long)ref_t32_data_d98e0) = v0;
    v0 = (s0 >> 0x17) & ((1U << 0x1) - 1);
L_e540:
    branch = (v0 == 0); v0 = (s0 >> 0x18) & ((1U << 0x1) - 1);
    if (branch) goto L_e55c;
    goto L_e548;
L_e548:
    v1 = hi_e548;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e548 + (u32)(unsigned long)ref_t32_data_d98dc);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e548 + (u32)(unsigned long)ref_t32_data_d98dc) = v0;
    v0 = (s0 >> 0x18) & ((1U << 0x1) - 1);
L_e55c:
    branch = (v0 == 0); v0 = (s0 >> 0x19) & ((1U << 0x1) - 1);
    if (branch) goto L_e578;
    goto L_e564;
L_e564:
    v1 = hi_e564;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e564 + (u32)(unsigned long)ref_t32_data_d98d8);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e564 + (u32)(unsigned long)ref_t32_data_d98d8) = v0;
    v0 = (s0 >> 0x19) & ((1U << 0x1) - 1);
L_e578:
    branch = (v0 == 0); v0 = (s0 >> 0x1a) & ((1U << 0x1) - 1);
    if (branch) goto L_e594;
    goto L_e580;
L_e580:
    v1 = hi_e580;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e580 + (u32)(unsigned long)ref_t32_data_d98d4);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e580 + (u32)(unsigned long)ref_t32_data_d98d4) = v0;
    v0 = (s0 >> 0x1a) & ((1U << 0x1) - 1);
L_e594:
    branch = (v0 == 0); v0 = (s0 >> 0x1b) & ((1U << 0x1) - 1);
    if (branch) goto L_e5b0;
    goto L_e59c;
L_e59c:
    v1 = hi_e59c;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e59c + (u32)(unsigned long)ref_t32_data_d98d0);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e59c + (u32)(unsigned long)ref_t32_data_d98d0) = v0;
    v0 = (s0 >> 0x1b) & ((1U << 0x1) - 1);
L_e5b0:
    branch = (v0 == 0); v0 = (s0 >> 0x1c) & ((1U << 0x1) - 1);
    if (branch) goto L_e5cc;
    goto L_e5b8;
L_e5b8:
    v1 = hi_e5b8;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e5b8 + (u32)(unsigned long)ref_t32_data_d98cc);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e5b8 + (u32)(unsigned long)ref_t32_data_d98cc) = v0;
    v0 = (s0 >> 0x1c) & ((1U << 0x1) - 1);
L_e5cc:
    branch = (v0 == 0); v0 = (s0 >> 0x1d) & ((1U << 0x1) - 1);
    if (branch) goto L_e5e8;
    goto L_e5d4;
L_e5d4:
    v1 = hi_e5d4;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e5d4 + (u32)(unsigned long)ref_t32_data_d98c8);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e5d4 + (u32)(unsigned long)ref_t32_data_d98c8) = v0;
    v0 = (s0 >> 0x1d) & ((1U << 0x1) - 1);
L_e5e8:
    branch = (v0 == 0); v0 = (s0 >> 0x1e) & ((1U << 0x1) - 1);
    if (branch) goto L_e604;
    goto L_e5f0;
L_e5f0:
    v1 = hi_e5f0;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e5f0 + (u32)(unsigned long)ref_t32_data_d98c4);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e5f0 + (u32)(unsigned long)ref_t32_data_d98c4) = v0;
    v0 = (s0 >> 0x1e) & ((1U << 0x1) - 1);
L_e604:
    branch = (v0 == 0); v1 = hi_e608;
    if (branch) goto L_e618;
    goto L_e60c;
L_e60c:
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e608 + (u32)(unsigned long)ref_t32_data_d98c0);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e608 + (u32)(unsigned long)ref_t32_data_d98c0) = v0;
L_e618:
    branch = ((s32)s0 >= 0); ra = *(volatile u32 *)(unsigned long)(sp + (84));
    if (branch) goto L_e634;
    goto L_e620;
L_e620:
    v1 = hi_e620;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_e620 + (u32)(unsigned long)ref_t32_data_d98bc);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e620 + (u32)(unsigned long)ref_t32_data_d98bc) = v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (84));
L_e634:
    s2 = *(volatile u32 *)(unsigned long)(sp + (80));
L_e638:
    s1 = *(volatile u32 *)(unsigned long)(sp + (76));
    s0 = *(volatile u32 *)(unsigned long)(sp + (72));
    v0 = 1;
    sp = sp + 88;
    return ((u64)v1 << 32) | v0;
}
