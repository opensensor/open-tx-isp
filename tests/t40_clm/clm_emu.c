/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The C CLM block (driver/t40/tx_isp_t40_clm.h, with the CLM step of tx_isp_t40_ct_chain.h) built for mipsel as a relocatable
 * object, for tools/ko_emu/diff_clm.py: Unicorn runs this object and the OEM tx-isp-t40.ko on the same random state and compares
 * memory, return values and the register accesses.  system_reg_write / system_reg_read / memcpy / memset / emu_alloc stay
 * undefined (the script hooks them).
 * Build: tests/t40_clm/build_emu.sh <cc> <out.o> [header-dir]
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

extern int32_t system_reg_write(uint32_t reg, uint32_t val);
extern uint32_t system_reg_read(uint32_t reg);
extern void *emu_alloc(uint32_t n);

uintptr_t tparamsN[2];

#define T40_CLM_ALLOC(n) emu_alloc(n)
#define T40_CLM_FREE(p)  do { } while (0)
#include "tx_isp_t40_clm.h"

#define T40_CLM_INTERP(bank, ct) t40_clm_ct_interp(bank, ct, 1)
#define T40_CLM_PREPARE(bank)    t40_clm_prepare_write_lut(bank)
#define T40_CT_TOP()             system_reg_read(0x40U)
#define T40_LSC_INTERP(b, ct, a3) 1
#define T40_LSC_PREPARE(b)        do { } while (0)
#define T40_CT_CCM(ct, a1)        do { } while (0)
#define T40_CT_LSC(ct, a1, f)     do { } while (0)
#define T40_CT_BCSH(ct, a1)       do { } while (0)
#define T40_CT_CLM(ct, a1, f)     t40_ctc_clm_update(0, ct, f, t40_clm_frame_saved, t40_clm_wlut_frequency)
#define CCM_U16(a) (*(volatile uint16_t *)(uintptr_t)(a))
#define CCM_U32(a) (*(volatile uint32_t *)(uintptr_t)(a))
static int32_t t40_ccm_ev_ct_update(uintptr_t ctx, uint32_t a1) { (void)ctx; (void)a1; return 0; }
#include "tx_isp_t40_ct_chain.h"

int emu_init(uint32_t b) { return t40_clm_init(b); }
int emu_interp(uint32_t b, uint32_t ct, uint32_t f) { return t40_clm_ct_interp(b, ct, f); }
int emu_csc(uint32_t b) { return t40_clm_write_csc_para(b); }
int emu_write(uint32_t b) { return t40_clm_real_write_lut(b); }
int emu_prepare(uint32_t b) { return t40_clm_prepare_write_lut(b); }
int emu_times(uint32_t b, uint32_t *out) { return t40_clm_get_wlut_times(b, out); }
int emu_refresh(uint32_t b) { return t40_clm_dn_params_refresh(b); }
int emu_wdr(uint32_t b, uint32_t en) { return t40_clm_wdr_en(b, en); }
int emu_deinit(uint32_t b) { return t40_clm_deinit(b); }
/* OEM tisp_clm_ct_update(bank, -, ct, -, fnum lo, fnum hi) */
int emu_ct_update(uint32_t b, uint32_t junk, uint32_t ct, uint32_t junk2, uint32_t lo, uint32_t hi)
{
	(void)junk; (void)junk2;
	return t40_ctc_clm_update(b, ct, ((uint64_t)hi << 32) | lo, t40_clm_frame_saved, t40_clm_wlut_frequency);
}
