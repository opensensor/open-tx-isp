/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_private_seq_printf[] __asm__("private_seq_printf");
extern unsigned char ref_t32_data_cc43c[] __asm__("t32_data_cc43c");
extern unsigned char ref_t32_data_cc460[] __asm__("t32_data_cc460");
extern unsigned char ref_t32_data_cc47c[] __asm__("t32_data_cc47c");
extern unsigned char ref_t32_data_cc3b0[] __asm__("t32_data_cc3b0");
extern unsigned char ref_t32_data_cc3e0[] __asm__("t32_data_cc3e0");
extern unsigned char ref_t32_data_cc328[] __asm__("t32_data_cc328");
extern unsigned char ref_t32_data_cc338[] __asm__("t32_data_cc338");
extern unsigned char ref_t32_data_cc340[] __asm__("t32_data_cc340");
extern unsigned char ref_t32_data_cc348[] __asm__("t32_data_cc348");
extern unsigned char ref_t32_data_cc350[] __asm__("t32_data_cc350");
extern unsigned char ref_t32_data_cc358[] __asm__("t32_data_cc358");
extern unsigned char ref_t32_data_cc360[] __asm__("t32_data_cc360");
extern unsigned char ref_t32_data_cc368[] __asm__("t32_data_cc368");
extern unsigned char ref_t32_data_cc370[] __asm__("t32_data_cc370");
extern unsigned char ref_t32_data_cc378[] __asm__("t32_data_cc378");
extern unsigned char ref_t32_data_cc380[] __asm__("t32_data_cc380");
extern unsigned char ref_t32_data_cc388[] __asm__("t32_data_cc388");
extern unsigned char ref_t32_data_cc390[] __asm__("t32_data_cc390");
extern unsigned char ref_t32_data_cc398[] __asm__("t32_data_cc398");
extern unsigned char ref_t32_data_cc3a0[] __asm__("t32_data_cc3a0");
extern unsigned char ref_t32_data_cc3a8[] __asm__("t32_data_cc3a8");
extern unsigned char ref_t32_data_cc3bc[] __asm__("t32_data_cc3bc");
extern unsigned char ref_t32_data_cc3c8[] __asm__("t32_data_cc3c8");
extern unsigned char ref_t32_data_cc3d4[] __asm__("t32_data_cc3d4");
extern unsigned char ref_t32_data_cc3ec[] __asm__("t32_data_cc3ec");
extern unsigned char ref_t32_data_cc3f8[] __asm__("t32_data_cc3f8");
extern unsigned char ref_t32_data_cc404[] __asm__("t32_data_cc404");
extern unsigned char ref_t32_data_cc410[] __asm__("t32_data_cc410");
extern unsigned char ref_t32_data_cc330[] __asm__("t32_data_cc330");
extern unsigned char ref_t32_data_cc498[] __asm__("t32_data_cc498");
extern unsigned char ref_t32_data_cc4ac[] __asm__("t32_data_cc4ac");
extern unsigned char ref_t32_data_cc4c8[] __asm__("t32_data_cc4c8");
extern unsigned char ref_t32_data_cc4e4[] __asm__("t32_data_cc4e4");
extern unsigned char ref_t32_data_cc504[] __asm__("t32_data_cc504");
extern unsigned char ref_t32_data_cc520[] __asm__("t32_data_cc520");
extern unsigned char ref_t32_data_cc534[] __asm__("t32_data_cc534");
extern unsigned char ref_t32_data_cc548[] __asm__("t32_data_cc548");
extern unsigned char ref_t32_data_cc55c[] __asm__("t32_data_cc55c");
extern unsigned char ref_t32_data_cc580[] __asm__("t32_data_cc580");
u64 isp_info_sensor(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b4184 = ((u32)(unsigned long)ref_private_seq_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_b4180 = ((u32)(unsigned long)ref_t32_data_cc43c + 0x8000U) & 0xffff0000U;
    const u32 hi_b41b0 = ((u32)(unsigned long)ref_t32_data_cc460 + 0x8000U) & 0xffff0000U;
    const u32 hi_b41e0 = ((u32)(unsigned long)ref_t32_data_cc47c + 0x8000U) & 0xffff0000U;
    const u32 hi_b4254 = ((u32)(unsigned long)ref_t32_data_cc3b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_b427c = ((u32)(unsigned long)ref_t32_data_cc3e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4518 = ((u32)(unsigned long)ref_t32_data_cc328 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4524 = ((u32)(unsigned long)ref_t32_data_cc338 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4530 = ((u32)(unsigned long)ref_t32_data_cc340 + 0x8000U) & 0xffff0000U;
    const u32 hi_b453c = ((u32)(unsigned long)ref_t32_data_cc348 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4548 = ((u32)(unsigned long)ref_t32_data_cc350 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4554 = ((u32)(unsigned long)ref_t32_data_cc358 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4560 = ((u32)(unsigned long)ref_t32_data_cc360 + 0x8000U) & 0xffff0000U;
    const u32 hi_b456c = ((u32)(unsigned long)ref_t32_data_cc368 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4578 = ((u32)(unsigned long)ref_t32_data_cc370 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4584 = ((u32)(unsigned long)ref_t32_data_cc378 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4590 = ((u32)(unsigned long)ref_t32_data_cc380 + 0x8000U) & 0xffff0000U;
    const u32 hi_b459c = ((u32)(unsigned long)ref_t32_data_cc388 + 0x8000U) & 0xffff0000U;
    const u32 hi_b45a8 = ((u32)(unsigned long)ref_t32_data_cc390 + 0x8000U) & 0xffff0000U;
    const u32 hi_b45b4 = ((u32)(unsigned long)ref_t32_data_cc398 + 0x8000U) & 0xffff0000U;
    const u32 hi_b45c0 = ((u32)(unsigned long)ref_t32_data_cc3a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_b45cc = ((u32)(unsigned long)ref_t32_data_cc3a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b45d8 = ((u32)(unsigned long)ref_t32_data_cc3bc + 0x8000U) & 0xffff0000U;
    const u32 hi_b45e4 = ((u32)(unsigned long)ref_t32_data_cc3c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b45f0 = ((u32)(unsigned long)ref_t32_data_cc3d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_b45fc = ((u32)(unsigned long)ref_t32_data_cc3ec + 0x8000U) & 0xffff0000U;
    const u32 hi_b4608 = ((u32)(unsigned long)ref_t32_data_cc3f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4614 = ((u32)(unsigned long)ref_t32_data_cc404 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4514 = ((u32)(unsigned long)ref_t32_data_cc410 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4628 = ((u32)(unsigned long)ref_t32_data_cc330 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4634 = ((u32)(unsigned long)ref_t32_data_cc498 + 0x8000U) & 0xffff0000U;
    const u32 hi_b464c = ((u32)(unsigned long)ref_t32_data_cc4ac + 0x8000U) & 0xffff0000U;
    const u32 hi_b4660 = ((u32)(unsigned long)ref_t32_data_cc4c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4674 = ((u32)(unsigned long)ref_t32_data_cc4e4 + 0x8000U) & 0xffff0000U;
    const u32 hi_b468c = ((u32)(unsigned long)ref_t32_data_cc504 + 0x8000U) & 0xffff0000U;
    const u32 hi_b46a4 = ((u32)(unsigned long)ref_t32_data_cc520 + 0x8000U) & 0xffff0000U;
    const u32 hi_b46bc = ((u32)(unsigned long)ref_t32_data_cc534 + 0x8000U) & 0xffff0000U;
    const u32 hi_b46d4 = ((u32)(unsigned long)ref_t32_data_cc548 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4704 = ((u32)(unsigned long)ref_t32_data_cc55c + 0x8000U) & 0xffff0000U;
    const u32 hi_b472c = ((u32)(unsigned long)ref_t32_data_cc580 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4250 = ((u32)(unsigned long)ref_t32_data_cc410 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4278 = ((u32)(unsigned long)ref_t32_data_cc410 + 0x8000U) & 0xffff0000U;
    const u32 hi_b42b4 = ((u32)(unsigned long)ref_t32_data_cc328 + 0x8000U) & 0xffff0000U;
    const u32 hi_b42bc = ((u32)(unsigned long)ref_t32_data_cc410 + 0x8000U) & 0xffff0000U;
    const u32 hi_b431c = ((u32)(unsigned long)ref_t32_data_cc340 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4324 = ((u32)(unsigned long)ref_t32_data_cc410 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4338 = ((u32)(unsigned long)ref_t32_data_cc340 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4340 = ((u32)(unsigned long)ref_t32_data_cc348 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4364 = ((u32)(unsigned long)ref_t32_data_cc358 + 0x8000U) & 0xffff0000U;
    const u32 hi_b436c = ((u32)(unsigned long)ref_t32_data_cc368 + 0x8000U) & 0xffff0000U;
    const u32 hi_b438c = ((u32)(unsigned long)ref_t32_data_cc390 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4394 = ((u32)(unsigned long)ref_t32_data_cc410 + 0x8000U) & 0xffff0000U;
    const u32 hi_b43e0 = ((u32)(unsigned long)ref_t32_data_cc3a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_b43e8 = ((u32)(unsigned long)ref_t32_data_cc340 + 0x8000U) & 0xffff0000U;
    const u32 hi_b43fc = ((u32)(unsigned long)ref_t32_data_cc340 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4404 = ((u32)(unsigned long)ref_t32_data_cc350 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4428 = ((u32)(unsigned long)ref_t32_data_cc360 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4430 = ((u32)(unsigned long)ref_t32_data_cc370 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4450 = ((u32)(unsigned long)ref_t32_data_cc398 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4458 = ((u32)(unsigned long)ref_t32_data_cc410 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4490 = ((u32)(unsigned long)ref_t32_data_cc3a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b4498 = ((u32)(unsigned long)ref_t32_data_cc340 + 0x8000U) & 0xffff0000U;
    const u32 hi_b44b8 = ((u32)(unsigned long)ref_t32_data_cc360 + 0x8000U) & 0xffff0000U;
    const u32 hi_b44c0 = ((u32)(unsigned long)ref_t32_data_cc410 + 0x8000U) & 0xffff0000U;
    const u32 hi_b44e4 = ((u32)(unsigned long)ref_t32_data_cc370 + 0x8000U) & 0xffff0000U;
    const u32 hi_b44ec = ((u32)(unsigned long)ref_t32_data_cc380 + 0x8000U) & 0xffff0000U;
    const u32 hi_b450c = ((u32)(unsigned long)ref_t32_data_cc3a8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_b4120:
    sp = sp + -56;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (72));
    s1 = a0;
    branch = (v0 == 0); a2 = a1;
    if (branch) goto L_b4174;
    goto L_b4150;
L_b4150:
    v1 = (u32)v0 < (u32)(-4095);
    branch = (v1 == 0); s3 = 104;
    if (branch) goto L_b4174;
    goto L_b415c;
L_b415c:
    s0 = *(volatile u32 *)(unsigned long)(v0 + (280));
    v0 = a1 * s3;
    s3 = v0 + s0;
    s3 = s3 + 324;
    s4 = s3; goto L_b4180;
L_b4174:
    s3 = 0;
    s0 = 0;
    s4 = 0;
L_b4180:
    a1 = hi_b4180;
    s5 = hi_b4184;
    s5 = s5 - hi_b4184 + (u32)(unsigned long)ref_private_seq_printf;
    a1 = a1 - hi_b4180 + (u32)(unsigned long)ref_t32_data_cc43c;
    a0 = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = a2;
    callee = s5; s2 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b41a0;
L_b41a0:
    branch = (s3 == 0); a2 = *(volatile u32 *)(unsigned long)(sp + (16));
    if (branch) goto L_b41b0;
    goto L_b41a8;
L_b41a8:
    if (s4 != 0) { v0 = a2 + 74; goto L_b41c8; }
    goto L_b41b0;
L_b41b0:
    a1 = hi_b41b0;
    a1 = a1 - hi_b41b0 + (u32)(unsigned long)ref_t32_data_cc460;
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b41c0;
L_b41c0:
    v0 = -1; goto L_b4744;
L_b41c8:
    v0 = v0 << (0x2 & 31);
    s0 = s0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (4));
    v0 = (s32)v0 < (s32)(4);
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s4 + (8)); goto L_b41f8; }
    goto L_b41e0;
L_b41e0:
    a1 = hi_b41e0;
    a1 = a1 - hi_b41e0 + (u32)(unsigned long)ref_t32_data_cc47c;
    callee = s5; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b41f0;
L_b41f0:
    v0 = -1; goto L_b4744;
L_b41f8:
    v1 = 21261;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21262);
    if (branch) goto L_b45b4;
    goto L_b4204;
L_b4204:
    branch = (v1 == 0); v1 = 21000;
    if (branch) goto L_b4398;
    goto L_b420c;
L_b420c:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21001);
    if (branch) goto L_b4518;
    goto L_b4214;
L_b4214:
    branch = (v1 == 0); v1 = 20739;
    if (branch) goto L_b42e0;
    goto L_b421c;
L_b421c:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(20740);
    if (branch) goto L_b4614;
    goto L_b4224;
L_b4224:
    branch = (v1 == 0); v1 = 20483;
    if (branch) goto L_b4288;
    goto L_b422c;
L_b422c:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(20484);
    if (branch) goto L_b45f0;
    goto L_b4234;
L_b4234:
    branch = (v1 == 0); v1 = 20481;
    if (branch) goto L_b4260;
    goto L_b423c;
L_b423c:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(20482);
    if (branch) goto L_b45d8;
    goto L_b4244;
L_b4244:
    branch = (v1 == 0); v1 = 20480;
    if (branch) goto L_b45e4;
    goto L_b424c;
L_b424c:
    if (v0 != v1) { s0 = hi_b4250; goto L_b4620; }
    goto L_b4254;
L_b4254:
    s0 = hi_b4254;
    s0 = s0 - hi_b4254 + (u32)(unsigned long)ref_t32_data_cc3b0; goto L_b4630;
L_b4260:
    v1 = 20737;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(20738);
    if (branch) goto L_b45fc;
    goto L_b426c;
L_b426c:
    branch = (v1 == 0); v1 = 20736;
    if (branch) goto L_b4608;
    goto L_b4274;
L_b4274:
    if (v0 != v1) { s0 = hi_b4278; goto L_b4620; }
    goto L_b427c;
L_b427c:
    s0 = hi_b427c;
    s0 = s0 - hi_b427c + (u32)(unsigned long)ref_t32_data_cc3e0; goto L_b4630;
L_b4288:
    v1 = 20995;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(20996);
    if (branch) goto L_b4530;
    goto L_b4294;
L_b4294:
    branch = (v1 == 0); v1 = 20997;
    if (branch) goto L_b42c0;
    goto L_b429c;
L_b429c:
    v1 = 20993;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(20994);
    if (branch) goto L_b4628;
    goto L_b42a8;
L_b42a8:
    branch = (v1 == 0); v1 = 20992;
    if (branch) goto L_b4524;
    goto L_b42b0;
L_b42b0:
    if (v0 == v1) { s0 = hi_b42b4; goto L_b451c; }
    goto L_b42b8;
L_b42b8:
    s0 = hi_b42bc; goto L_b4620;
L_b42c0:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(20997);
    if (branch) goto L_b4628;
    goto L_b42c8;
L_b42c8:
    branch = (v1 != 0); v1 = 20998;
    if (branch) goto L_b4518;
    goto L_b42d0;
L_b42d0:
    branch = (v0 == v1); v1 = 20999;
    if (branch) goto L_b4524;
    goto L_b42d8;
L_b42d8:
    ; goto L_b4318;
L_b42e0:
    v1 = 21252;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21253);
    if (branch) goto L_b4548;
    goto L_b42ec;
L_b42ec:
    branch = (v1 == 0); v1 = 21256;
    if (branch) goto L_b4344;
    goto L_b42f4;
L_b42f4:
    v1 = 21248;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21249);
    if (branch) goto L_b4530;
    goto L_b4300;
L_b4300:
    branch = (v1 == 0); v1 = 21002;
    if (branch) goto L_b4328;
    goto L_b4308;
L_b4308:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21002);
    if (branch) goto L_b4524;
    goto L_b4310;
L_b4310:
    branch = (v1 != 0); v1 = 21003;
    if (branch) goto L_b4628;
    goto L_b4318;
L_b4318:
    if (v0 == v1) { s0 = hi_b431c; goto L_b4534; }
    goto L_b4320;
L_b4320:
    s0 = hi_b4324; goto L_b4620;
L_b4328:
    v1 = 21250;
    branch = (v0 == v1); v0 = (u32)v0 < (u32)(21251);
    if (branch) goto L_b4530;
    goto L_b4334;
L_b4334:
    if (v0 != 0) { s0 = hi_b4338; goto L_b4534; }
    goto L_b433c;
L_b433c:
    s0 = hi_b4340; goto L_b4540;
L_b4344:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21257);
    if (branch) goto L_b4578;
    goto L_b434c;
L_b434c:
    branch = (v1 == 0); v1 = 21258;
    if (branch) goto L_b4370;
    goto L_b4354;
L_b4354:
    v1 = 21254;
    branch = (v0 == v1); v0 = (u32)v0 < (u32)(21255);
    if (branch) goto L_b4560;
    goto L_b4360;
L_b4360:
    if (v0 != 0) { s0 = hi_b4364; goto L_b4558; }
    goto L_b4368;
L_b4368:
    s0 = hi_b436c; goto L_b4570;
L_b4370:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21258);
    if (branch) goto L_b4590;
    goto L_b4378;
L_b4378:
    branch = (v1 != 0); v1 = 21259;
    if (branch) goto L_b4584;
    goto L_b4380;
L_b4380:
    branch = (v0 == v1); v1 = 21260;
    if (branch) goto L_b459c;
    goto L_b4388;
L_b4388:
    if (v0 == v1) { s0 = hi_b438c; goto L_b45ac; }
    goto L_b4390;
L_b4390:
    s0 = hi_b4394; goto L_b4620;
L_b4398:
    v1 = 21278;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21279);
    if (branch) goto L_b45c0;
    goto L_b43a4;
L_b43a4:
    branch = (v1 == 0); v1 = 21287;
    if (branch) goto L_b445c;
    goto L_b43ac;
L_b43ac:
    v1 = 21269;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21270);
    if (branch) goto L_b4554;
    goto L_b43b8;
L_b43b8:
    branch = (v1 == 0); v1 = 21273;
    if (branch) goto L_b4408;
    goto L_b43c0;
L_b43c0:
    v1 = 21265;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21266);
    if (branch) goto L_b4530;
    goto L_b43cc;
L_b43cc:
    branch = (v1 == 0); v1 = 21263;
    if (branch) goto L_b43ec;
    goto L_b43d4;
L_b43d4:
    branch = (v0 == v1); v0 = (u32)v0 < (u32)(21264);
    if (branch) goto L_b45cc;
    goto L_b43dc;
L_b43dc:
    if (v0 != 0) { s0 = hi_b43e0; goto L_b45c4; }
    goto L_b43e4;
L_b43e4:
    s0 = hi_b43e8; goto L_b4534;
L_b43ec:
    v1 = 21267;
    branch = (v0 == v1); v0 = (u32)v0 < (u32)(21268);
    if (branch) goto L_b453c;
    goto L_b43f8;
L_b43f8:
    if (v0 != 0) { s0 = hi_b43fc; goto L_b4534; }
    goto L_b4400;
L_b4400:
    s0 = hi_b4404; goto L_b454c;
L_b4408:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21274);
    if (branch) goto L_b4584;
    goto L_b4410;
L_b4410:
    branch = (v1 == 0); v1 = 21275;
    if (branch) goto L_b4434;
    goto L_b4418;
L_b4418:
    v1 = 21271;
    branch = (v0 == v1); v0 = (u32)v0 < (u32)(21272);
    if (branch) goto L_b456c;
    goto L_b4424;
L_b4424:
    if (v0 != 0) { s0 = hi_b4428; goto L_b4564; }
    goto L_b442c;
L_b442c:
    s0 = hi_b4430; goto L_b457c;
L_b4434:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21275);
    if (branch) goto L_b459c;
    goto L_b443c;
L_b443c:
    branch = (v1 != 0); v1 = 21276;
    if (branch) goto L_b4590;
    goto L_b4444;
L_b4444:
    branch = (v0 == v1); v1 = 21277;
    if (branch) goto L_b45a8;
    goto L_b444c;
L_b444c:
    if (v0 == v1) { s0 = hi_b4450; goto L_b45b8; }
    goto L_b4454;
L_b4454:
    s0 = hi_b4458; goto L_b4620;
L_b445c:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21288);
    if (branch) goto L_b456c;
    goto L_b4464;
L_b4464:
    branch = (v1 == 0); v1 = 21291;
    if (branch) goto L_b44c4;
    goto L_b446c;
L_b446c:
    v1 = 21282;
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21283);
    if (branch) goto L_b4530;
    goto L_b4478;
L_b4478:
    branch = (v1 == 0); v1 = 21284;
    if (branch) goto L_b449c;
    goto L_b4480;
L_b4480:
    v1 = 21280;
    branch = (v0 == v1); v0 = (u32)v0 < (u32)(21281);
    if (branch) goto L_b4530;
    goto L_b448c;
L_b448c:
    if (v0 != 0) { s0 = hi_b4490; goto L_b45d0; }
    goto L_b4494;
L_b4494:
    s0 = hi_b4498; goto L_b4534;
L_b449c:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21284);
    if (branch) goto L_b4548;
    goto L_b44a4;
L_b44a4:
    branch = (v1 != 0); v1 = 21285;
    if (branch) goto L_b453c;
    goto L_b44ac;
L_b44ac:
    branch = (v0 == v1); v1 = 21286;
    if (branch) goto L_b4554;
    goto L_b44b4;
L_b44b4:
    if (v0 == v1) { s0 = hi_b44b8; goto L_b4564; }
    goto L_b44bc;
L_b44bc:
    s0 = hi_b44c0; goto L_b4620;
L_b44c4:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21292);
    if (branch) goto L_b459c;
    goto L_b44cc;
L_b44cc:
    branch = (v1 == 0); v1 = 21293;
    if (branch) goto L_b44f0;
    goto L_b44d4;
L_b44d4:
    v1 = 21289;
    branch = (v0 == v1); v0 = (u32)v0 < (u32)(21290);
    if (branch) goto L_b4584;
    goto L_b44e0;
L_b44e0:
    if (v0 != 0) { s0 = hi_b44e4; goto L_b457c; }
    goto L_b44e8;
L_b44e8:
    s0 = hi_b44ec; goto L_b4594;
L_b44f0:
    branch = (v0 == v1); v1 = (u32)v0 < (u32)(21293);
    if (branch) goto L_b45b4;
    goto L_b44f8;
L_b44f8:
    branch = (v1 != 0); v1 = 21294;
    if (branch) goto L_b45a8;
    goto L_b4500;
L_b4500:
    branch = (v0 == v1); v1 = 21295;
    if (branch) goto L_b45c0;
    goto L_b4508;
L_b4508:
    if (v0 == v1) { s0 = hi_b450c; goto L_b45d0; }
    goto L_b4510;
L_b4510:
    s0 = hi_b4514; goto L_b4620;
L_b4518:
    s0 = hi_b4518;
L_b451c:
    s0 = s0 - hi_b4518 + (u32)(unsigned long)ref_t32_data_cc328; goto L_b4630;
L_b4524:
    s0 = hi_b4524;
    s0 = s0 - hi_b4524 + (u32)(unsigned long)ref_t32_data_cc338; goto L_b4630;
L_b4530:
    s0 = hi_b4530;
L_b4534:
    s0 = s0 - hi_b4530 + (u32)(unsigned long)ref_t32_data_cc340; goto L_b4630;
L_b453c:
    s0 = hi_b453c;
L_b4540:
    s0 = s0 - hi_b453c + (u32)(unsigned long)ref_t32_data_cc348; goto L_b4630;
L_b4548:
    s0 = hi_b4548;
L_b454c:
    s0 = s0 - hi_b4548 + (u32)(unsigned long)ref_t32_data_cc350; goto L_b4630;
L_b4554:
    s0 = hi_b4554;
L_b4558:
    s0 = s0 - hi_b4554 + (u32)(unsigned long)ref_t32_data_cc358; goto L_b4630;
L_b4560:
    s0 = hi_b4560;
L_b4564:
    s0 = s0 - hi_b4560 + (u32)(unsigned long)ref_t32_data_cc360; goto L_b4630;
L_b456c:
    s0 = hi_b456c;
L_b4570:
    s0 = s0 - hi_b456c + (u32)(unsigned long)ref_t32_data_cc368; goto L_b4630;
L_b4578:
    s0 = hi_b4578;
L_b457c:
    s0 = s0 - hi_b4578 + (u32)(unsigned long)ref_t32_data_cc370; goto L_b4630;
L_b4584:
    s0 = hi_b4584;
    s0 = s0 - hi_b4584 + (u32)(unsigned long)ref_t32_data_cc378; goto L_b4630;
L_b4590:
    s0 = hi_b4590;
L_b4594:
    s0 = s0 - hi_b4590 + (u32)(unsigned long)ref_t32_data_cc380; goto L_b4630;
L_b459c:
    s0 = hi_b459c;
    s0 = s0 - hi_b459c + (u32)(unsigned long)ref_t32_data_cc388; goto L_b4630;
L_b45a8:
    s0 = hi_b45a8;
L_b45ac:
    s0 = s0 - hi_b45a8 + (u32)(unsigned long)ref_t32_data_cc390; goto L_b4630;
L_b45b4:
    s0 = hi_b45b4;
L_b45b8:
    s0 = s0 - hi_b45b4 + (u32)(unsigned long)ref_t32_data_cc398; goto L_b4630;
L_b45c0:
    s0 = hi_b45c0;
L_b45c4:
    s0 = s0 - hi_b45c0 + (u32)(unsigned long)ref_t32_data_cc3a0; goto L_b4630;
L_b45cc:
    s0 = hi_b45cc;
L_b45d0:
    s0 = s0 - hi_b45cc + (u32)(unsigned long)ref_t32_data_cc3a8; goto L_b4630;
L_b45d8:
    s0 = hi_b45d8;
    s0 = s0 - hi_b45d8 + (u32)(unsigned long)ref_t32_data_cc3bc; goto L_b4630;
L_b45e4:
    s0 = hi_b45e4;
    s0 = s0 - hi_b45e4 + (u32)(unsigned long)ref_t32_data_cc3c8; goto L_b4630;
L_b45f0:
    s0 = hi_b45f0;
    s0 = s0 - hi_b45f0 + (u32)(unsigned long)ref_t32_data_cc3d4; goto L_b4630;
L_b45fc:
    s0 = hi_b45fc;
    s0 = s0 - hi_b45fc + (u32)(unsigned long)ref_t32_data_cc3ec; goto L_b4630;
L_b4608:
    s0 = hi_b4608;
    s0 = s0 - hi_b4608 + (u32)(unsigned long)ref_t32_data_cc3f8; goto L_b4630;
L_b4614:
    s0 = hi_b4614;
    s0 = s0 - hi_b4614 + (u32)(unsigned long)ref_t32_data_cc404; goto L_b4630;
L_b4620:
    s0 = s0 - hi_b4514 + (u32)(unsigned long)ref_t32_data_cc410; goto L_b4630;
L_b4628:
    s0 = hi_b4628;
    s0 = s0 - hi_b4628 + (u32)(unsigned long)ref_t32_data_cc330;
L_b4630:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (52));
    a1 = hi_b4634;
    a1 = a1 - hi_b4634 + (u32)(unsigned long)ref_t32_data_cc498;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b4648;
L_b4648:
    a2 = *(volatile u32 *)(unsigned long)(s4 + (0));
    a1 = hi_b464c;
    a1 = a1 - hi_b464c + (u32)(unsigned long)ref_t32_data_cc4ac;
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b465c;
L_b465c:
    a2 = *(volatile u32 *)(unsigned long)(s4 + (4));
    a1 = hi_b4660;
    a1 = a1 - hi_b4660 + (u32)(unsigned long)ref_t32_data_cc4c8;
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b4670;
L_b4670:
    a2 = *(volatile u32 *)(unsigned long)(s3 + (68));
    a1 = hi_b4674;
    a1 = a1 - hi_b4674 + (u32)(unsigned long)ref_t32_data_cc4e4;
    a3 = a2 & 0xffff;
    a0 = s1;
    callee = s2; a2 = a2 >> (0x10 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b468c;
L_b468c:
    a1 = hi_b468c;
    a2 = s0;
    a1 = a1 - hi_b468c + (u32)(unsigned long)ref_t32_data_cc504;
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b46a0;
L_b46a0:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (56));
    a1 = hi_b46a4;
    a1 = a1 - hi_b46a4 + (u32)(unsigned long)ref_t32_data_cc520;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (104));
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b46b8;
L_b46b8:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (52));
    a1 = hi_b46bc;
    a1 = a1 - hi_b46bc + (u32)(unsigned long)ref_t32_data_cc534;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (276));
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b46d0;
L_b46d0:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (52));
    a1 = hi_b46d4;
    a1 = a1 - hi_b46d4 + (u32)(unsigned long)ref_t32_data_cc548;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (278));
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b46e8;
L_b46e8:
    v1 = *(volatile u32 *)(unsigned long)(s3 + (68));
    v0 = 0xfU << 16;
    v0 = v0 + 16960;
    a2 = v1 >> (0x10 & 31);
    if (a2) { lo = v0 / a2; hi = v0 % a2; } else { lo = ~0U; hi = v0; }
    v1 = v1 & 0xffff;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (52));
    a1 = hi_b4704;
    a1 = a1 - hi_b4704 + (u32)(unsigned long)ref_t32_data_cc55c;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (278));
    a0 = s1;
    a2 = lo;
    a2 = a2 * v1;
    if (v0) { lo = a2 / v0; hi = a2 % v0; } else { lo = ~0U; hi = a2; }
    callee = s2; a2 = lo;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b4728;
L_b4728:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (52));
    a1 = hi_b472c;
    a1 = a1 - hi_b472c + (u32)(unsigned long)ref_t32_data_cc580;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (256));
    callee = s2; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b4740;
L_b4740:
    v0 = 0;
L_b4744:
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    s5 = *(volatile u32 *)(unsigned long)(sp + (48));
    s4 = *(volatile u32 *)(unsigned long)(sp + (44));
    s3 = *(volatile u32 *)(unsigned long)(sp + (40));
    s2 = *(volatile u32 *)(unsigned long)(sp + (36));
    s1 = *(volatile u32 *)(unsigned long)(sp + (32));
    s0 = *(volatile u32 *)(unsigned long)(sp + (28));
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
