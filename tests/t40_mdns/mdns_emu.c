/* SPDX-License-Identifier: GPL-2.0 */
/*
 * The C MDNS chain (driver/t40/tx_isp_t40_mdns_chain.h) built for mipsel as a relocatable object, for tools/ko_emu/diff_mdns_chain.py:
 * Unicorn runs this object and the OEM tx-isp-t40.ko on the same random state and compares memory, return values and the register writes.
 * system_reg_write / tisp_simple_intp_int8 / get_isp_memopt stay undefined (the script hooks them).
 * Build: tests/t40_mdns/build_emu.sh <cc> <out.o> [header-dir]
 */
#include <stdint.h>
#include <string.h>

extern int system_reg_write(uint32_t reg, uint32_t val);
extern uint32_t tisp_simple_intp_int8(int32_t a, int32_t b, void *c);
extern uint32_t get_isp_memopt(void);
static inline int32_t t40_mdns_reg_write(uint32_t reg, uint32_t val) { return system_reg_write(reg, val); }
#include "tx_isp_t40_mdns_chain.h"

static void mk(struct t40_mdns_ch *c, uintptr_t ch, uintptr_t par, uintptr_t comb, uintptr_t intp, uintptr_t w, uintptr_t h, uintptr_t gain_old)
{
	c->ch = (uint32_t)ch; c->par = par; c->comb = comb; c->intp = intp; c->width = (uint32_t)w; c->height = (uint32_t)h; c->gain_old = (uint32_t *)gain_old;
}

/* every entry takes one pointer to its arguments as words (more than four arguments would go over the stack) */
void emu_smp(const uint32_t *a) { t40_mdns_ramp_smp((int32_t *)a[0], (int32_t)a[1], (int32_t)a[2], (int32_t)a[3], (int32_t)a[4]); }
void emu_dif(const uint32_t *a)
{
	/* a[1]: two words, cut then segopt */
	t40_mdns_ramp_dif((int32_t *)a[0], (int32_t *)a[1], (int32_t *)a[1] + 1, (int32_t)a[2], (int32_t)a[3], (int32_t)a[4], (int32_t)a[5]);
}
void emu_wdr_en(const uint32_t *a) { t40_mdns_comb_fill(a[0], a[1], a[2]); }
void emu_intp(const uint32_t *a) { t40_mdns_intp(a[0], a[1], a[2], a[3]); }
int emu_start(const uint32_t *a) { return t40_mdns_start(a[0]); }
int emu_reg_trig(const uint32_t *a) { return t40_mdns_reg_trig(a[0]); }
int emu_func_en(const uint32_t *a) { return t40_mdns_func_en(a[0], a[1], get_isp_memopt()); }
int emu_reg_cfg(const uint32_t *a)
{
	struct t40_mdns_ch c;

	mk(&c, a[0], a[1], 0, a[2], a[3], a[4], 0);
	return t40_mdns_reg_cfg(&c);
}
int emu_all_reg_refresh(const uint32_t *a)
{
	struct t40_mdns_ch c;

	mk(&c, a[0], a[2], a[3], a[4], a[5], a[6], 0);
	return t40_mdns_all_reg_refresh(&c, a[1]);
}
int emu_par_refresh(const uint32_t *a)
{
	struct t40_mdns_ch c;

	mk(&c, a[0], a[3], a[4], a[5], a[6], a[7], a[8]);
	return t40_mdns_par_refresh(&c, a[1], a[2], get_isp_memopt());
}
int emu_refresh(const uint32_t *a)
{
	struct t40_mdns_ch c;

	mk(&c, a[0], a[2], a[3], a[4], a[5], a[6], a[7]);
	return t40_mdns_refresh(&c, a[1], get_isp_memopt());
}
void emu_params_refresh(const uint32_t *a) { t40_mdns_params_refresh(a[0], a[1]); }
