/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 OEM colour-temperature / EV chains (t40_ct_chains=1): the mechanically translated
 * tisp_ct_update (TOP-gated CCM / LSC / BCSH / CLM), tisp_ccm_main_ct_update + ev_ct_update,
 * tisp_lsc_ct_update + real_write_lut, tisp_bcsh_main_ct/ev_update (+ ct_update / ev_update)
 * from tx_isp_t40_vawb_gen.inc (tools/t40_vawb/gen.sh, same asm2c.py and runtime as the
 * vendor AWB) replace the driver's hand-written "literal" follow-ups in t40_vawb_ct_follow /
 * t40_vawb_ev_follow.  The OEM functions run on the literal chains' contexts, which have the
 * OEM pointer-table layout (pstMainCcmOri_lit[26], t40_bcsh_oem_ctx[72] of the C BCSH, LSC tool/real
 * para of lsc_lit_banks[0]); their init stays with the literal code.
 *
 * Findings from the OEM module (Eufy T8416 tx-isp-t40.ko):
 *  - tisp_ct_update reads TOP (reg 0x40) and skips CCM when bit 9, LSC when bit 1, BCSH when
 *    bit 15 and CLM when bit 16 is set (= module bypassed).
 *  - tisp_lsc_ct_update only re-interpolates the LUT (tisp_lsc_interp_by_ct) and defers the
 *    hardware write: lsc_lut_write_times[bank]++ when fnum > lsc_frm_num_saved + wlut_frequency
 *    (5), tisp_hardware_reg_refresh then calls tisp_lsc_real_write_lut.  The OEM module never
 *    writes fnum (.bss, 16 B, only read), so this deferral never fires: the vendor LSC LUT keeps
 *    its init interpolation.  t40_ct_fnum_tick=1 advances fnum per process to make the OEM
 *    deferral fire (beyond-vendor); default 0 = vendor behaviour.
 *  - TOP word (tisp_main_init 0x1da5c..0x1dae8): see t40_vct_top_word().
 * Included from tx_isp_t40_vawb.h after the runtime (VAWB_CTL/VAWB_CSP).
 */
#ifndef TX_ISP_T40_VCT_H
#define TX_ISP_T40_VCT_H

static uint t40_ct_top_apply;
module_param(t40_ct_top_apply, uint, 0644);
MODULE_PARM_DESC(t40_ct_top_apply, "1: commit the OEM-derived TOP word (t40_ct_top) at isp-block-init instead of the profile value");
static u32 t40_ct_top, t40_ct_top_sel;
module_param_named(t40_ct_top, t40_ct_top, uint, 0444);

/*
 * The translated chain itself (about 118 KB of vawb_gen code, opt-in, never device-tested) is only
 * built with TX_ISP_T40_VCT=y (Kbuild; issue #85).  Without it t40_ct_chains is the constant 0: the
 * literal/C CT and EV follow-ups run as with the parameter's default, and the compiler drops the
 * translated functions that only this path reaches.  tests/t40_vct_host.sh keeps testing the chain.
 */
#ifdef TX_ISP_T40_VCT
static uint t40_ct_chains;
module_param(t40_ct_chains, uint, 0644);
MODULE_PARM_DESC(t40_ct_chains, "1: OEM tisp_ct_update / ccm+bcsh ev_update chains (translated) instead of the literal CT/EV follow-ups");
static uint t40_ct_fnum_tick;
module_param(t40_ct_fnum_tick, uint, 0644);
MODULE_PARM_DESC(t40_ct_fnum_tick, "1: advance the OEM frame number per AWB process (OEM never does: LSC CT LUT write deferral never fires)");
static u32 vct_ct_calls, vct_ev_calls, vct_lut_writes, vct_skips;
module_param_named(t40_ct_calls, vct_ct_calls, uint, 0444);
module_param_named(t40_ct_lut_writes, vct_lut_writes, uint, 0444);
module_param_named(t40_ct_skips, vct_skips, uint, 0444);
#endif

/* OEM lsc_ram_lock[bank] (4 B each): the chain passes the lock address, map it to the literal bank lock */
static u64 vawb_x___private_spin_lock_irqsave(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 bank = (a0 - (u32)(uintptr_t)vct_lsc_ram_lock) / 4U;
	unsigned long flags = 0;

	if (bank < 2 && lsc_lit_banks[bank].alive) {
		spin_lock_irqsave(&lsc_lit_banks[bank].lock, flags);
		vawb_sw(a1, (u32)flags, 6);
	}
	return 0;
}
static u64 vawb_x_private_spin_unlock_irqrestore(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 bank = (a0 - (u32)(uintptr_t)vct_lsc_ram_lock) / 4U;

	if (bank < 2 && lsc_lit_banks[bank].alive)
		spin_unlock_irqrestore(&lsc_lit_banks[bank].lock, (unsigned long)a1);
	return 0;
}
/* OEM tisp_clm_ct_update: the driver's CLM is the one-shot start-up in tx_isp_t40_clm_lit.inc (no CT follow-up state), so nothing to do here */
static u64 vawb_s_tisp_clm_ct_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	(void)a0; (void)a1; (void)a2; (void)a3; (void)csp;
	return 0;
}

