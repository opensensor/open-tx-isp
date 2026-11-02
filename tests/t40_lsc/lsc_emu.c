/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The hand-written LSC chain of tx_isp_t40_lsc_lit.inc built for mipsel as a relocatable object, for tools/ko_emu/diff_lsc.py: Unicorn runs
 * this object and the OEM tx-isp-t40.ko on the same random state and compares memory, return values and the register writes.
 * system_reg_write / memcpy stay undefined (the script hooks them).  Build: tests/t40_lsc/build_emu.sh <cc> <out.o>
 */
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

typedef int spinlock_t;
#define KERN_WARNING ""
#define printk(...) ((void)0)
#define spin_lock_irqsave(l, f) do { (void)(l); (f) = 0; } while (0)
#define spin_unlock_irqrestore(l, f) do { (void)(l); (void)(f); } while (0)
extern int system_reg_write(uint32_t reg, uint32_t val);

#include LSC_INC

_Static_assert(sizeof(struct lsc_lit_bank) == 24 && offsetof(struct lsc_lit_bank, last_gain) == 12 &&
	       offsetof(struct lsc_lit_bank, last_ct) == 16 && offsetof(struct lsc_lit_bank, zone) == 18 &&
	       offsetof(struct lsc_lit_bank, wdr) == 19, "bank layout used by tools/ko_emu/diff_lsc.py");

int emu_valid(uint32_t h, uint32_t w, uint32_t ch, uint32_t cw, uint32_t n) { return lsc_lit_valid_judge(h, w, ch, cw, n); }
int emu_by_ct(uint32_t bank, uint32_t ct, uint32_t force) { return lsc_lit_interp_by_ct(bank, ct, (int)force); }
int emu_by_gain(uint32_t bank, uint32_t gain, uint32_t force) { return lsc_lit_interp_by_gain(bank, gain, (int)force); }
void emu_write_reg(uint32_t bank) { lsc_lit_write_reg(bank); }
void emu_write_lut(uint32_t bank) { lsc_lit_real_write_lut(bank); }
