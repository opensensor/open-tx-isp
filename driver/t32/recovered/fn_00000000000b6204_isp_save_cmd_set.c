/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_ccae8[] __asm__("t32_data_ccae8");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_private_copy_from_user[] __asm__("private_copy_from_user");
extern unsigned char ref_t32_data_ccb04[] __asm__("t32_data_ccb04");
extern unsigned char ref_private_msleep[] __asm__("private_msleep");
extern unsigned char ref_t32_data_ccb0c[] __asm__("t32_data_ccb0c");
extern unsigned char ref_lib_tisp_func_stop_reset[] __asm__("lib_tisp_func_stop_reset");
extern unsigned char ref_t32_data_ccb1c[] __asm__("t32_data_ccb1c");
extern unsigned char ref_t32_data_c311c[] __asm__("t32_data_c311c");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_ccb24[] __asm__("t32_data_ccb24");
extern unsigned char ref_strsep[] __asm__("strsep");
extern unsigned char ref_t32_data_ccb28[] __asm__("t32_data_ccb28");
extern unsigned char ref_t32_data_ccb20[] __asm__("t32_data_ccb20");
extern unsigned char ref_kstrtouint[] __asm__("kstrtouint");
extern unsigned char ref_memset[] __asm__("memset");
u64 isp_save_cmd_set(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[88] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b625c = ((u32)(unsigned long)ref_t32_data_ccae8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b6260 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_b627c = ((u32)(unsigned long)ref_private_copy_from_user + 0x8000U) & 0xffff0000U;
    const u32 hi_b6294 = ((u32)(unsigned long)ref_t32_data_ccb04 + 0x8000U) & 0xffff0000U;
    const u32 hi_b62e0 = ((u32)(unsigned long)ref_private_msleep + 0x8000U) & 0xffff0000U;
    const u32 hi_b62d0 = ((u32)(unsigned long)ref_t32_data_ccb0c + 0x8000U) & 0xffff0000U;
    const u32 hi_b6334 = ((u32)(unsigned long)ref_lib_tisp_func_stop_reset + 0x8000U) & 0xffff0000U;
    const u32 hi_b6330 = ((u32)(unsigned long)ref_t32_data_ccb1c + 0x8000U) & 0xffff0000U;
    const u32 hi_b638c = ((u32)(unsigned long)ref_t32_data_c311c + 0x8000U) & 0xffff0000U;
    const u32 hi_b6390 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b63a8 = ((u32)(unsigned long)ref_t32_data_ccb24 + 0x8000U) & 0xffff0000U;
    const u32 hi_b63ac = (((u32)(unsigned long)ref_strsep + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b63b4 = ((u32)(unsigned long)ref_t32_data_ccb28 + 0x8000U) & 0xffff0000U;
    const u32 hi_b63c4 = ((u32)(unsigned long)ref_t32_data_ccb20 + 0x8000U) & 0xffff0000U;
    const u32 hi_b63ec = (((u32)(unsigned long)ref_kstrtouint + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b64e8 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b624c = ((u32)(unsigned long)ref_t32_data_ccae8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b62f4 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b6348 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[24];
L_b6204:
    sp = sp + -96;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (92)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (88)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (84)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (72)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (68)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (120));
    s2 = a1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (72));
    branch = (v0 == 0); s6 = a2;
    if (branch) goto L_b625c;
    goto L_b6244;
L_b6244:
    v1 = (u32)v0 < (u32)(-4095);
    if (v1 == 0) { a1 = hi_b624c; goto L_b6260; }
    goto L_b6250;
L_b6250:
    s0 = *(volatile u32 *)(unsigned long)(v0 + (280));
    branch = (s0 != 0); s1 = s0 + 784;
    if (branch) goto L_b627c;
    goto L_b625c;
L_b625c:
    a1 = hi_b625c;
L_b6260:
    v0 = hi_b6260;
    a1 = a1 - hi_b625c + (u32)(unsigned long)ref_t32_data_ccae8;
    v0 = v0 - hi_b6260 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b6274;
L_b6274:
    s0 = 0;
    s1 = s0 + 784;
L_b627c:
    v0 = hi_b627c;
    a0 = s1;
    a2 = s6;
    v0 = v0 - hi_b627c + (u32)(unsigned long)ref_private_copy_from_user;
    callee = v0; a1 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b6294;
L_b6294:
    v0 = hi_b6294;
    v1 = s1;
    v0 = v0 - hi_b6294 + (u32)(unsigned long)ref_t32_data_ccb04;
    a0 = 6;
L_b62a4:
    a1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    branch = (a0 == 0); at = *(volatile u8 *)(unsigned long)(v0 + (0));
    if (branch) goto L_b62c4;
    goto L_b62b0;
L_b62b0:
    a0 = a0 + -1;
    branch = (at != a1); v1 = v1 + 1;
    if (branch) goto L_b62c8;
    goto L_b62bc;
L_b62bc:
    branch = (a1 != 0); v0 = v0 + 1;
    if (branch) goto L_b62a4;
    goto L_b62c4;
L_b62c4:
    a1 = at;
L_b62c8:
    a1 = a1 - at;
    if (a1 != 0) { v0 = hi_b62d0; goto L_b62f8; }
    goto L_b62d4;
L_b62d4:
    v0 = 1;
    *(volatile u8 *)(unsigned long)(s0 + (944)) = v0;
    *(volatile u8 *)(unsigned long)(s0 + (945)) = v0;
    v0 = hi_b62e0;
    v0 = v0 - hi_b62e0 + (u32)(unsigned long)ref_private_msleep;
    callee = v0; a0 = 200;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b62f0;
L_b62f0:
    v0 = hi_b62f4; goto L_b64ec;
L_b62f8:
    v1 = s1;
    v0 = v0 - hi_b62d0 + (u32)(unsigned long)ref_t32_data_ccb0c;
    a0 = 13;
L_b6304:
    a1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    branch = (a0 == 0); at = *(volatile u8 *)(unsigned long)(v0 + (0));
    if (branch) goto L_b6324;
    goto L_b6310;
L_b6310:
    a0 = a0 + -1;
    branch = (at != a1); v1 = v1 + 1;
    if (branch) goto L_b6328;
    goto L_b631c;
L_b631c:
    branch = (a1 != 0); v0 = v0 + 1;
    if (branch) goto L_b6304;
    goto L_b6324;
L_b6324:
    a1 = at;
L_b6328:
    a1 = a1 - at;
    if (a1 != 0) { v0 = hi_b6330; goto L_b634c; }
    goto L_b6334;
L_b6334:
    v0 = hi_b6334;
    v0 = v0 - hi_b6334 + (u32)(unsigned long)ref_lib_tisp_func_stop_reset;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b6344;
L_b6344:
    v0 = hi_b6348; goto L_b64ec;
L_b634c:
    v1 = s1;
    v0 = v0 - hi_b6330 + (u32)(unsigned long)ref_t32_data_ccb1c;
    a0 = 1;
L_b6358:
    a1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    branch = (a0 == 0); at = *(volatile u8 *)(unsigned long)(v0 + (0));
    if (branch) goto L_b6378;
    goto L_b6364;
L_b6364:
    a0 = a0 + -1;
    branch = (at != a1); v1 = v1 + 1;
    if (branch) goto L_b637c;
    goto L_b6370;
L_b6370:
    branch = (a1 != 0); v0 = v0 + 1;
    if (branch) goto L_b6358;
    goto L_b6378;
L_b6378:
    a1 = at;
L_b637c:
    a1 = a1 - at;
    branch = (a1 != 0); v0 = s0 + 786;
    if (branch) goto L_b64e8;
    goto L_b6388;
L_b6388:
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    a1 = hi_b638c;
    v0 = hi_b6390;
    a2 = 16;
    a1 = a1 - hi_b638c + (u32)(unsigned long)ref_t32_data_c311c;
    a0 = sp + 16;
    v0 = v0 - hi_b6390 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; s4 = hi_b63a8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b63ac;
L_b63ac:
    s2 = hi_b63ac;
    v0 = s4 - hi_b63a8 + (u32)(unsigned long)ref_t32_data_ccb24;
    s5 = hi_b63b4;
    s2 = s2 - hi_b63ac + ((u32)(unsigned long)ref_strsep + (0));
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    s5 = s5 - hi_b63b4 + (u32)(unsigned long)ref_t32_data_ccb28;
L_b63c4:
    s3 = hi_b63c4;
    a1 = s3 - hi_b63c4 + (u32)(unsigned long)ref_t32_data_ccb20;
    callee = s2; a0 = sp + 32;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b63d4;
L_b63d4:
    s7 = v0;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s3;
    branch = (v0 == 0); s8 = s2;
    if (branch) goto L_b64e8;
    goto L_b63e4;
L_b63e4:
    v0 = s0 + 760;
    *(volatile u32 *)(unsigned long)(sp + (40)) = v0;
    v0 = hi_b63ec;
    s4 = s0 + 744;
    s3 = sp + 16;
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
L_b63fc:
    v0 = *(volatile u32 *)(unsigned long)(sp + (40));
    branch = (s4 == v0); v1 = s7;
    if (branch) goto L_b63c4;
    goto L_b6408;
L_b6408:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
L_b6410:
    at = *(volatile u8 *)(unsigned long)(v1 + (0));
    v0 = v0 + 1;
    branch = (at != a0); v1 = v1 + 1;
    if (branch) goto L_b642c;
    goto L_b6420;
L_b6420:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    if (branch) goto L_b6410;
    goto L_b6428;
L_b6428:
    a0 = at;
L_b642c:
    a0 = a0 - at;
    if (a0 != 0) { s4 = s4 + 4; goto L_b64e0; }
    goto L_b6438;
L_b6438:
    v0 = *(volatile u32 *)(unsigned long)(sp + (44));
    a0 = sp + 32;
    callee = s8; a1 = v0 - hi_b63c4 + (u32)(unsigned long)ref_t32_data_ccb20;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b6448;
L_b6448:
    v1 = 2;
    a0 = v0;
    a1 = v0;
    a2 = *(volatile u32 *)(unsigned long)(sp + (52));
    t0 = v1;
L_b645c:
    t1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    branch = (t0 == 0); at = *(volatile u8 *)(unsigned long)(a2 + (0));
    if (branch) goto L_b647c;
    goto L_b6468;
L_b6468:
    t0 = t0 + -1;
    branch = (at != t1); a1 = a1 + 1;
    if (branch) goto L_b6480;
    goto L_b6474;
L_b6474:
    branch = (t1 != 0); a2 = a2 + 1;
    if (branch) goto L_b645c;
    goto L_b647c;
L_b647c:
    t1 = at;
L_b6480:
    t1 = t1 - at;
    v0 = *(volatile u32 *)(unsigned long)(sp + (48));
    branch = (t1 == 0); v0 = v0 - hi_b63ec + ((u32)(unsigned long)ref_kstrtouint + (0));
    if (branch) goto L_b64d0;
    goto L_b6490;
L_b6490:
    a1 = a0;
    a2 = s5;
L_b6498:
    t0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    branch = (v1 == 0); at = *(volatile u8 *)(unsigned long)(a2 + (0));
    if (branch) goto L_b64b8;
    goto L_b64a4;
L_b64a4:
    v1 = v1 + -1;
    branch = (at != t0); a1 = a1 + 1;
    if (branch) goto L_b64bc;
    goto L_b64b0;
L_b64b0:
    branch = (t0 != 0); a2 = a2 + 1;
    if (branch) goto L_b6498;
    goto L_b64b8;
L_b64b8:
    t0 = at;
L_b64bc:
    t0 = t0 - at;
    branch = (t0 == 0); a2 = s4;
    if (branch) goto L_b64d4;
    goto L_b64c8;
L_b64c8:
    a1 = 10; goto L_b64d8;
L_b64d0:
    a2 = s4;
L_b64d4:
    a1 = 16;
L_b64d8:
    callee = v0; s4 = s4 + 4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b64e0;
L_b64e0:
    s3 = s3 + 4; goto L_b63fc;
L_b64e8:
    v0 = hi_b64e8;
L_b64ec:
    a0 = s1;
    a2 = 64;
    v0 = v0 - hi_b64e8 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b6500;
L_b6500:
    ra = *(volatile u32 *)(unsigned long)(sp + (92));
    v0 = s6;
    s8 = *(volatile u32 *)(unsigned long)(sp + (88));
    s7 = *(volatile u32 *)(unsigned long)(sp + (84));
    s6 = *(volatile u32 *)(unsigned long)(sp + (80));
    s5 = *(volatile u32 *)(unsigned long)(sp + (76));
    s4 = *(volatile u32 *)(unsigned long)(sp + (72));
    s3 = *(volatile u32 *)(unsigned long)(sp + (68));
    s2 = *(volatile u32 *)(unsigned long)(sp + (64));
    s1 = *(volatile u32 *)(unsigned long)(sp + (60));
    s0 = *(volatile u32 *)(unsigned long)(sp + (56));
    sp = sp + 96;
    return ((u64)v1 << 32) | v0;
}
