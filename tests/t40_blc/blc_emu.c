/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The C BLC block (driver/t40/tx_isp_t40_blc.h) built for mipsel as a relocatable object, for tools/ko_emu/diff_blc.py: Unicorn runs this
 * object and the OEM tx-isp-t40.ko on the same random state and compares memory, return values and the register accesses.
 * system_reg_write / system_reg_read / memcpy / memset stay undefined (the script hooks them).
 * Build: tests/t40_blc/build_emu.sh <cc> <out.o> [header-dir]
 */
#include <stdint.h>
#include <string.h>

#define __maybe_unused __attribute__((unused))
extern void system_reg_write(uint32_t reg, uint32_t val);
extern uint32_t system_reg_read(uint32_t reg);

uintptr_t tparamsN[2];

#include "tx_isp_t40_blc.h"

int emu_ag_interp(uint32_t ch, uint32_t idx, uint32_t gain, uint32_t force) { return t40_blc_ag_interp(ch, idx, gain, force); }
int emu_calc(uint32_t ch, uint32_t idx) { t40_blc_calc_digital_gain(ch, idx); return 0; }
int emu_write_reg(uint32_t ch, uint32_t idx, uint32_t mode) { t40_blc_write_reg(ch, idx, mode); return 0; }
int emu_long(uint32_t ch, uint32_t junk, uint32_t gain) { return tisp_blc_ag_long_frame_update(ch, junk, gain); }
int emu_short(uint32_t ch, uint32_t junk, uint32_t gain) { return tisp_blc_ag_short_frame_update(ch, junk, gain); }
int emu_ae_write_dgain(uint32_t ch, uint32_t idx, uint32_t a2, uint32_t a3, uint32_t a4) { return tisp_blc_ae_write_dgain(ch, idx, a2, a3, a4); }
int emu_init(uint32_t ch) { return tisp_blc_init(ch); }
int emu_refresh(uint32_t ch) { return tisp_blc_dn_params_refresh(ch); }
int emu_update(uint32_t ch, uint32_t gain, uint32_t init) { return t40_blc_update(ch, gain, init); }
