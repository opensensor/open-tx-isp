/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The hand-written GIB block of tx_isp_t40_recovered.c built for mipsel as a relocatable object, for tools/ko_emu/diff_gib.py: Unicorn
 * runs this object and the OEM tx-isp-t40.ko on the same random state and compares memory, return values and the register writes.
 * The module variables the block uses are defined here under their OEM names.  system_reg_write / system_reg_read / memcpy stay
 * undefined (the script hooks them).  Build: tests/t40_gib/build_emu.sh <cc> <out.o>
 */
#include <stdint.h>
#include <string.h>

typedef unsigned int uint;
#define t40_bringup_param_named(a, b, c, d)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define max_t(t, a, b) ((t)(a) > (t)(b) ? (t)(a) : (t)(b))
extern void system_reg_write(uint32_t reg, uint32_t val);
extern uint32_t system_reg_read(uint32_t reg);

uintptr_t gib_main_tool_para, gib_seco_tool_para, gib_main_real_para, gib_seco_real_para;
uint32_t gib_IR[2] = { 1024, 1024 };
unsigned char tisp_par_info[480];
uintptr_t tparamsN[0x4000];

#include GIB_INC
