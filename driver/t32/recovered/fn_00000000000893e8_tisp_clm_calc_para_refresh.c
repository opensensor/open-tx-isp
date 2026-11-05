/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e28d0[] __asm__("t32_data_e28d0");
u64 tisp_clm_calc_para_refresh(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_893e8 = ((u32)(unsigned long)ref_t32_data_e28d0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_893e8:
    v0 = hi_893e8;
    v0 = v0 - hi_893e8 + (u32)(unsigned long)ref_t32_data_e28d0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u16 *)(unsigned long)(a1 + (28));
    v0 = *(volatile u16 *)(unsigned long)(a1 + (26));
    v0 = v1 - v0;
    v1 = (s32)v0 < (s32)(1025);
    if (v1 != 0) { v1 = (s32)v0 < (s32)(513); goto L_89430; }
    goto L_89418;
L_89418:
    v1 = (s32)v0 >> (0x1 & 31);
    a2 = 0x10U << 16;
    v1 = v1 + a2;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 10; goto L_89550;
L_89430:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(257); goto L_89450; }
    goto L_89438;
L_89438:
    v1 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8U << 16;
    v1 = v1 + a2;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 9; goto L_89550;
L_89450:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(129); goto L_89470; }
    goto L_89458;
L_89458:
    v1 = (s32)v0 >> (0x1 & 31);
    a2 = 0x4U << 16;
    v1 = v1 + a2;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 8; goto L_89550;
L_89470:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(65); goto L_89490; }
    goto L_89478;
L_89478:
    v1 = (s32)v0 >> (0x1 & 31);
    a2 = 0x2U << 16;
    v1 = v1 + a2;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 7; goto L_89550;
L_89490:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(33); goto L_894b0; }
    goto L_89498;
L_89498:
    v1 = (s32)v0 >> (0x1 & 31);
    a2 = 0x1U << 16;
    v1 = v1 + a2;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 6; goto L_89550;
L_894b0:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(17); goto L_894d0; }
    goto L_894b8;
L_894b8:
    v1 = (s32)v0 >> (0x1 & 31);
    a2 = 0x8000;
    v1 = v1 + a2;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 5; goto L_89550;
L_894d0:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(9); goto L_894ec; }
    goto L_894d8;
L_894d8:
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + 16384;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 4; goto L_89550;
L_894ec:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(5); goto L_89508; }
    goto L_894f4;
L_894f4:
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + 8192;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 3; goto L_89550;
L_89508:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(3); goto L_89524; }
    goto L_89510;
L_89510:
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + 4096;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 2; goto L_89550;
L_89524:
    if (v1 != 0) { v0 = v0 ^ 0x2; goto L_89540; }
    goto L_8952c;
L_8952c:
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + 2048;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 1; goto L_89550;
L_89540:
    a2 = 512;
    if (v0 != 0) a2 = 0;
    v1 = 0;
    lo = a2;
L_89550:
    *(volatile u16 *)(unsigned long)(a0 + (3256)) = v1;
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a0 + (3252)) = v0;
    v1 = *(volatile u16 *)(unsigned long)(a1 + (32));
    v0 = *(volatile u16 *)(unsigned long)(a1 + (30));
    v0 = v1 - v0;
    v1 = (s32)v0 < (s32)(1025);
    if (v1 != 0) { v1 = (s32)v0 < (s32)(513); goto L_8958c; }
    goto L_89574;
L_89574:
    v1 = (s32)v0 >> (0x1 & 31);
    a1 = 0x10U << 16;
    v1 = v1 + a1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 10; goto L_896ac;
L_8958c:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(257); goto L_895ac; }
    goto L_89594;
L_89594:
    v1 = (s32)v0 >> (0x1 & 31);
    a1 = 0x8U << 16;
    v1 = v1 + a1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 9; goto L_896ac;
L_895ac:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(129); goto L_895cc; }
    goto L_895b4;
L_895b4:
    v1 = (s32)v0 >> (0x1 & 31);
    a1 = 0x4U << 16;
    v1 = v1 + a1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 8; goto L_896ac;
L_895cc:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(65); goto L_895ec; }
    goto L_895d4;
L_895d4:
    v1 = (s32)v0 >> (0x1 & 31);
    a1 = 0x2U << 16;
    v1 = v1 + a1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 7; goto L_896ac;
L_895ec:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(33); goto L_8960c; }
    goto L_895f4;
L_895f4:
    v1 = (s32)v0 >> (0x1 & 31);
    a1 = 0x1U << 16;
    v1 = v1 + a1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 6; goto L_896ac;
L_8960c:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(17); goto L_8962c; }
    goto L_89614;
L_89614:
    v1 = (s32)v0 >> (0x1 & 31);
    a1 = 0x8000;
    v1 = v1 + a1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 5; goto L_896ac;
L_8962c:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(9); goto L_89648; }
    goto L_89634;
L_89634:
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + 16384;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 4; goto L_896ac;
L_89648:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(5); goto L_89664; }
    goto L_89650;
L_89650:
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + 8192;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 3; goto L_896ac;
L_89664:
    if (v1 != 0) { v1 = (s32)v0 < (s32)(3); goto L_89680; }
    goto L_8966c;
L_8966c:
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + 4096;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 2; goto L_896ac;
L_89680:
    if (v1 != 0) { v0 = v0 ^ 0x2; goto L_8969c; }
    goto L_89688;
L_89688:
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + 2048;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 1; goto L_896ac;
L_8969c:
    a1 = 512;
    if (v0 != 0) a1 = 0;
    v1 = 0;
    lo = a1;
L_896ac:
    *(volatile u16 *)(unsigned long)(a0 + (3258)) = v1;
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a0 + (3254)) = v0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
