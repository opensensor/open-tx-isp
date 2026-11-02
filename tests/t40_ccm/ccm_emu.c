/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The C CCM chain (driver/t40/tx_isp_t40_ccm_chain.h + tx_isp_t40_ccm_conv.h) built for mipsel as a relocatable object, for
 * tools/ko_emu/diff_ccm_chain.py: Unicorn runs this object and the OEM tx-isp-t40.ko on the same random state and compares memory and
 * the register writes.  system_reg_write / memcpy stay undefined (the script hooks them).  Build: tests/t40_ccm/build_emu.sh <cc> <out.o>
 */
#include <stdint.h>
#include <string.h>

extern int system_reg_write(uint32_t reg, uint32_t val);
static inline void t40_ccm_reg_write(uint32_t reg, uint32_t val) { (void)system_reg_write(reg, val); }
#include CFIX_INC
#include "tx_isp_t40_ccm_conv.h"
#include "tx_isp_t40_ccm_chain.h"

#define EMU3(n, call) void emu_##n(uintptr_t a, uintptr_t b, uintptr_t c) { call; }
EMU3(transmit, t40_ccm_params_transmit(a, b, c))
EMU3(refresh, t40_ccm_params_refresh(a, b, c))
EMU3(cm_control, t40_ccm_cm_control(a, (uint32_t)b, c))
EMU3(lut_parameter, t40_ccm_lut_parameter(a, (const uint32_t *)b, (uint32_t)c))
void emu_ct_interpolation(uintptr_t a) { t40_ccm_ct_interpolation(a); }
void emu_ev_ct_update(uintptr_t a, uintptr_t b) { t40_ccm_ev_ct_update(a, (uint32_t)b); }
