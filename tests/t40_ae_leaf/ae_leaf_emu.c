/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The C AE leaf/parameter functions (driver/t40/tx_isp_t40_ae_leaf.h) built for mipsel as a relocatable object, for
 * tools/ko_emu/diff_ae_leaf.py: Unicorn runs this object and the OEM tx-isp-t40.ko on the same random state and compares memory,
 * return values and the calls to the functions that are not part of the header (hardware param, par_calc, set_exprinfo_attr,
 * the AE locks).  fix_point_div_32 / fix_point_mult2_32, memcpy and memset stay undefined (the script hooks them).
 * Build: tests/t40_ae_leaf/build_emu.sh <cc> <out.o> [header-dir]
 */
#include <stdint.h>
#include <string.h>

#define EINVAL 22
#define NULL ((void *)0)

/* state objects of the driver, same names and sizes */
uint8_t pstMainAeOri_storage[0x164] __attribute__((aligned(4)));
uint8_t pstSecAeOri_storage[0x164] __attribute__((aligned(4)));
uintptr_t stMainAeOuter, stSecAeOuter;
uint8_t ae_cache[12] __attribute__((aligned(4)));
uintptr_t tparamsN[2];
int32_t ta_custom_en[2];
uint8_t tisp_ae_main_hist_last[1052] __attribute__((aligned(4)));
uint8_t tisp_ae_sec_hist_last[1052] __attribute__((aligned(4)));
int32_t main_slock, sec_slock, main_slock_hist, sec_slock_hist;
uint32_t tisp_tattr;
uint32_t tisp_ae_main_ctrls_storage[41], tisp_ae_sec_ctrls_storage[41];
uint8_t tisp_par_info[480];

extern void emu_lock(const void *lock, uint32_t *flags);
extern void emu_unlock(const void *lock, uint32_t flags);
extern int32_t fix_point_div_32(int32_t, int32_t, int32_t);
extern int32_t fix_point_mult2_32(int32_t, int32_t, int32_t);
extern int32_t tisp_log2_fixed_to_fixed(uint32_t, uint32_t, uint32_t);
extern int64_t tisp_ae_set_hardware_param(uintptr_t ctx, uint32_t ch);
extern int32_t tisp_ae_par_calc(uint32_t ch, uintptr_t ctx);
extern int32_t tisp_ae_set_exprinfo_attr(uint32_t ch, uintptr_t buf);
extern int32_t system_reg_write(uint32_t reg, uint32_t val);
extern int32_t isp_printf(uint32_t level, const char *fmt, ...);

#define T40_AE_OK(p) 1
#define T40_AE_LOCK(l, f) emu_lock((l), (f))
#define T40_AE_UNLOCK(l, f) emu_unlock((l), (f))
#define T40_AE_CACHE(ch) (((ch) < 2U) ? *(uintptr_t *)(ae_cache + 4U * (ch)) : 0U)

int32_t *tisp_ae_param_now_get(int32_t ch) { return (int32_t *)(ch ? pstSecAeOri_storage : pstMainAeOri_storage); }

#include "tx_isp_t40_ae_leaf.h"
