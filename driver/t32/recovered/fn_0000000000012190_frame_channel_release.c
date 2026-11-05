/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref___frame_channel_vb2_streamoff[] __asm__("__frame_channel_vb2_streamoff");
extern unsigned char ref___vb2_queue_free[] __asm__("__vb2_queue_free");
extern unsigned char ref_t32_data_d9008[] __asm__("t32_data_d9008");
extern unsigned char ref_t32_data_f37d4[] __asm__("t32_data_f37d4");
extern unsigned char ref_t32_data_f37a4[] __asm__("t32_data_f37a4");
extern unsigned char ref_t32_data_f3774[] __asm__("t32_data_f3774");
extern unsigned char ref_t32_data_f3370[] __asm__("t32_data_f3370");
extern unsigned char ref_t32_data_d9004[] __asm__("t32_data_d9004");
extern unsigned char ref_t32_data_d9954[] __asm__("t32_data_d9954");
extern unsigned char ref_private_kfree[] __asm__("private_kfree");
u64 frame_channel_release(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_121d0 = ((u32)(unsigned long)ref___frame_channel_vb2_streamoff + 0x8000U) & 0xffff0000U;
    const u32 hi_121e4 = ((u32)(unsigned long)ref___vb2_queue_free + 0x8000U) & 0xffff0000U;
    const u32 hi_121fc = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_12210 = ((u32)(unsigned long)ref_t32_data_f37d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_1222c = ((u32)(unsigned long)ref_t32_data_f37a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_12244 = ((u32)(unsigned long)ref_t32_data_f3774 + 0x8000U) & 0xffff0000U;
    const u32 hi_12264 = ((u32)(unsigned long)ref_t32_data_f3370 + 0x8000U) & 0xffff0000U;
    const u32 hi_1229c = ((u32)(unsigned long)ref___frame_channel_vb2_streamoff + 0x8000U) & 0xffff0000U;
    const u32 hi_122b0 = ((u32)(unsigned long)ref___vb2_queue_free + 0x8000U) & 0xffff0000U;
    const u32 hi_122c8 = ((u32)(unsigned long)ref_t32_data_d9004 + 0x8000U) & 0xffff0000U;
    const u32 hi_122dc = ((u32)(unsigned long)ref_t32_data_d9954 + 0x8000U) & 0xffff0000U;
    const u32 hi_122f8 = ((u32)(unsigned long)ref_private_kfree + 0x8000U) & 0xffff0000U;
    const u32 hi_12208 = ((u32)(unsigned long)ref_t32_data_d9004 + 0x8000U) & 0xffff0000U;
    const u32 hi_12228 = ((u32)(unsigned long)ref_t32_data_d9004 + 0x8000U) & 0xffff0000U;
    const u32 hi_12240 = ((u32)(unsigned long)ref_t32_data_d9004 + 0x8000U) & 0xffff0000U;
    const u32 hi_12258 = ((u32)(unsigned long)ref_t32_data_d9004 + 0x8000U) & 0xffff0000U;
    const u32 hi_12294 = ((u32)(unsigned long)ref_t32_data_d9004 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_12190:
    sp = sp + -32;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    s0 = *(volatile u32 *)(unsigned long)(a1 + (120));
    branch = (s0 == 0); v0 = -22;
    if (branch) goto L_1231c;
    goto L_121ac;
L_121ac:
    v0 = (u32)s0 < (u32)(-4095);
    if (v0 != 0) { v1 = *(volatile u32 *)(unsigned long)(s0 + (736)); goto L_121c0; }
    goto L_121b8;
L_121b8:
    v0 = -22; goto L_1231c;
L_121c0:
    v0 = 4;
    branch = (v1 != v0); s1 = a1;
    if (branch) goto L_121fc;
    goto L_121cc;
L_121cc:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (44));
    v0 = hi_121d0;
    v0 = v0 - hi_121d0 + (u32)(unsigned long)ref___frame_channel_vb2_streamoff;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_121e0;
L_121e0:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (532));
    v0 = hi_121e4;
    v0 = v0 - hi_121e4 + (u32)(unsigned long)ref___vb2_queue_free;
    callee = v0; a0 = s0 + 44;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_121f4;
L_121f4:
    v0 = 2;
    *(volatile u32 *)(unsigned long)(s0 + (736)) = v0;
L_121fc:
    v0 = hi_121fc;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_121fc + (u32)(unsigned long)ref_t32_data_d9008);
    branch = (v0 == 0); v0 = hi_12208;
    if (branch) goto L_122cc;
    goto L_1220c;
L_1220c:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (720));
    v1 = hi_12210;
    v1 = v1 - hi_12210 + (u32)(unsigned long)ref_t32_data_f37d4;
    v0 = v0 << (0x2 & 31);
    v1 = v0 + v1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    if (v1 == 0) { v0 = hi_12228; goto L_122cc; }
    goto L_1222c;
