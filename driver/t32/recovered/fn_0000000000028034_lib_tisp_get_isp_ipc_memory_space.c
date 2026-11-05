/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dc074[] __asm__("t32_data_dc074");
extern unsigned char ref_t32_data_dc284[] __asm__("t32_data_dc284");
extern unsigned char ref_t32_data_bf1d4[] __asm__("t32_data_bf1d4");
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_c8328[] __asm__("t32_data_c8328");
extern unsigned char ref_tisp_top_ipc_get_mem_size[] __asm__("tisp_top_ipc_get_mem_size");
extern unsigned char ref_lib_tisp_ldc_get_mem_size[] __asm__("lib_tisp_ldc_get_mem_size");
u64 lib_tisp_get_isp_ipc_memory_space(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_28068 = ((u32)(unsigned long)ref_t32_data_dc074 + 0x8000U) & 0xffff0000U;
    const u32 hi_28080 = ((u32)(unsigned long)ref_t32_data_dc284 + 0x8000U) & 0xffff0000U;
    const u32 hi_2809c = ((u32)(unsigned long)ref_t32_data_bf1d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_280b8 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_280a0 = ((u32)(unsigned long)ref_t32_data_c8328 + 0x8000U) & 0xffff0000U;
    const u32 hi_280d0 = ((u32)(unsigned long)ref_tisp_top_ipc_get_mem_size + 0x8000U) & 0xffff0000U;
    const u32 hi_28108 = ((u32)(unsigned long)ref_lib_tisp_ldc_get_mem_size + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
L_28034:
    sp = sp + -64;
    v0 = 76;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (60)) = ra;
    s5 = a0 & 0xff;
    s4 = a1;
    a0 = *(volatile u8 *)(unsigned long)(a1 + (2));
    a1 = s5 * v0;
    s0 = hi_28068;
    v1 = s0 - hi_28068 + (u32)(unsigned long)ref_t32_data_dc074;
    s3 = v1;
    s2 = 0;
    v0 = a1 + v1;
    *(volatile u8 *)(unsigned long)(v0 + (10)) = a0;
    v0 = hi_28080;
    v0 = v0 - hi_28080 + (u32)(unsigned long)ref_t32_data_dc284;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (900));
    a0 = a0 + -1;
    branch = (s5 != a0); s1 = v0;
    if (branch) goto L_280e4;
    goto L_28098;
L_28098:
    v0 = *(volatile u32 *)(unsigned long)(s0 - hi_28068 + (u32)(unsigned long)ref_t32_data_dc074);
    a1 = hi_2809c;
    a0 = hi_280a0;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s4 + (0));
    a3 = *(volatile u32 *)(unsigned long)(sp + (24));
    a2 = 1483;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_280b8;
    a1 = a1 - hi_2809c + (u32)(unsigned long)ref_t32_data_bf1d4;
    v0 = v0 - hi_280b8 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_280a0 + (u32)(unsigned long)ref_t32_data_c8328;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_280cc;
L_280cc:
    a1 = *(volatile u16 *)(unsigned long)(s4 + (0));
    v0 = hi_280d0;
    v0 = v0 - hi_280d0 + (u32)(unsigned long)ref_tisp_top_ipc_get_mem_size;
    callee = v0; a0 = *(volatile u16 *)(unsigned long)(s0 - hi_28068 + (u32)(unsigned long)ref_t32_data_dc074);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_280e0;
L_280e0:
    s2 = v0;
L_280e4:
    v1 = *(volatile u8 *)(unsigned long)(s4 + (2));
    v0 = 1;
    branch = (v1 != v0); ra = *(volatile u32 *)(unsigned long)(sp + (60));
    if (branch) goto L_28120;
    goto L_280f4;
L_280f4:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (900));
    v0 = v0 + -1;
    branch = (s5 != v0); v0 = s2;
    if (branch) goto L_28124;
    goto L_28104;
L_28104:
    a1 = *(volatile u32 *)(unsigned long)(s3 + (4));
    v0 = hi_28108;
    v0 = v0 - hi_28108 + (u32)(unsigned long)ref_lib_tisp_ldc_get_mem_size;
    callee = v0; a0 = *(volatile u32 *)(unsigned long)(s0 - hi_28068 + (u32)(unsigned long)ref_t32_data_dc074);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_28118;
L_28118:
    s2 = s2 + v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
L_28120:
    v0 = s2;
L_28124:
    s5 = *(volatile u32 *)(unsigned long)(sp + (56));
    s4 = *(volatile u32 *)(unsigned long)(sp + (52));
    s3 = *(volatile u32 *)(unsigned long)(sp + (48));
    s2 = *(volatile u32 *)(unsigned long)(sp + (44));
    s1 = *(volatile u32 *)(unsigned long)(sp + (40));
    s0 = *(volatile u32 *)(unsigned long)(sp + (36));
    sp = sp + 64;
    return ((u64)v1 << 32) | v0;
}
