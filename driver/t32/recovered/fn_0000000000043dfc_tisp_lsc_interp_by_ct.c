/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e17e0[] __asm__("t32_data_e17e0");
extern unsigned char ref___private_spin_lock_irqsave[] __asm__("__private_spin_lock_irqsave");
extern unsigned char ref_t32_data_dc274[] __asm__("t32_data_dc274");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_private_spin_unlock_irqrestore[] __asm__("private_spin_unlock_irqrestore");
extern unsigned char ref_tisp_lsc_mesh_itp[] __asm__("tisp_lsc_mesh_itp");
extern unsigned char ref_tisp_lsc_ring_itp[] __asm__("tisp_lsc_ring_itp");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_tisp_round_int64[] __asm__("tisp_round_int64");
extern unsigned char ref_tisp_clip[] __asm__("tisp_clip");
u64 tisp_lsc_interp_by_ct(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[132] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_43e00 = ((u32)(unsigned long)ref_t32_data_e17e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_43ef0 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_43f58 = ((u32)(unsigned long)ref_t32_data_dc274 + 0x8000U) & 0xffff0000U;
    const u32 hi_43f70 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_44044 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_44090 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_44230 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_44304 = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    const u32 hi_443d0 = ((u32)(unsigned long)ref_tisp_lsc_mesh_itp + 0x8000U) & 0xffff0000U;
    const u32 hi_4441c = ((u32)(unsigned long)ref_tisp_lsc_ring_itp + 0x8000U) & 0xffff0000U;
    const u32 hi_444b4 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4455c = ((u32)(unsigned long)ref_tisp_round_int64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4456c = ((u32)(unsigned long)ref_tisp_clip + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[68];
L_43dfc:
    sp = sp + -272;
    v0 = hi_43e00;
    v0 = v0 - hi_43e00 + (u32)(unsigned long)ref_t32_data_e17e0;
    *(volatile u32 *)(unsigned long)(sp + (236)) = s1;
    s1 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (268)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (264)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (260)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (256)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (252)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (248)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (244)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (240)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (232)) = s0;
    v1 = s1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t1 = a2 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (148)) = v0;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    s0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(sp + (116)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (4));
    *(volatile u32 *)(unsigned long)(sp + (160)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(sp + (116));
    a2 = a2 + 26;
    *(volatile u32 *)(unsigned long)(sp + (112)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(sp + (116));
    a2 = a2 + 4634;
    *(volatile u32 *)(unsigned long)(sp + (132)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(sp + (116));
    a2 = a2 + 9242;
    *(volatile u32 *)(unsigned long)(sp + (136)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(sp + (116));
    a2 = a2 + 2074;
    *(volatile u32 *)(unsigned long)(sp + (140)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(sp + (116));
    a2 = a2 + 4122;
    *(volatile u32 *)(unsigned long)(sp + (144)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (4));
    t0 = *(volatile u32 *)(unsigned long)(a2 + (8));
    a2 = a1 - t0;
    v0 = a2;
    a2 = *(volatile u32 *)(unsigned long)(sp + (116));
    a3 = (u32)t0 < (u32)(a1);
    t0 = t0 - a1;
    a2 = *(volatile u8 *)(unsigned long)(a2 + (17));
    if (a3 == 0) v0 = t0;
    *(volatile u32 *)(unsigned long)(sp + (156)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(sp + (116));
    *(volatile u32 *)(unsigned long)(sp + (108)) = 0;
    a2 = *(volatile u8 *)(unsigned long)(a2 + (18));
    branch = (t1 != 0); *(volatile u32 *)(unsigned long)(sp + (164)) = a2;
    if (branch) goto L_43ee0;
    goto L_43ed0;
L_43ed0:
    a2 = *(volatile u32 *)(unsigned long)(s0 + (12));
    a2 = (u32)a2 < (u32)(v0);
    branch = (a2 == 0); v0 = 0;
    if (branch) goto L_44ca8;
    goto L_43ee0;
L_43ee0:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (69));
    *(volatile u32 *)(unsigned long)(sp + (152)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (116));
    t7 = *(volatile u8 *)(unsigned long)(s0 + (116));
    s2 = hi_43ef0;
    *(volatile u8 *)(unsigned long)(a0 + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u8 *)(unsigned long)(s0 + (70));
    s2 = s2 - hi_43ef0 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    s4 = a1;
    *(volatile u8 *)(unsigned long)(v0 + (21)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u8 *)(unsigned long)(s0 + (71));
    *(volatile u32 *)(unsigned long)(sp + (120)) = t7;
    *(volatile u8 *)(unsigned long)(v0 + (22)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u8 *)(unsigned long)(s0 + (72));
    *(volatile u8 *)(unsigned long)(v0 + (23)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u8 *)(unsigned long)(s0 + (73));
    *(volatile u8 *)(unsigned long)(v0 + (24)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u8 *)(unsigned long)(s0 + (74));
    *(volatile u8 *)(unsigned long)(v0 + (25)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = v1 + 16;
    *(volatile u32 *)(unsigned long)(v0 + (8)) = a1;
    callee = s2; a1 = sp + 108;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_43f54;
L_43f54:
    t7 = *(volatile u32 *)(unsigned long)(sp + (120));
    a3 = hi_43f58;
    v0 = 1;
    a3 = a3 - hi_43f58 + (u32)(unsigned long)ref_t32_data_dc274;
    branch = (t7 != v0); *(volatile u32 *)(unsigned long)(sp + (184)) = s2;
    if (branch) goto L_44b4c;
    goto L_43f6c;
L_43f6c:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (65));
    s2 = hi_43f70;
    s2 = s2 - hi_43f70 + ((u32)(unsigned long)ref_memcpy + (0));
    branch = (v0 != 0); s1 = a3 + s1;
    if (branch) goto L_43f8c;
    goto L_43f80;
L_43f80:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (20)); goto L_43f98;
L_43f8c:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (16)); goto L_44054;
L_43f98:
    a0 = *(volatile u32 *)(unsigned long)(sp + (112));
    a2 = 4608;
    callee = s2; a1 = a1 + 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_43fa8;
L_43fa8:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(sp + (132));
    a2 = 4608;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (20));
    callee = s2; a1 = a1 + 4610;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_43fc0;
L_43fc0:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 4608;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (20));
    a1 = a1 + 9218; goto L_440ec;
L_43fd4:
    a1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    a0 = a0 + 1;
    v1 = v1 << (0x2 & 31);
    a2 = *(volatile u32 *)(unsigned long)(a1 + (20));
    a1 = a0 * t0;
    a2 = a1 + a2;
    a1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a2 = *(volatile u16 *)(unsigned long)(a2 + (-13826));
    a1 = a1 - a2;
    a2 = (u32)a1 < (u32)(v0);
    if (a2 != 0) v0 = a1;
    v1 = (u32)v0 < (u32)(v1);
    branch = (v1 == 0); a1 = (s32)a0 < (s32)(t7);
    if (branch) goto L_44018;
    goto L_4400c;
L_4400c:
    v1 = v0 >> (0x2 & 31);
    *(volatile u16 *)(unsigned long)(s0 + (48)) = v1;
L_44014:
    a1 = (s32)a0 < (s32)(t7);
L_44018:
    branch = (a1 != 0); v1 = *(volatile u16 *)(unsigned long)(s0 + (48));
    if (branch) goto L_43fd4;
    goto L_44020;
L_44020:
    s1 = a3 + s1;
    t9 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(t9 + (20));
    v0 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v0 = v0 + v1;
    v0 = (u32)v0 < (u32)(s4);
    branch = (v0 != 0); s3 = t7 + -1;
    if (branch) goto L_44194;
    goto L_44040;
L_44040:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (65));
    s2 = hi_44044;
    branch = (v0 == 0); s2 = s2 - hi_44044 + ((u32)(unsigned long)ref_memcpy + (0));
    if (branch) goto L_43f98;
    goto L_44050;
L_44050:
    a1 = *(volatile u32 *)(unsigned long)(t9 + (16));
L_44054:
    a0 = *(volatile u32 *)(unsigned long)(sp + (112));
    a2 = 1154;
    callee = s2; a1 = a1 + 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44064;
L_44064:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(sp + (140));
    a2 = 1154;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    callee = s2; a1 = a1 + 1156;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4407c;
L_4407c:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 1154;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a1 = a1 + 2310; goto L_4418c;
L_44090:
    s2 = hi_44090;
    branch = (v0 != 0); s2 = s2 - hi_44090 + ((u32)(unsigned long)ref_memcpy + (0));
    if (branch) goto L_44130;
    goto L_4409c;
L_4409c:
    a0 = *(volatile u32 *)(unsigned long)(sp + (112));
    v0 = s5 + 2;
    a2 = 4608;
    callee = s2; a1 = a1 + v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_440b0;
L_440b0:
    a1 = 6913;
    s3 = s3 * a1;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(sp + (132));
    a2 = 4608;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (20));
    s5 = s5 + 9218;
    s3 = s3 + 2305;
    s3 = s3 << (0x1 & 31);
    callee = s2; a1 = a1 + s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_440dc;
L_440dc:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 4608;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (20));
    a1 = a1 + s5;
