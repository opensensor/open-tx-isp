/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The C DMSC chain (driver/t40/tx_isp_t40_dmsc_chain.h) built for mipsel as a relocatable object, for tools/ko_emu/diff_dmsc_chain.py:
 * Unicorn runs this object and the OEM tx-isp-t40.ko on the same random state and compares memory, return values and the register writes.
 * system_reg_write / tisp_simple_intp_int8 / tisp_simple_intp_int16 stay undefined (the script hooks them).
 * Build: tests/t40_dmsc/build_emu.sh <cc> <out.o> [header-dir]
 */
#include <stdint.h>

extern int system_reg_write(uint32_t reg, uint32_t val);
extern uint32_t tisp_simple_intp_int8(int32_t a, int32_t b, void *c);
extern uint32_t tisp_simple_intp_int16(int32_t a, int32_t b, void *c);
static inline int32_t t40_dmsc_reg_write(uint32_t reg, uint32_t val) { return system_reg_write(reg, val); }
#include "tx_isp_t40_dmsc_chain.h"

void emu_wdr_en(uintptr_t par, uintptr_t comb, uintptr_t wdr) { t40_dmsc_comb_fill(par, comb, (uint32_t)wdr); }
void emu_intp(uintptr_t par, uintptr_t comb, uintptr_t intp, uintptr_t gain) { t40_dmsc_intp(par, comb, intp, (uint32_t)gain); }
int emu_reg_trig(uintptr_t ch) { return t40_dmsc_reg_trig((uint32_t)ch); }
void emu_noref(uintptr_t ch, uintptr_t par, uintptr_t comb) { t40_dmsc_noref_reg_cfg((uint32_t)ch, par, comb); }
void emu_ref(uintptr_t ch, uintptr_t par, uintptr_t comb, uintptr_t intp) { t40_dmsc_ref_reg_cfg((uint32_t)ch, par, comb, intp); }
