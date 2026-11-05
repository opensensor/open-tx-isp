/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dd7e0[] __asm__("t32_data_dd7e0");
extern unsigned char ref_t32_small_bss[] __asm__("t32_small_bss");
extern unsigned char ref_t32_data_c849c[] __asm__("t32_data_c849c");
extern unsigned char ref___init_waitqueue_head[] __asm__("__init_waitqueue_head");
extern unsigned char ref_private_spin_lock_init[] __asm__("private_spin_lock_init");
u64 tisp_event_init(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_28cf8 = ((u32)(unsigned long)ref_t32_data_dd7e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_28d78 = ((u32)(unsigned long)ref_t32_small_bss + 0x8000U) & 0xffff0000U;
    const u32 hi_28d7c = ((u32)(unsigned long)ref_t32_data_c849c + 0x8000U) & 0xffff0000U;
    const u32 hi_28d80 = (((u32)(unsigned long)ref___init_waitqueue_head + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_28da4 = ((u32)(unsigned long)ref_private_spin_lock_init + 0x8000U) & 0xffff0000U;
    const u32 hi_28da0 = ((u32)(unsigned long)ref_t32_small_bss + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_28cf0:
    v0 = 3872;
    v0 = a0 * v0;
    a1 = hi_28cf8;
    a1 = a1 - hi_28cf8 + (u32)(unsigned long)ref_t32_data_dd7e0;
    a3 = 80;
    v1 = v0 + 3856;
    a2 = v0 + a1;
    v1 = a1 + v1;
    v0 = v0 + 16;
    *(volatile u32 *)(unsigned long)(a2 + (3856)) = v1;
    *(volatile u32 *)(unsigned long)(a2 + (3860)) = v1;
    v0 = a1 + v0;
    v1 = v1 + 8;
    *(volatile u32 *)(unsigned long)(a2 + (3864)) = v1;
    *(volatile u32 *)(unsigned long)(a2 + (3868)) = v1;
    a2 = v0;
L_28d30:
    a3 = a3 + -1;
    *(volatile u32 *)(unsigned long)(a2 + (0)) = a2;
    *(volatile u32 *)(unsigned long)(a2 + (4)) = a2;
    branch = (a3 != 0); a2 = a2 + 48;
    if (branch) goto L_28d30;
    goto L_28d44;
L_28d44:
    a3 = 3872;
    t0 = a0 * a3;
    a2 = 80;
    a0 = t0 + a1;
L_28d54:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (3868));
    a2 = a2 + -1;
    *(volatile u32 *)(unsigned long)(a0 + (3868)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = a1;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v0;
    branch = (a2 != 0); v0 = v0 + 48;
    if (branch) goto L_28d54;
    goto L_28d74;
L_28d74:
    sp = sp + -24;
    a2 = hi_28d78;
    a1 = hi_28d7c;
    v0 = hi_28d80;
    a2 = a2 - hi_28d78 + (u32)(unsigned long)ref_t32_small_bss;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    a1 = a1 - hi_28d7c + (u32)(unsigned long)ref_t32_data_c849c;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = 0;
    v0 = v0 - hi_28d80 + ((u32)(unsigned long)ref___init_waitqueue_head + (0));
    callee = v0; a0 = a0 + 4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_28da0;
L_28da0:
    a0 = hi_28da0;
    v0 = hi_28da4;
    v0 = v0 - hi_28da4 + (u32)(unsigned long)ref_private_spin_lock_init;
    callee = v0; a0 = a0 - hi_28da0 + (u32)(unsigned long)ref_t32_small_bss;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_28db4;
L_28db4:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = 0;
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
