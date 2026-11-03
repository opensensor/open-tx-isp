/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 colour-temperature / EV event consumers in plain C (#85): the OEM tisp_ct_update (event 13 after
 * every AWB process), tisp_ccm_main_ct_update, tisp_ccm_main_ev_update (event 8), and the frame-cadence
 * part of tisp_lsc_ct_update and tisp_clm_ct_update.  Checked against the OEM instructions of the vendor
 * tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_ct_chain.py, tests/t40_ct_chain_host.sh).
 *
 * OEM facts this file keeps:
 *  - tisp_ct_update reads TOP (reg 0x40) once and skips CCM when bit 9, LSC when bit 1, BCSH when bit 15 and
 *    CLM when bit 16 is set (module bypassed).  LSC and CLM get the frame number of sensor 0 (fnum[0]).
 *  - The CCM threshold compare is unsigned against the full 32-bit CT / EV, the stored values are u16 (CT)
 *    and u32 (EV).  EV is the 64-bit event payload folded to (hi << 22) | (lo >> 10).
 *  - LSC/CLM re-interpolate the LUT on every CT event; the hardware LUT write is only armed
 *    (prepare_write_lut: write_times[bank]++) when the interpolation changed it (return 0) and the frame
 *    number is past saved + wlut_frequency (strictly).  fnum advances once per frame (OEM
 *    tisp_push_frame_count in the ISP interrupt); tisp_hardware_reg_refresh then writes the armed LUTs.
 *  - tisp_clm_ct_update returns the interpolation result, tisp_lsc_ct_update always 0.
 *
 * Needs from the includer: uint32_t/uint64_t, t40_ccm_ev_ct_update (tx_isp_t40_ccm_chain.h) and the hooks
 *   T40_CT_TOP()                       TOP word (system_reg_read(0x40))
 *   T40_CT_CCM(ct, a1)                 tisp_ccm_main_ct_update
 *   T40_CT_LSC(ct, a1, fnum)           tisp_lsc_ct_update(0, ...)
 *   T40_CT_BCSH(ct, a1)                tisp_bcsh_main_ct_update
 *   T40_CT_CLM(ct, a1, fnum)           tisp_clm_ct_update(0, ...)
 *   T40_LSC_INTERP(bank, ct, a3)       tisp_lsc_interp_by_ct(bank, -, ct, a3, 0), 0 = LUT changed
 *   T40_LSC_PREPARE(bank)              tisp_lsc_prepare_write_lut (write_times[bank]++)
 *   T40_CLM_INTERP(bank, ct)           tisp_clm_ct_interp(bank, ct, 1), 0 = LUT changed
 *   T40_CLM_PREPARE(bank)              tisp_clm_prepare_write_lut
 * (a macro the includer does not need may stay undefined: only the functions it calls expand them).
 */
#ifndef TX_ISP_T40_CT_CHAIN_H
#define TX_ISP_T40_CT_CHAIN_H

#define T40_TOP_BYPASS_LSC  0x00002U
#define T40_TOP_BYPASS_CCM  0x00200U
#define T40_TOP_BYPASS_BCSH 0x08000U
#define T40_TOP_BYPASS_CLM  0x10000U

/* OEM tisp_ccm_main_ct_update: ctx[6] = CT now, ctx[7] = CT last applied, ctx[8] = threshold (u16 each) */
static int32_t t40_ccm_main_ct_update(uintptr_t ctx, uint32_t ct)
{
	uint16_t thr = CCM_U16(CCM_U32(ctx + 32)), last;
	uint32_t d;

	CCM_U16(CCM_U32(ctx + 24)) = (uint16_t)ct;
	last = CCM_U16(CCM_U32(ctx + 28));
	d = last < ct ? ct - last : last - ct;
	if (thr < d) {
		t40_ccm_ev_ct_update(ctx, 0);
		CCM_U16(CCM_U32(ctx + 28)) = (uint16_t)ct;
	}
	return 0;
}

/* OEM tisp_ccm_main_ev_update(lo, hi): ctx[3] = EV now, ctx[4] = EV last applied, ctx[5] = threshold (u32 each) */
static int32_t t40_ccm_main_ev_update(uintptr_t ctx, uint32_t lo, uint32_t hi)
{
	uint32_t thr = CCM_U32(CCM_U32(ctx + 20)), ev = hi << 22 | lo >> 10, last, d;

	CCM_U32(CCM_U32(ctx + 12)) = ev;
	last = CCM_U32(CCM_U32(ctx + 16));
	d = last < ev ? ev - last : last - ev;
	if (thr < d) {
		t40_ccm_ev_ct_update(ctx, 0);
		CCM_U32(CCM_U32(ctx + 16)) = ev;
	}
	return 0;
}

/* frame cadence of tisp_lsc_ct_update / tisp_clm_ct_update after the interpolation: arm the LUT write when
 * the frame number is past saved + frequency; returns true when armed (the caller does write_times++) */
static bool t40_lut_frame_due(uint64_t *saved, uint8_t freq, uint64_t fnum)
{
	if (*saved + freq < fnum) {
		*saved = fnum;
		return true;
	}
	return false;
}

/* OEM tisp_lsc_ct_update(bank, -, ct, a3, fnum): saved = lsc_frm_num_saved, freq = lsc_wlut_frequency */
static int32_t t40_ctc_lsc_update(uint32_t bank, uint32_t ct, uint32_t a3, uint64_t fnum, uint64_t *saved, const uint8_t *freq)
{
	if (T40_LSC_INTERP(bank, ct, a3) == 0 && t40_lut_frame_due(&saved[bank], freq[bank], fnum))
		T40_LSC_PREPARE(bank);
	return 0;
}

/* OEM tisp_clm_ct_update(bank, -, ct, -, fnum): saved = clm_frame_num_saved, freq = clm_wlut_frequency */
static int32_t t40_ctc_clm_update(uint32_t bank, uint32_t ct, uint64_t fnum, uint64_t *saved, const uint8_t *freq)
{
	int32_t r = T40_CLM_INTERP(bank, ct);

	if (r == 0 && t40_lut_frame_due(&saved[bank], freq[bank], fnum))
		T40_CLM_PREPARE(bank);
	return r;
}

/* OEM tisp_ct_update(ct, a1): event 13 */
static int32_t t40_ct_update(uint32_t ct, uint32_t a1, uint64_t fnum)
{
	uint32_t top = T40_CT_TOP();

	if (!(top & T40_TOP_BYPASS_CCM))
		T40_CT_CCM(ct, a1);
	if (!(top & T40_TOP_BYPASS_LSC))
		T40_CT_LSC(ct, a1, fnum);
	if (!(top & T40_TOP_BYPASS_BCSH))
		T40_CT_BCSH(ct, a1);
	if (!(top & T40_TOP_BYPASS_CLM))
		T40_CT_CLM(ct, a1, fnum);
	return 0;
}

#endif
