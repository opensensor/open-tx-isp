/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_bf860[] __asm__("t32_data_bf860");
extern unsigned char ref_t32_data_bf9a8[] __asm__("t32_data_bf9a8");
extern unsigned char ref_t32_data_ce1f0[] __asm__("t32_data_ce1f0");
extern unsigned char ref_t32_data_ce1e0[] __asm__("t32_data_ce1e0");
extern unsigned char ref_t32_data_ce1d0[] __asm__("t32_data_ce1d0");
extern unsigned char ref_t32_data_d6c67[] __asm__("t32_data_d6c67");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 lce_hist_method_16bit_simd(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[186] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_54484 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_544fc = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_544f8 = ((u32)(unsigned long)ref_t32_data_bf860 + 0x8000U) & 0xffff0000U;
    const u32 hi_5451c = ((u32)(unsigned long)ref_t32_data_bf9a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_546f8 = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_546fc = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_54700 = ((u32)(unsigned long)ref_t32_data_ce1d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_547b8 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[122];
L_54438:
    sp = sp + -488;
    *(volatile u32 *)(unsigned long)(sp + (484)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (476)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (472)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (468)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (464)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (456)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (452)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (448)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (480)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (460)) = s3;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (4));
    t2 = *(volatile u32 *)(unsigned long)(a2 + (20));
    t4 = *(volatile u32 *)(unsigned long)(a2 + (24));
    t0 = *(volatile u32 *)(unsigned long)(a2 + (28));
    t3 = *(volatile u32 *)(unsigned long)(a2 + (32));
    t5 = *(volatile u32 *)(unsigned long)(a2 + (36));
    t1 = *(volatile u32 *)(unsigned long)(a2 + (40));
    s4 = sp + 144;
    s7 = hi_54484;
    s7 = s7 - hi_54484 + ((u32)(unsigned long)ref_memset + (0));
    s8 = *(volatile u32 *)(unsigned long)(a2 + (44));
    s3 = *(volatile u32 *)(unsigned long)(a2 + (48));
    s5 = a0;
    a2 = 128;
    a0 = s4;
    s1 = a1;
    s6 = sp + 16;
    a1 = 0;
    s0 = v1 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (440)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (436)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (432)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (428)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (424)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (420)) = t5;
    *(volatile u32 *)(unsigned long)(sp + (416)) = t1;
    callee = s7; s2 = sp + 336;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_544d4;
L_544d4:
    a2 = 128;
    a1 = 0;
    callee = s7; a0 = s6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_544e4;
L_544e4:
    a2 = 64;
    a1 = 0;
    callee = s7; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_544f4;
L_544f4:
    a3 = sp + 272;
    a1 = hi_544f8;
    v0 = hi_544fc;
    a0 = a3;
    a2 = 64;
    v0 = v0 - hi_544fc + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a1 = a1 - hi_544f8 + (u32)(unsigned long)ref_t32_data_bf860;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_54514;
L_54514:
    v1 = *(volatile u32 *)(unsigned long)(sp + (440));
    a3 = v0;
    v0 = hi_5451c;
    v1 = v1 & 0xff;
    a0 = v1 << (0x1 & 31);
    v0 = v0 - hi_5451c + (u32)(unsigned long)ref_t32_data_bf9a8;
    v0 = a0 + v0;
    t5 = *(volatile u32 *)(unsigned long)(sp + (420));
    t4 = *(volatile u32 *)(unsigned long)(sp + (432));
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a0 = t5 & 0xffff;
    v0 = t4 & 0xff;
    v0 = v0 * a1;
    t0 = *(volatile u32 *)(unsigned long)(sp + (428));
    t3 = *(volatile u32 *)(unsigned long)(sp + (424));
    t2 = *(volatile u32 *)(unsigned long)(sp + (436));
    t1 = *(volatile u32 *)(unsigned long)(sp + (416));
    t0 = t0 & 0xff;
    t3 = t3 & 0xffff;
    t2 = t2 & 0xff;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t3; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t2; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[6] = tmp; }
    t0 = v1 + -4;
    a0 = a0 * a1;
    a2 = (s32)v0 >> (0xa & 31);
    v0 = 1024;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a2; vx[2] = tmp; }
    v0 = 0;
    a0 = (s32)a0 >> (0xa & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[0] = tmp; }
L_5459c:
    a1 = (s32)t0 < (s32)(v0);
    branch = (a1 != 0); a1 = v0 + 1;
    if (branch) goto L_545f0;
    goto L_545a8;