L_440ec:
    a0 = *(volatile u32 *)(unsigned long)(sp + (136));
L_440f0:
    callee = s2; s3 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_440f8;
L_440f8:
    s2 = 0;
    s8 = 0;
    s7 = 0;
    s6 = 0;
    s5 = 0;
    *(volatile u32 *)(unsigned long)(sp + (128)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (124)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (120)) = 0;
    t4 = 0;
    t3 = 0;
    t2 = 0;
    t0 = 0;
    s1 = 0; goto L_442e0;
L_44130:
    s4 = 3464;
    s4 = s3 * s4;
    a1 = *(volatile u32 *)(unsigned long)(t9 + (16));
    a0 = *(volatile u32 *)(unsigned long)(sp + (112));
    a2 = 1154;
    v0 = s4 + 2;
    callee = s2; a1 = a1 + v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44150;
L_44150:
    a1 = 1732;
    s3 = s3 * a1;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(sp + (140));
    a2 = 1154;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    s4 = s4 + 2310;
    s3 = s3 + 578;
    s3 = s3 << (0x1 & 31);
    callee = s2; a1 = a1 + s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4417c;
L_4417c:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 1154;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a1 = a1 + s4;
L_4418c:
    a0 = *(volatile u32 *)(unsigned long)(sp + (144)); goto L_440f0;
