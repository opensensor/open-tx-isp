/* SPDX-License-Identifier: GPL-2.0 */
/*
 * driver/t40/tx_isp_t40_ct_chain.h (+ the CCM chain it calls) built for mipsel as a relocatable object, for
 * tools/ko_emu/diff_ct_chain.py: Unicorn runs this object and the OEM tx-isp-t40.ko on the same random state and
 * compares memory, register writes and the calls into the CCM/LSC/BCSH/CLM consumers.  The hooks stay undefined
 * symbols (the script records them).  Build: tests/t40_ct/build_emu.sh <cc> <out.o> [header-dir]
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

extern int system_reg_write(uint32_t reg, uint32_t val);
extern uint32_t system_reg_read(uint32_t reg);
extern int tisp_ccm_main_ct_update(uint32_t ct, uint32_t a1);
extern int tisp_bcsh_main_ct_update(uint32_t ct, uint32_t a1);
extern int tisp_lsc_ct_update(uint32_t bank, uint32_t a1, uint32_t ct, uint32_t a3, uint32_t flo, uint32_t fhi);
extern int tisp_clm_ct_update(uint32_t bank, uint32_t a1, uint32_t ct, uint32_t a3, uint32_t flo, uint32_t fhi);
extern int tisp_lsc_interp_by_ct(uint32_t bank, uint32_t a1, uint32_t ct, uint32_t a3, uint32_t flag);
extern int tisp_lsc_prepare_write_lut(uint32_t bank);
extern int tisp_clm_ct_interp(uint32_t bank, uint32_t ct, uint32_t a2);
extern int tisp_clm_prepare_write_lut(uint32_t bank);
static inline void t40_ccm_reg_write(uint32_t reg, uint32_t val) { (void)system_reg_write(reg, val); }
#include CFIX_INC
#include "tx_isp_t40_ccm_conv.h"
#include "tx_isp_t40_ccm_chain.h"
#define T40_CT_TOP()             system_reg_read(0x40)
#define T40_CT_CCM(ct, a1)       tisp_ccm_main_ct_update(ct, a1)
#define T40_CT_BCSH(ct, a1)      tisp_bcsh_main_ct_update(ct, a1)
#define T40_CT_LSC(ct, a1, f)    tisp_lsc_ct_update(0, 0, ct, a1, (uint32_t)(f), (uint32_t)((f) >> 32))
#define T40_CT_CLM(ct, a1, f)    tisp_clm_ct_update(0, 0, ct, a1, (uint32_t)(f), (uint32_t)((f) >> 32))
#define T40_LSC_INTERP(b, ct, a3) tisp_lsc_interp_by_ct(b, 0, ct, a3, 0)
#define T40_LSC_PREPARE(b)       tisp_lsc_prepare_write_lut(b)
#define T40_CLM_INTERP(b, ct)    tisp_clm_ct_interp(b, ct, 1)
#define T40_CLM_PREPARE(b)       tisp_clm_prepare_write_lut(b)
#include "tx_isp_t40_ct_chain.h"

/* the OEM keeps these in module globals; here the script points them at the same guest buffers */
uint64_t *emu_lsc_saved, *emu_clm_saved;
uint8_t *emu_lsc_freq, *emu_clm_freq;
static uint64_t q(uint32_t lo, uint32_t hi) { return (uint64_t)hi << 32 | lo; }
int emu_ct_update(uint32_t ct, uint32_t a1, uint32_t flo, uint32_t fhi) { return t40_ct_update(ct, a1, q(flo, fhi)); }
int emu_ccm_main_ct(uintptr_t ctx, uint32_t ct) { return t40_ccm_main_ct_update(ctx, ct); }
int emu_ccm_main_ev(uintptr_t ctx, uint32_t lo, uint32_t hi) { return t40_ccm_main_ev_update(ctx, lo, hi); }
int emu_lsc_ct(uint32_t bank, uint32_t ct, uint32_t a3, uint32_t flo, uint32_t fhi) { return t40_ctc_lsc_update(bank, ct, a3, q(flo, fhi), emu_lsc_saved, emu_lsc_freq); }
int emu_clm_ct(uint32_t bank, uint32_t ct, uint32_t flo, uint32_t fhi) { return t40_ctc_clm_update(bank, ct, q(flo, fhi), emu_clm_saved, emu_clm_freq); }
