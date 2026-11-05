/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e28f0[] __asm__("t32_data_e28f0");
u64 tisp_ccm_calc_para_refresh(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_8b6a4 = ((u32)(unsigned long)ref_t32_data_e28f0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_8b6a4:
    v0 = hi_8b6a4;
    v0 = v0 - hi_8b6a4 + (u32)(unsigned long)ref_t32_data_e28f0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a1 + (70));
    v0 = *(volatile u16 *)(unsigned long)(a1 + (68));
    v0 = a0 - v0;
    a0 = (s32)v0 < (s32)(1025);
    if (a0 != 0) { a0 = (s32)v0 < (s32)(513); goto L_8b6ec; }
    goto L_8b6d4;
L_8b6d4:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x10U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 10; goto L_8b80c;
L_8b6ec:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(257); goto L_8b70c; }
    goto L_8b6f4;
L_8b6f4:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 9; goto L_8b80c;
L_8b70c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(129); goto L_8b72c; }
    goto L_8b714;
L_8b714:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x4U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 8; goto L_8b80c;
L_8b72c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(65); goto L_8b74c; }
    goto L_8b734;
L_8b734:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x2U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 7; goto L_8b80c;
L_8b74c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(33); goto L_8b76c; }
    goto L_8b754;
L_8b754:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x1U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 6; goto L_8b80c;
L_8b76c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(17); goto L_8b78c; }
    goto L_8b774;
L_8b774:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8000;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 5; goto L_8b80c;
L_8b78c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(9); goto L_8b7a8; }
    goto L_8b794;
L_8b794:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 16384;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 4; goto L_8b80c;
L_8b7a8:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(5); goto L_8b7c4; }
    goto L_8b7b0;
L_8b7b0:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 8192;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 3; goto L_8b80c;
L_8b7c4:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(3); goto L_8b7e0; }
    goto L_8b7cc;
L_8b7cc:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 4096;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 2; goto L_8b80c;
L_8b7e0:
    if (a0 != 0) { v0 = v0 ^ 0x2; goto L_8b7fc; }
    goto L_8b7e8;
L_8b7e8:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 2048;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 1; goto L_8b80c;
L_8b7fc:
    a2 = 512;
    if (v0 != 0) a2 = 0;
    a0 = 0;
    lo = a2;
L_8b80c:
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a1 + (38)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (36)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u16 *)(unsigned long)(a0 + (636));
    v0 = *(volatile u16 *)(unsigned long)(a0 + (634));
    v0 = a1 - v0;
    a0 = (s32)v0 < (s32)(1025);
    if (a0 != 0) { a0 = (s32)v0 < (s32)(513); goto L_8b850; }
    goto L_8b838;
L_8b838:
    a0 = (s32)v0 >> (0x1 & 31);
    a1 = 0x10U << 16;
    a0 = a0 + a1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 10; goto L_8b970;
L_8b850:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(257); goto L_8b870; }
    goto L_8b858;
L_8b858:
    a0 = (s32)v0 >> (0x1 & 31);
    a1 = 0x8U << 16;
    a0 = a0 + a1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 9; goto L_8b970;
L_8b870:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(129); goto L_8b890; }
    goto L_8b878;
L_8b878:
    a0 = (s32)v0 >> (0x1 & 31);
    a1 = 0x4U << 16;
    a0 = a0 + a1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 8; goto L_8b970;
L_8b890:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(65); goto L_8b8b0; }
    goto L_8b898;
L_8b898:
    a0 = (s32)v0 >> (0x1 & 31);
    a1 = 0x2U << 16;
    a0 = a0 + a1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 7; goto L_8b970;
L_8b8b0:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(33); goto L_8b8d0; }
    goto L_8b8b8;
L_8b8b8:
    a0 = (s32)v0 >> (0x1 & 31);
    a1 = 0x1U << 16;
    a0 = a0 + a1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 6; goto L_8b970;
L_8b8d0:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(17); goto L_8b8f0; }
    goto L_8b8d8;
L_8b8d8:
    a0 = (s32)v0 >> (0x1 & 31);
    a1 = 0x8000;
    a0 = a0 + a1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 5; goto L_8b970;
L_8b8f0:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(9); goto L_8b90c; }
    goto L_8b8f8;
L_8b8f8:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 16384;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 4; goto L_8b970;
L_8b90c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(5); goto L_8b928; }
    goto L_8b914;