L_44194:
    s5 = 13826;
    s5 = s3 * s5;
    v0 = a1 + s5;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = v0 - v1;
    v0 = (u32)s4 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u8 *)(unsigned long)(s0 + (65)); goto L_44090; }
    goto L_441b4;
L_441b4:
    v0 = a1 + 2;
    a0 = 2;
    s3 = 1;
    s2 = 0;
    s8 = 0;
    s7 = 0;
    s6 = 0;
    s5 = 0;
    *(volatile u32 *)(unsigned long)(sp + (128)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (124)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (120)) = 0;
    t4 = 0;
    t3 = 0;
    t2 = 0;
    t0 = 0;
    s1 = 0;
    t5 = 1;
    t1 = 13826;
L_441fc:
    a2 = (s32)t5 < (s32)(t7);
    if (a2 == 0) { v0 = *(volatile u32 *)(unsigned long)(sp + (152)); goto L_442e4; }
    goto L_44208;
L_44208:
    t8 = *(volatile u16 *)(unsigned long)(v0 + (13824));
    a2 = t8 - v1;
    ra = (u32)s4 < (u32)(a2);
    branch = (ra != 0); t6 = t5 * t1;
    if (branch) goto L_44bf8;
    goto L_4421c;
L_4421c:
    t8 = v1 + t8;
    t8 = (u32)t8 < (u32)(s4);
    if (t8 != 0) { t6 = *(volatile u16 *)(unsigned long)(v0 + (-2)); goto L_44bfc; }
    goto L_4422c;
L_4422c:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (65));
    s1 = hi_44230;
    branch = (v0 != 0); s1 = s1 - hi_44230 + ((u32)(unsigned long)ref_memcpy + (0));
    if (branch) goto L_44b60;
    goto L_4423c;
L_4423c:
    a0 = *(volatile u32 *)(unsigned long)(sp + (112));
    v0 = t6 + 2;
    a2 = 4608;
    a1 = a1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (168)) = t6;
    *(volatile u32 *)(unsigned long)(sp + (196)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (192)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (188)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (180)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (176)) = t0;
    callee = s1; *(volatile u32 *)(unsigned long)(sp + (172)) = t5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4426c;
L_4426c:
    t5 = *(volatile u32 *)(unsigned long)(sp + (172));
    a1 = 6913;
    v0 = *(volatile u32 *)(unsigned long)(sp + (152));
    t5 = t5 * a1;
    a3 = *(volatile u32 *)(unsigned long)(sp + (196));
    s4 = v0 << (0x2 & 31);
    a0 = *(volatile u32 *)(unsigned long)(sp + (132));
    s4 = a3 + s4;
    v0 = *(volatile u32 *)(unsigned long)(s4 + (0));
    a2 = 4608;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (20));
    t5 = t5 + 2305;
    t5 = t5 << (0x1 & 31);
    callee = s1; a1 = a1 + t5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_442a8;
L_442a8:
    v0 = *(volatile u32 *)(unsigned long)(s4 + (0));
    t6 = *(volatile u32 *)(unsigned long)(sp + (168));
    a0 = *(volatile u32 *)(unsigned long)(sp + (136));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (20));
    t6 = t6 + 9218;
    a2 = 4608;
    a1 = a1 + t6;
L_442c4:
    callee = s1; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_442cc;
L_442cc:
    t0 = *(volatile u32 *)(unsigned long)(sp + (176));
    t2 = *(volatile u32 *)(unsigned long)(sp + (180));
    t3 = *(volatile u32 *)(unsigned long)(sp + (188));
    t4 = *(volatile u32 *)(unsigned long)(sp + (192));
    s1 = 0;
L_442e0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (152));
L_442e4:
    a1 = *(volatile u32 *)(unsigned long)(sp + (108));
    *(volatile u32 *)(unsigned long)(sp + (196)) = t4;
    s4 = v0 << (0x2 & 31);
    v0 = *(volatile u32 *)(unsigned long)(sp + (148));
    *(volatile u32 *)(unsigned long)(sp + (192)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (180)) = t2;
    v1 = v0 + s4;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = hi_44304;
    v0 = v0 - hi_44304 + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    a0 = a0 + 16;
    *(volatile u32 *)(unsigned long)(sp + (176)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (172)) = v1;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (168)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44320;
L_44320:
    v0 = *(volatile u32 *)(unsigned long)(sp + (168));
    v1 = *(volatile u32 *)(unsigned long)(sp + (172));
    t0 = *(volatile u32 *)(unsigned long)(sp + (176));
    *(volatile u32 *)(unsigned long)(sp + (188)) = v0;
    t2 = *(volatile u32 *)(unsigned long)(sp + (180));
    t3 = *(volatile u32 *)(unsigned long)(sp + (192));
    branch = (s1 == 0); t4 = *(volatile u32 *)(unsigned long)(sp + (196));
    if (branch) goto L_44460;
    goto L_44340;
L_44340:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (184));
    a1 = sp + 108;
    a0 = a0 + 16;
    *(volatile u32 *)(unsigned long)(sp + (180)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (176)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (172)) = t2;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (168)) = t0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44364;