L_1222c:
    v1 = hi_1222c;
    v1 = v1 - hi_1222c + (u32)(unsigned long)ref_t32_data_f37a4;
    v1 = v0 + v1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    if (v1 == 0) { v0 = hi_12240; goto L_122cc; }
    goto L_12244;
L_12244:
    v1 = hi_12244;
    v1 = v1 - hi_12244 + (u32)(unsigned long)ref_t32_data_f3774;
    v1 = v0 + v1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    if (v1 == 0) { v0 = hi_12258; goto L_122cc; }
    goto L_1225c;
L_1225c:
    if (s1 != 0) { s1 = *(volatile u32 *)(unsigned long)(s1 + (120)); goto L_12274; }
    goto L_12264;
L_12264:
    v1 = hi_12264;
    v1 = v1 - hi_12264 + (u32)(unsigned long)ref_t32_data_f3370;
    v0 = v0 + v1;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (0));
L_12274:
    branch = (s1 == 0); v0 = -22;
    if (branch) goto L_1231c;
    goto L_1227c;
L_1227c:
    v0 = (u32)s1 < (u32)(-4095);
    branch = (v0 == 0); v0 = -22;
    if (branch) goto L_1231c;
    goto L_12288;
L_12288:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (736));
    v0 = 4;
    branch = (v1 != v0); v0 = hi_12294;
    if (branch) goto L_122cc;
    goto L_12298;
L_12298:
    a1 = *(volatile u32 *)(unsigned long)(s1 + (44));
    v0 = hi_1229c;
    v0 = v0 - hi_1229c + (u32)(unsigned long)ref___frame_channel_vb2_streamoff;
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_122ac;
L_122ac:
    a1 = *(volatile u32 *)(unsigned long)(s1 + (532));
    v0 = hi_122b0;
    v0 = v0 - hi_122b0 + (u32)(unsigned long)ref___vb2_queue_free;
    callee = v0; a0 = s1 + 44;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_122c0;
L_122c0:
    v0 = 2;
    *(volatile u32 *)(unsigned long)(s1 + (736)) = v0;
    v0 = hi_122c8;
L_122cc:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_122c8 + (u32)(unsigned long)ref_t32_data_d9004);
    branch = (v0 == 0); ra = *(volatile u32 *)(unsigned long)(sp + (28));
    if (branch) goto L_12320;
    goto L_122d8;
L_122d8:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (720));
    v0 = hi_122dc;
    s1 = v0 - hi_122dc + (u32)(unsigned long)ref_t32_data_d9954;
    v1 = v1 << (0x2 & 31);
    v1 = v1 + s1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    branch = (a0 == 0); v0 = 0;
    if (branch) goto L_12320;
    goto L_122f8;
L_122f8:
    v0 = hi_122f8;
    v0 = v0 - hi_122f8 + (u32)(unsigned long)ref_private_kfree;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12308;
L_12308:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (720));
    v0 = v0 << (0x2 & 31);
    v0 = v0 + s1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    v0 = 0;
L_1231c:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
L_12320:
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
