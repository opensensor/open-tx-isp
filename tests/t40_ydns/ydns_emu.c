/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The hand-written YDNS block of tx_isp_t40_recovered.c built for mipsel as a relocatable object, for tools/ko_emu/diff_ydns.py: Unicorn
 * runs this object and the OEM tx-isp-t40.ko on the same random state and compares memory, return values and the register writes.
 * The module variables the block uses are defined here under their driver names.  system_reg_write / tisp_simple_intp_int8 / memcpy stay
 * undefined (the script hooks them).  Build: tests/t40_ydns/build_emu.sh <cc> <out.o>
 */
#include <stdint.h>
#include <string.h>

#define EFAULT 14
#define EINVAL 22
extern int system_reg_write(uint32_t reg, uint32_t val);
extern uint32_t tisp_simple_intp_int8(int32_t a, int32_t b, void *c);

uintptr_t main_ydns, main_ydns_comb, main_ydns_intp, sec_ydns, sec_ydns_comb, sec_ydns_intp;
uintptr_t tparamsN[2];

#include YDNS_INC

/* the flags are only read by the init in the driver: keep them in the object */
uint32_t emu_ydns_flag(unsigned int i) { return regtrace_ydns_wdr_flag[i & 1]; }