L_44364:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (65));
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(sp + (144)); goto L_443f0; }
    goto L_44370;
L_44370:
    v0 = *(volatile u32 *)(unsigned long)(sp + (160));
    t4 = *(volatile u32 *)(unsigned long)(sp + (180));
    t3 = *(volatile u32 *)(unsigned long)(sp + (176));
    *(volatile u32 *)(unsigned long)(sp + (60)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (136));
    t2 = *(volatile u32 *)(unsigned long)(sp + (172));
    t0 = *(volatile u32 *)(unsigned long)(sp + (168));
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (132));
    *(volatile u32 *)(unsigned long)(sp + (64)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (112));
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (124));
    *(volatile u32 *)(unsigned long)(sp + (24)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (40)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (120));
    *(volatile u32 *)(unsigned long)(sp + (16)) = t3;
    a3 = 1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    v0 = hi_443d0;
    a2 = t2;
    a1 = 1;
    v0 = v0 - hi_443d0 + (u32)(unsigned long)ref_tisp_lsc_mesh_itp;
    callee = v0; a0 = t0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_443e8;
L_443e8:
    v0 = *(volatile u32 *)(unsigned long)(sp + (148)); goto L_44448;
L_443f0:
    a0 = *(volatile u32 *)(unsigned long)(sp + (128));
    *(volatile u32 *)(unsigned long)(sp + (60)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (140));
    *(volatile u32 *)(unsigned long)(sp + (44)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (112));
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
    v0 = hi_4441c;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s6;
    a3 = 1;
    a2 = s5;
    v0 = v0 - hi_4441c + (u32)(unsigned long)ref_tisp_lsc_ring_itp;
    callee = v0; a1 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44444;
L_44444:
    v0 = *(volatile u32 *)(unsigned long)(sp + (148));
L_44448:
    a1 = *(volatile u32 *)(unsigned long)(sp + (108));
    v0 = v0 + s4;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (188));
    callee = v0; a0 = a0 + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44460;
L_44460:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (65));
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(sp + (152));
    if (branch) goto L_4490c;
    goto L_4446c;
L_4446c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (164));
    v0 = *(volatile u32 *)(unsigned long)(sp + (156));
    s5 = 0x100U << 16;
    v1 = v1 << (0x1 & 31);
    *(volatile u32 *)(unsigned long)(sp + (168)) = v1;
    v1 = v1 + 1;
    product = (s64)(s32)v1 * (s32)v1; lo = product; hi = product >> 32;
    v0 = v0 << (0x1 & 31);
    v0 = v0 + 1;
    s6 = sp + 72;
    a2 = 36;
    a1 = 0;
    a0 = s6;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    if (s5 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)s5 / (s32)v0; hi = (s32)s5 % (s32)v0; } else { lo = (s32)s5 < 0 ? 1 : ~0U; hi = s5; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(sp + (204)) = v0;
    v0 = hi_444b4;
    v0 = v0 - hi_444b4 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; s8 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_444c4;
L_444c4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (148));
    s7 = *(volatile u32 *)(unsigned long)(sp + (156));
    *(volatile u32 *)(unsigned long)(sp + (104)) = s5;
    s4 = v0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(s4 + (0));
    *(volatile u32 *)(unsigned long)(sp + (192)) = s6;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = 2048;
    s2 = *(volatile u8 *)(unsigned long)(v1 + (23));
    s3 = *(volatile u8 *)(unsigned long)(v1 + (24));
    s1 = *(volatile u8 *)(unsigned long)(v1 + (25));
    s2 = (s32)v0 >> (s2 & 31);
    s3 = (s32)v0 >> (s3 & 31);
    s1 = (s32)v0 >> (s1 & 31);
    v0 = *(volatile u16 *)(unsigned long)(s0 + (32));
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (72)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (34));
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (76)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (36));
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (80)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (38));
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (84)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (40));
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (88)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (42));
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (92)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (44));
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (96)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (46));
    v0 = v0 * v0;
    *(volatile u32 *)(unsigned long)(sp + (100)) = v0;
    v0 = hi_4455c;
    *(volatile u32 *)(unsigned long)(sp + (156)) = v0;
    v0 = (s32)s2 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(sp + (216)) = v0;
    v0 = hi_4456c;
    *(volatile u32 *)(unsigned long)(sp + (160)) = v0;
L_44574:
    branch = (s7 == 0); v0 = s8 + 1;
    if (branch) goto L_44908;
    goto L_4457c;
L_4457c:
    v0 = v0 * v0;
    s6 = 1;
    s5 = 0;
    *(volatile u32 *)(unsigned long)(sp + (196)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (164));
    *(volatile u32 *)(unsigned long)(sp + (124)) = v0;
L_44594:
    v0 = *(volatile u32 *)(unsigned long)(sp + (124));
    branch = (v0 == 0); a0 = s6 * s6;
    if (branch) goto L_448fc;
    goto L_445a0;
L_445a0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (196));
    v1 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (204));
    a0 = 9;
    v1 = v1 * v0;
L_445b4:
    branch = (s5 == a0); a1 = *(volatile u32 *)(unsigned long)(sp + (192));
    if (branch) goto L_4468c;
    goto L_445bc;
