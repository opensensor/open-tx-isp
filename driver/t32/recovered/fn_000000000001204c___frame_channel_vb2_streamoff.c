/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c62c0[] __asm__("t32_data_c62c0");
extern unsigned char ref_t32_data_c6388[] __asm__("t32_data_c6388");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_t32_data_d9d04[] __asm__("t32_data_d9d04");
extern unsigned char ref___vb2_queue_cancel[] __asm__("__vb2_queue_cancel");
u64 __frame_channel_vb2_streamoff(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_12064 = ((u32)(unsigned long)ref_t32_data_c62c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_12084 = ((u32)(unsigned long)ref_t32_data_c6388 + 0x8000U) & 0xffff0000U;
    const u32 hi_12090 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_12080 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_1214c = ((u32)(unsigned long)ref_t32_data_d9d04 + 0x8000U) & 0xffff0000U;
    const u32 hi_12164 = ((u32)(unsigned long)ref___vb2_queue_cancel + 0x8000U) & 0xffff0000U;
    const u32 hi_120c8 = ((u32)(unsigned long)ref___vb2_queue_cancel + 0x8000U) & 0xffff0000U;
    const u32 hi_120ec = ((u32)(unsigned long)ref___vb2_queue_cancel + 0x8000U) & 0xffff0000U;
    const u32 hi_1210c = ((u32)(unsigned long)ref___vb2_queue_cancel + 0x8000U) & 0xffff0000U;
    const u32 hi_1211c = ((u32)(unsigned long)ref___vb2_queue_cancel + 0x8000U) & 0xffff0000U;
    const u32 hi_1212c = ((u32)(unsigned long)ref___vb2_queue_cancel + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
    sp = sp + -24;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (44));
    branch = (v0 == a1); s0 = a0;
    if (branch) goto L_12074;
    goto L_12064;
L_12064:
    a1 = hi_12064;
    a1 = a1 - hi_12064 + (u32)(unsigned long)ref_t32_data_c62c0;
    a0 = 2; goto L_12090;
L_12074:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (580));
    v0 = v0 & 0x1;
    if (v0 != 0) { v0 = hi_12080; goto L_120a8; }
    goto L_12084;
L_12084:
    a1 = hi_12084;
    a1 = a1 - hi_12084 + (u32)(unsigned long)ref_t32_data_c6388;
    a0 = 1;
L_12090:
    v0 = hi_12090;
    v0 = v0 - hi_12090 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_120a0;
L_120a0:
    v0 = -22; goto L_12180;
L_120a8:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_12080 + (u32)(unsigned long)ref_t32_data_d9014);
    v1 = 1;
    branch = (v0 != v1); a0 = a0 + 44;
    if (branch) goto L_120cc;
    goto L_120b8;
L_120b8:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (720));
    branch = (v0 == 0); v1 = 3;
    if (branch) goto L_12148;
    goto L_120c4;
L_120c4:
    v0 = hi_120c8; goto L_12168;
L_120cc:
    v1 = 2;
    branch = (v0 != v1); v1 = 3;
    if (branch) goto L_120f8;
    goto L_120d8;
L_120d8:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (720));
    if (v0 == 0) { if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; } goto L_1214c; }
    goto L_120e4;
L_120e4:
    v1 = 3;
    if (v0 != v1) { v0 = hi_120ec; goto L_12168; }
    goto L_120f0;
L_120f0:
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; } goto L_1214c;
L_120f8:
    branch = (v0 != v1); v1 = 4;
    if (branch) goto L_12118;
    goto L_12100;
L_12100:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (720));
    v0 = (u32)v1 < (u32)(7);
    if (v0 == 0) { v0 = hi_1210c; goto L_12168; }
    goto L_12110;
L_12110:
    v0 = 73; goto L_12134;
L_12118:
    branch = (v0 != v1); v0 = hi_1211c;
    if (branch) goto L_12168;
    goto L_12120;
L_12120:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (720));
    v0 = (u32)v1 < (u32)(10);
    branch = (v0 == 0); v0 = hi_1212c;
    if (branch) goto L_12168;
    goto L_12130;
L_12130:
    v0 = 585;
L_12134:
    v0 = v0 >> (v1 & 31);
    v0 = v0 & 0x1;
    branch = (v0 == 0); v1 = 3;
    if (branch) goto L_12164;
    goto L_12144;
L_12144:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (720));
L_12148:
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
L_1214c:
    v1 = hi_1214c;
    v1 = v1 - hi_1214c + (u32)(unsigned long)ref_t32_data_d9d04;
    v0 = lo;
    v0 = v0 << (0x2 & 31);
    v0 = v0 + v1;
L_12160:
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
L_12164:
    v0 = hi_12164;
L_12168:
    v0 = v0 - hi_12164 + (u32)(unsigned long)ref___vb2_queue_cancel;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12174;
L_12174:
    v0 = 3;
    *(volatile u32 *)(unsigned long)(s0 + (736)) = v0;
    v0 = 0;
L_12180:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