L_545a8:
    *(volatile u32 *)(unsigned long)(sp + (404)) = a1;
    a1 = v0 + 2;
    *(volatile u32 *)(unsigned long)(sp + (408)) = a1;
    a1 = v0 + 3;
    *(volatile u32 *)(unsigned long)(sp + (400)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (412)) = a1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(sp + (400)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[3].w[i] | vx[3].w[i]; vx[10] = tmp; }
    a1 = v0 << (0x2 & 31);
    v0 = v0 + 4;
    v0 = v0 & 0xff;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[10].w[i] + ((u32)vx[2].w[i] * (u32)vx[4].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[9].w[i] + ((u32)vx[0].w[i] * (u32)vx[4].w[i]); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (a1)))[i] = vx[9].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (a1)))[i] = vx[10].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] + (u32)vx[10].w[i]; vx[6] = tmp; } goto L_5459c;
L_545f0:
    t0 = 0;
L_545f4:
    a1 = (u32)v0 < (u32)(s0);
    branch = (a1 == 0); t5 = a0 * v0;
    if (branch) goto L_5462c;
    goto L_54600;
L_54600:
    a1 = v0 << (0x2 & 31);
    a1 = s6 + a1;
    t4 = t5 + t3;
    t5 = a2 * v0;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = t4;
    v0 = v0 + 1;
    v0 = v0 & 0xff;
    t4 = t5 + t2;
    *(volatile u32 *)(unsigned long)(a1 + (128)) = t4;
    t0 = t0 + t4; goto L_545f4;
L_5462c:
    v1 = v1 << (0x2 & 31);
    v1 = s6 + v1;
    t1 = t1 & 0xffff;
    s8 = s8 & 0xffff;
    s0 = s0 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = t1;
    *(volatile u32 *)(unsigned long)(v1 + (128)) = s8;
    t0 = t0 + s8;
    v0 = s0 & 0xff;
    a1 = 31;
    t1 = 30;
    t4 = 29;
    t5 = 28;
L_54660:
    v1 = (u32)v0 < (u32)(29);
    branch = (v1 == 0); v1 = a1 - v0;
    if (branch) goto L_546b8;
    goto L_5466c;
L_5466c:
    *(volatile u32 *)(unsigned long)(sp + (400)) = v1;
    v1 = t1 - v0;
    *(volatile u32 *)(unsigned long)(sp + (404)) = v1;
    v1 = t4 - v0;
    *(volatile u32 *)(unsigned long)(sp + (408)) = v1;
    v1 = t5 - v0;
    *(volatile u32 *)(unsigned long)(sp + (412)) = v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(sp + (400)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[3].w[i] | vx[3].w[i]; vx[10] = tmp; }
    v1 = v0 << (0x2 & 31);
    v0 = v0 + 4;
    v0 = v0 & 0xff;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[10].w[i] + ((u32)vx[2].w[i] * (u32)vx[4].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[9].w[i] + ((u32)vx[0].w[i] * (u32)vx[4].w[i]); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v1)))[i] = vx[9].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (v1)))[i] = vx[10].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] + (u32)vx[10].w[i]; vx[6] = tmp; } goto L_54660;
L_546b8:
    t1 = 31;
L_546bc:
    v1 = (u32)v0 < (u32)(32);
    branch = (v1 == 0); v1 = t1 - v0;
    if (branch) goto L_546f8;
    goto L_546c8;
L_546c8:
    t5 = a0 * v1;
    a1 = v0 << (0x2 & 31);
    a1 = s6 + a1;
    v0 = v0 + 1;
    v0 = v0 & 0xff;
    t4 = t5 + t3;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = t4;
    t4 = a2 * v1;
    v1 = t4 + t2;
    *(volatile u32 *)(unsigned long)(a1 + (128)) = v1;
    t0 = t0 + v1; goto L_546bc;
L_546f8:
    t1 = hi_546f8;
    a2 = hi_546fc;
    a1 = hi_54700;
    t1 = t1 - hi_546f8 + (u32)(unsigned long)ref_t32_data_ce1f0;
    a2 = a2 - hi_546fc + (u32)(unsigned long)ref_t32_data_ce1e0;
    a1 = a1 - hi_54700 + (u32)(unsigned long)ref_t32_data_ce1d0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[4] = tmp; }
    v1 = 0;
    a0 = 64;
L_54728:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s5 + (v1)))[i]; }
    v0 = v1 << (0x1 & 31);
    v0 = s6 + v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] - (u32)vx[7].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] - (u32)vx[7].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[8].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] * (u32)vx[8].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[3].w[i] >> (7 & 31); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (7 & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] + (u32)vx[7].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[7].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] < vx[3].w[i]) ? ~0U : 0; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] < vx[1].w[i]) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[3].w[i] & ~vx[0].w[i]) | (vx[2].w[i] & vx[0].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[11].w[i]) | (vx[9].w[i] & vx[11].w[i]); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] + (u32)vx[2].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] + (u32)vx[0].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s2 + (v1)))[i] = vx[0].b[i]; }
    v1 = v1 + 16;
    branch = (v1 != a0); v0 = (s32)vx[4].w[0];
    if (branch) goto L_54728;
    goto L_54790;