L_445bc:
    v0 = s5 << (0x2 & 31);
    v0 = a1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = (s32)v1 < (s32)(v0);
    branch = (a1 != 0); ;
    if (branch) goto L_445dc;
    goto L_445d4;
L_445d4:
    s5 = s5 + 1; goto L_445b4;
L_445dc:
    branch = (s5 != 0); a0 = 8;
    if (branch) goto L_445f4;
    goto L_445e4;
L_445e4:
    t0 = *(volatile u8 *)(unsigned long)(s0 + (77));
    a3 = *(volatile u8 *)(unsigned long)(s0 + (85));
    v0 = *(volatile u8 *)(unsigned long)(s0 + (93)); goto L_44698;
L_445f4:
    branch = (s5 == a0); a1 = *(volatile u32 *)(unsigned long)(sp + (192));
    if (branch) goto L_4468c;
    goto L_445fc;
L_445fc:
    a2 = s5 + -1;
    a0 = a2 << (0x2 & 31);
    a0 = a1 + a0;
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = v0 - a1;
    branch = ((s32)v0 <= 0); a0 = s0 + s5;
    if (branch) goto L_4467c;
    goto L_44618;
L_44618:
    a2 = s0 + a2;
    t0 = *(volatile u8 *)(unsigned long)(a2 + (77));
    a1 = v1 - a1;
    t4 = v0 - a1;
    product = (s64)(s32)t0 * (s32)t4; lo = product; hi = product >> 32;
    a3 = *(volatile u8 *)(unsigned long)(a0 + (77));
    t3 = *(volatile u8 *)(unsigned long)(a0 + (85));
    v1 = *(volatile u8 *)(unsigned long)(a2 + (93));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (93));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)a1); lo = product; hi = product >> 32;
    a3 = *(volatile u8 *)(unsigned long)(a2 + (85));
    t0 = lo;
    if (t0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)t0 / (s32)v0; hi = (s32)t0 % (s32)v0; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    product = (s64)(s32)a3 * (s32)t4; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t3 * (s32)a1); lo = product; hi = product >> 32;
    a3 = lo;
    if (a3 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a3 / (s32)v0; hi = (s32)a3 % (s32)v0; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; }
    a3 = lo;
    product = (s64)(s32)v1 * (s32)t4; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)a1); lo = product; hi = product >> 32;
    v1 = lo;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = lo; goto L_44698;
L_4467c:
    t0 = *(volatile u8 *)(unsigned long)(a0 + (77));
    a3 = *(volatile u8 *)(unsigned long)(a0 + (85));
    v0 = *(volatile u8 *)(unsigned long)(a0 + (93)); goto L_44698;
L_4468c:
    t0 = *(volatile u8 *)(unsigned long)(s0 + (84));
    a3 = *(volatile u8 *)(unsigned long)(s0 + (92));
    v0 = *(volatile u8 *)(unsigned long)(s0 + (100));
L_44698:
    v1 = (t0 >> 0x7) & ((1U << 0x1) - 1);
    v1 = t0 + v1;
    *(volatile u32 *)(unsigned long)(sp + (172)) = v1;
    v1 = (a3 >> 0x7) & ((1U << 0x1) - 1);
    v1 = a3 + v1;
    *(volatile u32 *)(unsigned long)(sp + (176)) = v1;
    v1 = (v0 >> 0x7) & ((1U << 0x1) - 1);
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(sp + (180)) = v0;
    v0 = -1;
    *(volatile u32 *)(unsigned long)(sp + (120)) = v0;
    v0 = s6 + -1;
    *(volatile u32 *)(unsigned long)(sp + (208)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (172));
    *(volatile u32 *)(unsigned long)(sp + (144)) = s7;
    v0 = (s32)v0 < (s32)(256);
    *(volatile u32 *)(unsigned long)(sp + (212)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (120));
    v1 = *(volatile u32 *)(unsigned long)(sp + (144));
L_446e4:
    s4 = -1;
    v0 = v0 >> (0x1f & 31);
    v0 = v1 - v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (168));
    v0 = v0 * v1;
    *(volatile u32 *)(unsigned long)(sp + (200)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (124));
    *(volatile u32 *)(unsigned long)(sp + (128)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (128));
L_44708:
    t0 = s4 >> (0x1f & 31);
    t0 = v0 - t0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (200));
    t0 = t0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (212));
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (176));
    if (branch) goto L_447a0;
    goto L_44724;
L_44724:
    v0 = *(volatile u32 *)(unsigned long)(sp + (112));
    t4 = t0 << (0x1 & 31);
    a2 = 8;
    t4 = v0 + t4;
    a0 = *(volatile u16 *)(unsigned long)(t4 + (0));
    *(volatile u32 *)(unsigned long)(sp + (224)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (220)) = t4;
    v0 = (s32)s2 < (s32)(a0);
    a0 = a0 - s2;
    if (v0 == 0) a0 = 0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (172));
    a0 = a0 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (156));
    v0 = v0 - hi_4455c + (u32)(unsigned long)ref_tisp_round_int64;
    callee = v0; a1 = (s32)a0 >> (0x1f & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44764;
L_44764:
    a0 = s2 + v0;
    v0 = 4095;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (160));
    a3 = *(volatile u32 *)(unsigned long)(sp + (216));
    v1 = 0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    a2 = s2;
    v0 = v0 - hi_4456c + (u32)(unsigned long)ref_tisp_clip;
    callee = v0; a1 = (s32)a0 >> (0x1f & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44790;
L_44790:
    t4 = *(volatile u32 *)(unsigned long)(sp + (220));
    t0 = *(volatile u32 *)(unsigned long)(sp + (224));
    *(volatile u16 *)(unsigned long)(t4 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (176));
L_447a0:
    v0 = (s32)v0 < (s32)(256);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (180));
    if (branch) goto L_44828;
    goto L_447ac;