L_8b914:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 8192;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 3; goto L_8b970;
L_8b928:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(3); goto L_8b944; }
    goto L_8b930;
L_8b930:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 4096;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 2; goto L_8b970;
L_8b944:
    if (a0 != 0) { v0 = v0 ^ 0x2; goto L_8b960; }
    goto L_8b94c;
L_8b94c:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 2048;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 1; goto L_8b970;
L_8b960:
    a1 = 512;
    if (v0 != 0) a1 = 0;
    a0 = 0;
    lo = a1;
L_8b970:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = lo;
    *(volatile u16 *)(unsigned long)(v0 + (42)) = a1;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (40)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a1 + (74));
    v0 = *(volatile u16 *)(unsigned long)(a1 + (72));
    v0 = a0 - v0;
    a0 = (s32)v0 < (s32)(1025);
    if (a0 != 0) { a0 = (s32)v0 < (s32)(513); goto L_8b9b8; }
    goto L_8b9a0;
L_8b9a0:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x10U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 10; goto L_8bad8;
L_8b9b8:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(257); goto L_8b9d8; }
    goto L_8b9c0;
L_8b9c0:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 9; goto L_8bad8;
L_8b9d8:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(129); goto L_8b9f8; }
    goto L_8b9e0;
L_8b9e0:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x4U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 8; goto L_8bad8;
L_8b9f8:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(65); goto L_8ba18; }
    goto L_8ba00;
L_8ba00:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x2U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 7; goto L_8bad8;
L_8ba18:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(33); goto L_8ba38; }
    goto L_8ba20;
L_8ba20:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x1U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 6; goto L_8bad8;
L_8ba38:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(17); goto L_8ba58; }
    goto L_8ba40;
L_8ba40:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8000;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 5; goto L_8bad8;
L_8ba58:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(9); goto L_8ba74; }
    goto L_8ba60;
L_8ba60:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 16384;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 4; goto L_8bad8;
L_8ba74:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(5); goto L_8ba90; }
    goto L_8ba7c;
L_8ba7c:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 8192;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 3; goto L_8bad8;
L_8ba90:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(3); goto L_8baac; }
    goto L_8ba98;
L_8ba98:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 4096;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 2; goto L_8bad8;
L_8baac:
    if (a0 != 0) { v0 = v0 ^ 0x2; goto L_8bac8; }
    goto L_8bab4;
L_8bab4:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 2048;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 1; goto L_8bad8;
L_8bac8:
    a2 = 512;
    if (v0 != 0) a2 = 0;
    a0 = 0;
    lo = a2;
L_8bad8:
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a1 + (46)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (44)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a1 + (78));
    v0 = *(volatile u16 *)(unsigned long)(a1 + (76));
    v0 = a0 - v0;
    a0 = (s32)v0 < (s32)(1025);
    if (a0 != 0) { a0 = (s32)v0 < (s32)(513); goto L_8bb1c; }
    goto L_8bb04;
L_8bb04:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x10U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 10; goto L_8bc3c;
L_8bb1c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(257); goto L_8bb3c; }
    goto L_8bb24;
L_8bb24:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 9; goto L_8bc3c;
L_8bb3c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(129); goto L_8bb5c; }
    goto L_8bb44;
L_8bb44:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x4U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 8; goto L_8bc3c;
L_8bb5c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(65); goto L_8bb7c; }
    goto L_8bb64;
L_8bb64:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x2U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 7; goto L_8bc3c;
L_8bb7c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(33); goto L_8bb9c; }
    goto L_8bb84;
L_8bb84:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x1U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 6; goto L_8bc3c;
L_8bb9c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(17); goto L_8bbbc; }
    goto L_8bba4;
L_8bba4:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8000;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 5; goto L_8bc3c;
L_8bbbc:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(9); goto L_8bbd8; }
    goto L_8bbc4;
L_8bbc4:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 16384;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 4; goto L_8bc3c;
L_8bbd8:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(5); goto L_8bbf4; }
    goto L_8bbe0;
L_8bbe0:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 8192;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 3; goto L_8bc3c;
L_8bbf4:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(3); goto L_8bc10; }
    goto L_8bbfc;
L_8bbfc:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 4096;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 2; goto L_8bc3c;
L_8bc10:
    if (a0 != 0) { v0 = v0 ^ 0x2; goto L_8bc2c; }
    goto L_8bc18;
