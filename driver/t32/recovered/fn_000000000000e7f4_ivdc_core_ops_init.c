/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c5b9c[] __asm__("t32_data_c5b9c");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_t32_data_d9894[] __asm__("t32_data_d9894");
extern unsigned char ref_msleep[] __asm__("msleep");
extern unsigned char ref___udelay[] __asm__("__udelay");
extern unsigned char ref_t32_data_c5bb8[] __asm__("t32_data_c5bb8");
u64 ivdc_core_ops_init(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_e834 = ((u32)(unsigned long)ref_t32_data_c5b9c + 0x8000U) & 0xffff0000U;
    const u32 hi_e838 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_e868 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_e874 = ((u32)(unsigned long)ref_t32_data_d9894 + 0x8000U) & 0xffff0000U;
    const u32 hi_e8b0 = (((u32)(unsigned long)ref_msleep + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_e8dc = (((u32)(unsigned long)ref___udelay + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_e960 = ((u32)(unsigned long)ref_t32_data_c5bb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_e964 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_e994 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_e99c = ((u32)(unsigned long)ref_t32_data_d9894 + 0x8000U) & 0xffff0000U;
    const u32 hi_e818 = ((u32)(unsigned long)ref_t32_data_c5b9c + 0x8000U) & 0xffff0000U;
    const u32 hi_e824 = ((u32)(unsigned long)ref_t32_data_c5b9c + 0x8000U) & 0xffff0000U;
    const u32 hi_e950 = ((u32)(unsigned long)ref_t32_data_c5bb8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
L_e7f4:
    sp = sp + -40;
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    branch = (a0 == 0); *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    if (branch) goto L_e834;
    goto L_e810;
L_e810:
    v0 = (u32)a0 < (u32)(-4095);
    if (v0 == 0) { a1 = hi_e818; goto L_e838; }
    goto L_e81c;
L_e81c:
    s0 = *(volatile u32 *)(unsigned long)(a0 + (280));
    if (s0 == 0) { a1 = hi_e824; goto L_e838; }
    goto L_e828;
L_e828:
    v0 = (u32)s0 < (u32)(-4095);
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(a1 + (0)); goto L_e854; }
    goto L_e834;
L_e834:
    a1 = hi_e834;
L_e838:
    v0 = hi_e838;
    a1 = a1 - hi_e834 + (u32)(unsigned long)ref_t32_data_c5b9c;
    v0 = v0 - hi_e838 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e84c;
L_e84c:
    v0 = -22; goto L_e9a8;
L_e854:
    branch = (v0 == 0); a0 = *(volatile u32 *)(unsigned long)(s0 + (444));
    if (branch) goto L_e984;
    goto L_e85c;
L_e85c:
    v1 = 3;
    branch = (a0 == v1); v0 = 0;
    if (branch) goto L_e9a8;
    goto L_e868;
L_e868:
    s1 = hi_e868;
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_e868 + (u32)(unsigned long)ref_t32_data_d9014);
    branch = (v0 != 0); v1 = hi_e874;
    if (branch) goto L_e890;
    goto L_e878;
L_e878:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a1 = 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_e874 + (u32)(unsigned long)ref_t32_data_d9894) = 0;
    *(volatile u32 *)(unsigned long)(a0 + (92)) = a1;
    ra = *(volatile u32 *)(unsigned long)(sp + (36)); goto L_e9ac;
L_e890:
    v1 = *(volatile u32 *)(unsigned long)(v1 - hi_e874 + (u32)(unsigned long)ref_t32_data_d9894);
    branch = (v0 == v1); s2 = 0xb000U << 16;
    if (branch) goto L_e8d4;
    goto L_e89c;
L_e89c:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (196));
    v1 = 0x8U << 16;
    a0 = 1;
    v0 = v0 | v1;
    *(volatile u32 *)(unsigned long)(s2 + (196)) = v0;
    v0 = hi_e8b0;
    v0 = v0 - hi_e8b0 + ((u32)(unsigned long)ref_msleep + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e8c0;
L_e8c0:
    v1 = *(volatile u32 *)(unsigned long)(s2 + (196));
    v0 = 0xfff7U << 16;
    v0 = v0 | 0xffff;
    v0 = v1 & v0;
    *(volatile u32 *)(unsigned long)(s2 + (196)) = v0;
L_e8d4:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
L_e8d8:
    v1 = 1;
    s3 = hi_e8dc;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
L_e8e4:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = v1 & 0x1;
    branch = (v1 == 0); s2 = 201;
    if (branch) goto L_e914;
    goto L_e8f8;
L_e8f8:
    s2 = s2 + -1;
L_e8fc:
    branch = (s2 == 0); v0 = s3 - hi_e8dc + ((u32)(unsigned long)ref___udelay + (0));
    if (branch) goto L_e8e4;
    goto L_e904;
L_e904:
    callee = v0; a0 = 1000;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e90c;
L_e90c:
    s2 = s2 + -1; goto L_e8fc;
L_e914:
    a2 = *(volatile u32 *)(unsigned long)(s1 - hi_e868 + (u32)(unsigned long)ref_t32_data_d9014);
    v1 = 1;
    if (a2 != v1) { v1 = 2; goto L_e92c; }
    goto L_e924;
L_e924:
    v1 = 0x4U << 16; goto L_e958;
L_e92c:
    if (a2 != v1) { v1 = 3; goto L_e93c; }
    goto L_e934;
L_e934:
    v1 = 0x3c4U << 16; goto L_e958;
L_e93c:
    if (a2 != v1) { v1 = 4; goto L_e94c; }
    goto L_e944;
L_e944:
    v1 = 0x5c4U << 16; goto L_e958;
L_e94c:
    branch = (a2 != v1); a1 = hi_e950;
    if (branch) goto L_e964;
    goto L_e954;
L_e954:
    v1 = 0x7c4U << 16;
L_e958:
    v1 = v1 + 4352;
    *(volatile u32 *)(unsigned long)(v0 + (92)) = v1;
    a1 = hi_e960;
L_e964:
    v0 = hi_e964;
    a1 = a1 - hi_e960 + (u32)(unsigned long)ref_t32_data_c5bb8;
    v0 = v0 - hi_e964 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e978;
L_e978:
    v0 = 3;
    *(volatile u32 *)(unsigned long)(s0 + (444)) = v0; goto L_e994;
L_e984:
    v1 = 2;
    branch = (a0 == v1); ra = *(volatile u32 *)(unsigned long)(sp + (36));
    if (branch) goto L_e9ac;
    goto L_e990;
L_e990:
    *(volatile u32 *)(unsigned long)(s0 + (444)) = v1;
L_e994:
    v0 = hi_e994;
    v1 = *(volatile u32 *)(unsigned long)(v0 - hi_e994 + (u32)(unsigned long)ref_t32_data_d9014);
    v0 = hi_e99c;
    *(volatile u32 *)(unsigned long)(v0 - hi_e99c + (u32)(unsigned long)ref_t32_data_d9894) = v1;
    v0 = 0;
L_e9a8:
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
L_e9ac:
    s3 = *(volatile u32 *)(unsigned long)(sp + (32));
    s2 = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 40;
    return ((u64)v1 << 32) | v0;
}