L_447ac:
    v0 = *(volatile u32 *)(unsigned long)(sp + (132));
    t4 = t0 << (0x1 & 31);
    a2 = 8;
    t4 = v0 + t4;
    a0 = *(volatile u16 *)(unsigned long)(t4 + (0));
    *(volatile u32 *)(unsigned long)(sp + (224)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (220)) = t4;
    v0 = (s32)s3 < (s32)(a0);
    a0 = a0 - s3;
    if (v0 == 0) a0 = 0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (176));
    a0 = a0 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (156));
    v0 = v0 - hi_4455c + (u32)(unsigned long)ref_tisp_round_int64;
    callee = v0; a1 = (s32)a0 >> (0x1f & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_447ec;
L_447ec:
    a0 = s3 + v0;
    v0 = 4095;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (160));
    v1 = 0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    a2 = s3;
    a3 = (s32)s3 >> (0x1f & 31);
    v0 = v0 - hi_4456c + (u32)(unsigned long)ref_tisp_clip;
    callee = v0; a1 = (s32)a0 >> (0x1f & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44818;
L_44818:
    t4 = *(volatile u32 *)(unsigned long)(sp + (220));
    t0 = *(volatile u32 *)(unsigned long)(sp + (224));
    *(volatile u16 *)(unsigned long)(t4 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (180));
L_44828:
    v0 = (s32)v0 < (s32)(256);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (128));
    if (branch) goto L_448a8;
    goto L_44834;
L_44834:
    v0 = *(volatile u32 *)(unsigned long)(sp + (136));
    t0 = t0 << (0x1 & 31);
    a2 = 8;
    t0 = v0 + t0;
    a0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (220)) = t0;
    v0 = (s32)s1 < (s32)(a0);
    a0 = a0 - s1;
    if (v0 == 0) a0 = 0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (180));
    a0 = a0 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (156));
    v0 = v0 - hi_4455c + (u32)(unsigned long)ref_tisp_round_int64;
    callee = v0; a1 = (s32)a0 >> (0x1f & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44870;
L_44870:
    a0 = s1 + v0;
    v0 = 4095;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (160));
    v1 = 0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    a2 = s1;
    a3 = (s32)s1 >> (0x1f & 31);
    v0 = v0 - hi_4456c + (u32)(unsigned long)ref_tisp_clip;
    callee = v0; a1 = (s32)a0 >> (0x1f & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4489c;
L_4489c:
    t0 = *(volatile u32 *)(unsigned long)(sp + (220));
    *(volatile u16 *)(unsigned long)(t0 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (128));
L_448a8:
    v1 = *(volatile u32 *)(unsigned long)(sp + (208));
    s4 = s4 + 2;
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(sp + (128)) = v0;
    v0 = 3;
    branch = (s4 != v0); v0 = *(volatile u32 *)(unsigned long)(sp + (128));
    if (branch) goto L_44708;
    goto L_448c4;
L_448c4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (120));
    v0 = v0 + 2;
    *(volatile u32 *)(unsigned long)(sp + (120)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (144));
    v0 = v0 + s8;
    *(volatile u32 *)(unsigned long)(sp + (144)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (120));
    branch = (v0 != s4); v1 = *(volatile u32 *)(unsigned long)(sp + (144));
    if (branch) goto L_446e4;
    goto L_448e8;
L_448e8:
    v0 = *(volatile u32 *)(unsigned long)(sp + (124));
    s6 = s6 + 2;
    v0 = v0 + -1;
    *(volatile u32 *)(unsigned long)(sp + (124)) = v0; goto L_44594;
L_448fc:
    s8 = s8 + 2;
    s7 = s7 + -1; goto L_44574;
L_44908:
    v0 = *(volatile u32 *)(unsigned long)(sp + (152));
L_4490c:
    a1 = sp + 108;
    s1 = v0 << (0x2 & 31);
    v0 = *(volatile u32 *)(unsigned long)(sp + (148));
    s2 = v0 + s1;
    a0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (184));
    callee = v0; a0 = a0 + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4492c;
L_4492c:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (65));
    a3 = *(volatile u32 *)(unsigned long)(s2 + (0));
    branch = (v0 != 0); t2 = *(volatile u32 *)(unsigned long)(sp + (112));
    if (branch) goto L_44a24;
    goto L_4493c;
L_4493c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (116));
    t1 = *(volatile u32 *)(unsigned long)(sp + (132));
    a2 = 0;
    t0 = v0 + 9244;
    t3 = 3456;