L_8bc18:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 2048;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 1; goto L_8bc3c;
L_8bc2c:
    a2 = 512;
    if (v0 != 0) a2 = 0;
    a0 = 0;
    lo = a2;
L_8bc3c:
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a1 + (50)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (48)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a1 + (62));
    v0 = *(volatile u16 *)(unsigned long)(a1 + (60));
    v0 = a0 - v0;
    a0 = (s32)v0 < (s32)(1025);
    if (a0 != 0) { a0 = (s32)v0 < (s32)(513); goto L_8bc80; }
    goto L_8bc68;
L_8bc68:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x10U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 10; goto L_8bda0;
L_8bc80:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(257); goto L_8bca0; }
    goto L_8bc88;
L_8bc88:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 9; goto L_8bda0;
L_8bca0:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(129); goto L_8bcc0; }
    goto L_8bca8;
L_8bca8:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x4U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 8; goto L_8bda0;
L_8bcc0:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(65); goto L_8bce0; }
    goto L_8bcc8;
L_8bcc8:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x2U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 7; goto L_8bda0;
L_8bce0:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(33); goto L_8bd00; }
    goto L_8bce8;
L_8bce8:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x1U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 6; goto L_8bda0;
L_8bd00:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(17); goto L_8bd20; }
    goto L_8bd08;
L_8bd08:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8000;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 5; goto L_8bda0;
L_8bd20:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(9); goto L_8bd3c; }
    goto L_8bd28;
L_8bd28:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 16384;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 4; goto L_8bda0;
L_8bd3c:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(5); goto L_8bd58; }
    goto L_8bd44;
L_8bd44:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 8192;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 3; goto L_8bda0;
L_8bd58:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(3); goto L_8bd74; }
    goto L_8bd60;
L_8bd60:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 4096;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 2; goto L_8bda0;
L_8bd74:
    if (a0 != 0) { v0 = v0 ^ 0x2; goto L_8bd90; }
    goto L_8bd7c;
L_8bd7c:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 2048;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 1; goto L_8bda0;
L_8bd90:
    a2 = 512;
    if (v0 != 0) a2 = 0;
    a0 = 0;
    lo = a2;
L_8bda0:
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a1 + (54)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (52)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a1 + (66));
    v0 = *(volatile u16 *)(unsigned long)(a1 + (64));
    v0 = a0 - v0;
    a0 = (s32)v0 < (s32)(1025);
    if (a0 != 0) { a0 = (s32)v0 < (s32)(513); goto L_8bde4; }
    goto L_8bdcc;
L_8bdcc:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x10U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 10; goto L_8bf04;
L_8bde4:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(257); goto L_8be04; }
    goto L_8bdec;
L_8bdec:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 9; goto L_8bf04;
L_8be04:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(129); goto L_8be24; }
    goto L_8be0c;
L_8be0c:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x4U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 8; goto L_8bf04;
L_8be24:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(65); goto L_8be44; }
    goto L_8be2c;
L_8be2c:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x2U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 7; goto L_8bf04;
L_8be44:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(33); goto L_8be64; }
    goto L_8be4c;
L_8be4c:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x1U << 16;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 6; goto L_8bf04;
L_8be64:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(17); goto L_8be84; }
    goto L_8be6c;
L_8be6c:
    a0 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8000;
    a0 = a0 + a2;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 5; goto L_8bf04;
L_8be84:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(9); goto L_8bea0; }
    goto L_8be8c;
L_8be8c:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 16384;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 4; goto L_8bf04;
L_8bea0:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(5); goto L_8bebc; }
    goto L_8bea8;
L_8bea8:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 8192;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 3; goto L_8bf04;
L_8bebc:
    if (a0 != 0) { a0 = (s32)v0 < (s32)(3); goto L_8bed8; }
    goto L_8bec4;
L_8bec4:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 4096;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 2; goto L_8bf04;
L_8bed8:
    if (a0 != 0) { v0 = v0 ^ 0x2; goto L_8bef4; }
    goto L_8bee0;
L_8bee0:
    a0 = (s32)v0 >> (0x1 & 31);
    a0 = a0 + 2048;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = 1; goto L_8bf04;
L_8bef4:
    a2 = 512;
    if (v0 != 0) a2 = 0;
    a0 = 0;
    lo = a2;
L_8bf04:
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a1 + (58)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (56)) = a0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