/* OEM tisp_main_init 0x1da5c..0x1dae8: TOP word from the day bank.  sel = tisp_par_info[0x74] == 1
 * selects bin bytes [32..63] (bypass bits) and [96..127] (reg 0x6c), else [0..31] / [64..95];
 * bit 3 is always cleared, bits 22..31 always set, and the modules not present in the bin
 * (tparams_status bit clear) are bypassed too.  *reg6c receives the second word (24 bits). */
static u32 t40_vct_top_word(const u8 *bin, u32 sel, u32 status, u32 *reg6c)
{
	u32 top = 0x7fffffffU, r6c = 0, i;

	for (i = 0; i < 32; i++) {
		top &= ~BIT(i);
		r6c &= ~BIT(i);
		top += (u32)bin[(sel == 1 ? 32 : 0) + i] << i;
		top &= ~8U;
		r6c += (u32)bin[(sel == 1 ? 96 : 64) + i] << i;
	}
	top |= 0xffc00000U;
	if (status)
		top |= ~status & 0x3fffffU;
	if (reg6c)
		*reg6c = r6c & 0xffffffU;
	return top;
}

#ifdef TX_ISP_T40_VCT
/* bind the OEM LSC pointer objects to the literal bank buffers (OEM layout: tool para 0xa324 B,
 * real para 27656 B with nodes @13828 / packed LUT @13832) */
static bool t40_vct_bind(void)
{
	u32 i;

	for (i = 0; i < 2; i++) {
		if (lsc_lit_banks[i].alive) {
			vct_lsc_real_para[i] = (u32)(uintptr_t)lsc_lit_banks[i].real;
			vct_lsc_awdr_para[i] = (u32)(uintptr_t)lsc_lit_banks[i].tool;
		} else {
			vct_lsc_real_para[i] = vct_lsc_awdr_para[i] = 0;
		}
	}
	return stMainCcmOuter_lit && t40_bcsh.ready && pstMainCcmOri_lit[6];
}

/* OEM event 13 handler: tisp_ct_update(ct, 0); the deferred LSC LUT write of tisp_hardware_reg_refresh
 * (lsc_lut_write_times[0] != 0 -> tisp_lsc_real_write_lut(0)) follows right away */
static void t40_vct_ct_update(u32 ct)
{
	if (!t40_vct_bind()) {
		vct_skips++;
		return;
	}
	if (t40_ct_fnum_tick)
		vct_fnum[0]++;
	vct_ct_calls++;
	VAWB_TOP();
	VAWB_CTL(vawb_tisp_ct_update, ct, 0, 0);
	if (vct_lsc_lut_write_times[0] && lsc_lit_banks[0].alive) {
		vct_lut_writes++;
		VAWB_TOP();
		VAWB_CTL(vawb_tisp_lsc_real_write_lut, 0, 0, 0);
	}
}

/* OEM event 8 consumers (ev = integration time x gain, Q10, as u64 lo/hi): CCM + BCSH */
static void t40_vct_ev_update(u32 ev)
{
	if (!t40_vct_bind()) {
		vct_skips++;
		return;
	}
	vct_ev_calls++;
	VAWB_TOP();
	VAWB_CTL(vawb_tisp_ccm_main_ev_update, ev, 0, 0);
	VAWB_TOP();
	VAWB_CTL(vawb_tisp_bcsh_main_ev_update, ev, 0, 0);
}

static int t40_vct_diag_get(char *buf, const struct kernel_param *kp)
{
	return scnprintf(buf, PAGE_SIZE, "ct=%u ev=%u lut=%u skips=%u fnum=%llu wt=%u,%u lscct=%u flag=%u,%u top=%#x sel=%u faults=%u\n",
			 vct_ct_calls, vct_ev_calls, vct_lut_writes, vct_skips, vct_fnum[0],
			 vct_lsc_lut_write_times[0], vct_lsc_lut_write_times[1], vct_lsc_ct,
			 vct_lsc_ct_flag[0], vct_lsc_ct_flag[1], t40_ct_top, t40_ct_top_sel, vawb_faults);
}
static const struct kernel_param_ops t40_vct_diag_ops = { .get = t40_vct_diag_get };
module_param_cb(t40_ct_diag, &t40_vct_diag_ops, NULL, 0444);

#else
#define t40_ct_chains 0U
static inline void t40_vct_ct_update(u32 ct) { }
static inline void t40_vct_ev_update(u32 ev) { }
#endif /* TX_ISP_T40_VCT */

#endif