L_44950:
    v0 = *(volatile u32 *)(unsigned long)(a3 + (8));
    a1 = a2 + 3460;
    a1 = a1 << (0x2 & 31);
    v1 = *(volatile u16 *)(unsigned long)(t2 + (0));
    a1 = v0 + a1;
    v0 = *(volatile u16 *)(unsigned long)(t1 + (0));
    a0 = v1 & 0xfff;
    t4 = a2 + 3461;
    v0 = v0 << (0x18 & 31);
    v1 = a0 | v0;
    v0 = *(volatile u16 *)(unsigned long)(t2 + (2));
    t4 = t4 << (0x2 & 31);
    t2 = t2 + 4;
    v0 = v0 & 0xfff;
    v0 = v0 << (0xc & 31);
    v0 = v1 | v0;
    *(volatile u32 *)(unsigned long)(a1 + (12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (8));
    v1 = *(volatile u16 *)(unsigned long)(t1 + (2));
    a0 = *(volatile u16 *)(unsigned long)(t1 + (0));
    t4 = v0 + t4;
    v0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    v1 = v1 << (0x4 & 31);
    v1 = v1 & 0xffff;
    a1 = (a0 >> 0x8) & ((1U << 0x4) - 1);
    v0 = v0 << (0x1c & 31);
    a0 = a1 | v1;
    v1 = a0 | v0;
    v0 = *(volatile u16 *)(unsigned long)(t0 + (-2));
    t1 = t1 + 4;
    t0 = t0 + 4;
    v0 = v0 & 0xfff;
    v0 = v0 << (0x10 & 31);
    v0 = v1 | v0;
    *(volatile u32 *)(unsigned long)(t4 + (12)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(a3 + (8));
    v0 = a2 + 3462;
    v0 = v0 << (0x2 & 31);
    v0 = v1 + v0;
    v1 = *(volatile u16 *)(unsigned long)(t0 + (-4));
    a2 = a2 + 3;
    v1 = (v1 >> 0x4) & ((1U << 0x8) - 1);
    branch = (a2 != t3); *(volatile u32 *)(unsigned long)(v0 + (12)) = v1;
    if (branch) goto L_44950;
    goto L_44a00;
L_44a00:
    v0 = *(volatile u32 *)(unsigned long)(sp + (148));
L_44a04:
    a1 = *(volatile u32 *)(unsigned long)(sp + (108));
    s1 = v0 + s1;
    a0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (188));
    callee = v0; a0 = a0 + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44a1c;
L_44a1c:
    v0 = 1; goto L_44ca8;
L_44a24:
    v0 = *(volatile u32 *)(unsigned long)(sp + (116));
    t0 = *(volatile u32 *)(unsigned long)(sp + (140));
    a2 = 0;
    t1 = v0 + 4124;
    t3 = 1728;
L_44a38:
    v0 = *(volatile u32 *)(unsigned long)(a3 + (8));
    a1 = a2 + 3460;
    a1 = a1 << (0x2 & 31);
    v1 = *(volatile u16 *)(unsigned long)(t2 + (0));
    a1 = v0 + a1;
    v0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    a0 = v1 & 0xfff;
    t4 = a2 + 3461;
    v0 = v0 << (0x18 & 31);
    v1 = a0 | v0;
    v0 = *(volatile u16 *)(unsigned long)(t2 + (2));
    t4 = t4 << (0x2 & 31);
    t2 = t2 + 2;
    v0 = v0 & 0xfff;
    v0 = v0 << (0xc & 31);
    v0 = v1 | v0;
    *(volatile u32 *)(unsigned long)(a1 + (12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (8));
    v1 = *(volatile u16 *)(unsigned long)(t0 + (2));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t4 = v0 + t4;
    v0 = *(volatile u16 *)(unsigned long)(t1 + (0));
    v1 = v1 << (0x4 & 31);
    v1 = v1 & 0xffff;
    a1 = (a0 >> 0x8) & ((1U << 0x4) - 1);
    a0 = a1 | v1;
    v0 = v0 << (0x1c & 31);
    v1 = a0 | v0;
    v0 = *(volatile u16 *)(unsigned long)(t1 + (-2));
    a0 = a2 + 5189;
    a0 = a0 << (0x2 & 31);
    v0 = v0 & 0xfff;
    v0 = v0 << (0x10 & 31);
    v0 = v1 | v0;
    *(volatile u32 *)(unsigned long)(t4 + (12)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(a3 + (8));
    v0 = a2 + 3462;
    v0 = v0 << (0x2 & 31);
    v0 = v1 + v0;
    v1 = *(volatile u16 *)(unsigned long)(t1 + (0));
    t0 = t0 + 2;
    t1 = t1 + 2;
    v1 = (v1 >> 0x4) & ((1U << 0x8) - 1);
    *(volatile u32 *)(unsigned long)(v0 + (12)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a3 + (8));
    v0 = a2 + 5188;
    v0 = v0 << (0x2 & 31);
    v0 = v1 + v0;
    v1 = *(volatile u16 *)(unsigned long)(t0 + (-2));
    v1 = v1 << (0x18 & 31);
    *(volatile u32 *)(unsigned long)(v0 + (12)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (8));
    a0 = v0 + a0;
    v0 = *(volatile u16 *)(unsigned long)(t0 + (-2));
    v1 = (v0 >> 0x8) & ((1U << 0x4) - 1);
    v0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    v0 = v0 << (0x4 & 31);
    v0 = v0 & 0xffff;
    v0 = v1 | v0;
    *(volatile u32 *)(unsigned long)(a0 + (12)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(a3 + (8));
    v0 = a2 + 5190;
    v0 = v0 << (0x2 & 31);
    v0 = v1 + v0;
    a2 = a2 + 3;
    branch = (a2 != t3); *(volatile u32 *)(unsigned long)(v0 + (12)) = 0;
    if (branch) goto L_44a38;
    goto L_44b44;
L_44b44:
    v0 = *(volatile u32 *)(unsigned long)(sp + (148)); goto L_44a04;
L_44b4c:
    v0 = 0x1U << 16;
    a0 = 0;
    t1 = a3 + s1;
    t0 = 13826; goto L_44014;
L_44b60:
    s4 = 3464;
    s4 = t5 * s4;
    a1 = *(volatile u32 *)(unsigned long)(t9 + (16));
    a0 = *(volatile u32 *)(unsigned long)(sp + (112));
    a2 = 1154;
    *(volatile u32 *)(unsigned long)(sp + (168)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (192)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (188)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (180)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (176)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (172)) = t5;
    v0 = s4 + 2;
    callee = s1; a1 = a1 + v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44b98;
L_44b98:
    t5 = *(volatile u32 *)(unsigned long)(sp + (172));
    a1 = 1732;
    v0 = *(volatile u32 *)(unsigned long)(sp + (152));
    t5 = t5 * a1;
    a3 = *(volatile u32 *)(unsigned long)(sp + (168));
    v0 = v0 << (0x2 & 31);
    a0 = *(volatile u32 *)(unsigned long)(sp + (140));
    a3 = a3 + v0;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a2 = 1154;
    *(volatile u32 *)(unsigned long)(sp + (168)) = a3;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    s4 = s4 + 2310;
    t5 = t5 + 578;
    t5 = t5 << (0x1 & 31);
    callee = s1; a1 = a1 + t5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_44bdc;
L_44bdc:
    a3 = *(volatile u32 *)(unsigned long)(sp + (168));
    a2 = 1154;
    a0 = *(volatile u32 *)(unsigned long)(sp + (144));
    v0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    a1 = a1 + s4; goto L_442c4;
L_44bf8:
    t6 = *(volatile u16 *)(unsigned long)(v0 + (-2));
L_44bfc:
    t6 = t6 + v1;
    t8 = (u32)t6 < (u32)(s4);
    if (t8 == 0) { t5 = t5 + 1; goto L_44c9c; }
    goto L_44c0c;
L_44c0c:
    t8 = (u32)a2 < (u32)(s4);
    if (t8 != 0) { t5 = t5 + 1; goto L_44c9c; }
    goto L_44c18;
L_44c18:
    t0 = v0 + 18434;
    *(volatile u32 *)(unsigned long)(sp + (120)) = t0;
    t0 = v0 + 23042;
    *(volatile u32 *)(unsigned long)(sp + (124)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(t9 + (16));
    s5 = a0 + 1154;
    s6 = a0 + 2308;
    s7 = a0 + 3464;
    s8 = a0 + 4618;
    s2 = a0 + 5772;
    t8 = t0 + a0;
    s5 = t0 + s5;
    s6 = t0 + s6;
    s7 = t0 + s7;
    s8 = t0 + s8;
    s2 = t0 + s2;
    t0 = (u32)s4 < (u32)(a2);
    t2 = v0 + 4608;
    t3 = v0 + 9216;
    t4 = v0 + 13826;
    branch = (t0 == 0); *(volatile u32 *)(unsigned long)(sp + (128)) = t8;
    if (branch) goto L_44c8c;
    goto L_44c70;
L_44c70:
    s3 = s4 - t6;
    t0 = s3 << (0xc & 31);
    s3 = a2 - t6;
    if (s3) { lo = t0 / s3; hi = t0 % s3; } else { lo = ~0U; hi = t0; }
    t0 = v0;
    s3 = lo; goto L_44c94;
L_44c8c:
    t0 = v0;
    s3 = 0;
L_44c94:
    s1 = 1;
    t5 = t5 + 1;
L_44c9c:
    v0 = v0 + 13826;
    a0 = a0 + 3464; goto L_441fc;
L_44ca8:
    ra = *(volatile u32 *)(unsigned long)(sp + (268));
    s8 = *(volatile u32 *)(unsigned long)(sp + (264));
    s7 = *(volatile u32 *)(unsigned long)(sp + (260));
    s6 = *(volatile u32 *)(unsigned long)(sp + (256));
    s5 = *(volatile u32 *)(unsigned long)(sp + (252));
    s4 = *(volatile u32 *)(unsigned long)(sp + (248));
    s3 = *(volatile u32 *)(unsigned long)(sp + (244));
    s2 = *(volatile u32 *)(unsigned long)(sp + (240));
    s1 = *(volatile u32 *)(unsigned long)(sp + (236));
    s0 = *(volatile u32 *)(unsigned long)(sp + (232));
    sp = sp + 272;
    return ((u64)v1 << 32) | v0;
}