L_54790:
    v1 = (s32)vx[4].w[1];
    a0 = 0x8000;
    v1 = v0 + v1;
    v0 = (s32)vx[4].w[2];
    v0 = v1 + v0;
    v1 = (s32)vx[4].w[3];
    v1 = v0 + v1;
    a0 = a0 - v1;
    branch = ((s32)a0 >= 0); v0 = (s32)vx[6].w[3];
    if (branch) goto L_54848;
    goto L_547b8;
L_547b8:
    v0 = hi_547b8;
    a0 = *(volatile u8 *)(unsigned long)(v0 - hi_547b8 + (u32)(unsigned long)ref_t32_data_d6c67);
    v0 = 1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a0 = v0 << (a0 & 31);
    v0 = v1 << (0x5 & 31);
    v0 = (s32)v0 >> (0xe & 31);
    v0 = v0 + 1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    s3 = s3 & 0xff;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = s3; vx[3] = tmp; }
    v1 = 64;
    v0 = lo;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[2] = tmp; }
    v0 = 0;
L_547fc:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s2 + (v0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (vx[3].w[i] & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[4].w[i] >> (vx[3].w[i] & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[4].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (v0)))[i] = vx[1].b[i]; }
    v0 = v0 + 16;
    branch = (v0 != v1); ;
    if (branch) goto L_547fc;
    goto L_5482c;
L_5482c:
    v1 = (s32)vx[0].w[1];
    v0 = (s32)vx[0].w[0];
    v0 = v0 + v1;
    v1 = (s32)vx[0].w[2];
    v0 = v0 + v1;
    v1 = (s32)vx[0].w[3]; goto L_548ec;
L_54848:
    v1 = (s32)vx[6].w[2];
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    v1 = v1 + v0;
    v0 = (s32)vx[6].w[1];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[1] = tmp; }
    v1 = v1 + v0;
    v0 = (s32)vx[6].w[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[6] = tmp; }
    a0 = 64;
    v0 = v1 + v0;
    v0 = v0 + t0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[0] = tmp; }
    v0 = 0;
    v1 = v0 << (0x1 & 31);
L_54888:
    v1 = s4 + v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v1 + (16)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(s2 + (v0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[6].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[6].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[9].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] ? vx[4].w[i] / vx[0].w[i] : ~0U; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] ? vx[3].w[i] / vx[0].w[i] : ~0U; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] + (u32)vx[2].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] + (u32)vx[7].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[4].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[2].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (v0)))[i] = vx[2].b[i]; }
    v0 = v0 + 16;
    branch = (v0 != a0); v1 = v0 << (0x1 & 31);
    if (branch) goto L_54888;
    goto L_548d4;
L_548d4:
    v1 = (s32)vx[1].w[1];
    v0 = (s32)vx[1].w[0];
    v0 = v0 + v1;
    v1 = (s32)vx[1].w[2];
    v0 = v0 + v1;
    v1 = (s32)vx[1].w[3];
L_548ec:
    v0 = v0 + v1;
    a0 = 0x8000;
    v0 = a0 - v0;
    v1 = v0 << (0x5 & 31);
    v1 = (s32)v1 >> (0xa & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = v1; vx[0] = tmp; }
    v1 = 32;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(sp + (320)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(sp + (288)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(sp + (304)))[i]; }
    ra = *(volatile u32 *)(unsigned long)(sp + (484));
    s8 = *(volatile u32 *)(unsigned long)(sp + (480));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[0].h[i] + (u16)vx[3].h[i]; vx[3] = tmp; }
    s7 = *(volatile u32 *)(unsigned long)(sp + (476));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[0].h[i] + (u16)vx[2].h[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[0].h[i] + (u16)vx[1].h[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[0].h[i] + (u16)vx[4].h[i]; vx[0] = tmp; }
    s6 = *(volatile u32 *)(unsigned long)(sp + (472));
    s5 = *(volatile u32 *)(unsigned long)(sp + (468));
    s4 = *(volatile u32 *)(unsigned long)(sp + (464));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (320)))[i] = vx[0].b[i]; }
    v1 = *(volatile u16 *)(unsigned long)(sp + (334));
    s3 = *(volatile u32 *)(unsigned long)(sp + (460));
    s2 = *(volatile u32 *)(unsigned long)(sp + (456));
    s0 = *(volatile u32 *)(unsigned long)(sp + (448));
    a0 = hi;
    v1 = a0 + v1;
    *(volatile u16 *)(unsigned long)(sp + (334)) = v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a3 + (48)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s1 + (0)))[i] = vx[3].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s1 + (16)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s1 + (32)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s1 + (48)))[i] = vx[0].b[i]; }
    s1 = *(volatile u32 *)(unsigned long)(sp + (452));
    sp = sp + 488;
    return ((u64)v1 << 32) | v0;
}
