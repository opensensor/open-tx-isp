/* Host test of the #189 lost-tail-call / lost-ALU fixes in the lifted T40 code: the functions are cut out of
 * driver/t40/tx_isp_t40_recovered.c (t40_lost_tail_host.sh) and run against stubs of their callees.  Expected
 * behaviour is the OEM's (vendor T40 module decompile / libt40-firmware disassembly).  Pointers live in the low 2 GB
 * (MAP_32BIT) because the lifted code keeps them in uint32_t. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

static struct { uint32_t reg, val; } wr[64];
static unsigned nwr;
static uint32_t regs[0x40000 / 4];
static unsigned lce_calls, mdns_calls;

static int32_t system_reg_read(uint32_t a) { return regs[(a / 4) & 0xffff]; }
static int32_t system_reg_write(uint32_t a, uint32_t v) { wr[nwr].reg = a; wr[nwr++].val = v; regs[(a / 4) & 0xffff] = v; return 0; }
static int32_t isp_printf(int l, ...) { (void)l; return 0; }
static int32_t tisp_mdns_start(uint32_t a0) { (void)a0; mdns_calls++; return 0; }
static int32_t tisp_lce_top_change_state(uint32_t a0) { (void)a0; lce_calls++; return 0; }
static const char LC2[] = "x", __param_str_isp_dual_buf[] = "isp_dual_buf";
static uint32_t tparams_status[2], day_night[2];

#include "t40_lost_tail_fn.inc"

static void *low(size_t n) { void *p = mmap(0, 4096 > n ? 4096 : n, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0); assert(p != MAP_FAILED); return p; }
static void put32(unsigned char *b, unsigned off, void *p) { uint32_t v = (uint32_t)(uintptr_t)p; memcpy(b + off, &v, 4); }

int main(void)
{
	uint32_t *st = low(8);
	uint8_t *f0, *f1;
	uint16_t *tp, *tgt;
	uint32_t *cmp;

	/* system_reg_write_af(vin, ch, reg, val): trigger 0x1a000 / 0x1a200 only for vin 1, then ALWAYS system_reg_write(reg, val) */
	nwr = 0; system_reg_write_af(1, 0, 0x1a100, 7);
	assert(nwr == 2 && wr[0].reg == 0x1a000 && wr[0].val == 1 && wr[1].reg == 0x1a100 && wr[1].val == 7);
	nwr = 0; system_reg_write_af(1, 1, 0x1a104, 8);
	assert(nwr == 2 && wr[0].reg == 0x1a200 && wr[0].val == 1 && wr[1].reg == 0x1a104 && wr[1].val == 8);
	nwr = 0; system_reg_write_af(0, 0, 0x1a108, 9);
	assert(nwr == 1 && wr[0].reg == 0x1a108 && wr[0].val == 9);

	/* tisp_s_module_control(ch, ctrl): module-enable word at (ch + 16) * 4 */
	st[0] = st[1] = 0xffffffffu;
	tparams_status[0] = tparams_status[1] = (uint32_t)(uintptr_t)st;
	regs[0x40 / 4] = 0xabc00000u | 0x0200000u;       /* upper bits survive, LCE bit 21 set */
	nwr = lce_calls = mdns_calls = 0;
	tisp_s_module_control(0, 0x0200000u);            /* nothing changes */
	assert(lce_calls == 0 && mdns_calls == 0 && nwr == 1 && wr[0].reg == 0x40 && wr[0].val == (0xabc00000u | 0x200000u));
	nwr = lce_calls = mdns_calls = 0;
	tisp_s_module_control(0, 0x0200000u | 0x1u);     /* an unrelated bit: no LCE state change (the lift ran it for any change) */
	assert(lce_calls == 0 && mdns_calls == 0 && nwr == 1);
	nwr = lce_calls = mdns_calls = 0;
	tisp_s_module_control(0, 0x0u);                  /* LCE bit 21 changed */
	assert(lce_calls == 1 && mdns_calls == 0 && nwr == 1 && wr[0].val == 0xabc00000u);
	nwr = lce_calls = mdns_calls = 0;
	tisp_s_module_control(0, 0x80u);                 /* bit 7 changed (LCE state), bit 21 changed */
	assert(lce_calls == 1);
	regs[0x44 / 4] = 0;
	nwr = lce_calls = mdns_calls = 0;
	tisp_s_module_control(1, 0x2000u);               /* MDNS bit 13: mdns_start + register write + mdns_reg_trig(1) = reg 0xf804 */
	assert(mdns_calls == 1 && lce_calls == 0 && nwr == 2 && wr[0].reg == 0x44 && wr[0].val == 0x2000u && wr[1].reg == (31u << 11) + 4 && wr[1].val == 1);

	/* tisp_ae_s_comp is now plain C in tx_isp_t40_ae_leaf.h and covered by the Unicorn oracle (t40_ae_leaf_host: hardware-param call, target maths) */
	puts("t40_lost_tail_host: ok");
	return 0;
}
