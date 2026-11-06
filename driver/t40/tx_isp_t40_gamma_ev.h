/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 gamma EV follow-up (#204): the OEM tisp_gamma_ev_update chain as plain C.
 *
 * The tuning bin gamma section (620 bytes, tparams + 0x106ec on the T40 bins) holds the linear curve
 * (129 x u16 at +0), ten EV nodes (u32 at +0x204) and ten strengths (u8 at +0x22c).  The OEM AE event
 * thread (tisp_main_long_ev_update, TOP bit 10 clear) hands the EV (IT x total gain, Q10) to
 * tisp_gamma_ev_update, which interpolates a strength over the EV nodes and, when it changed and the
 * frame cadence allows it, blends the curve toward the identity ramp (strength 255 = curve unchanged)
 * and arms the LUT write.  Host-checked against the OEM instructions in Unicorn
 * (tests/t40_gamma_ev_host.sh, tools/ko_emu/diff_gamma_ev.py).
 *
 * OEM functions (vendor image build): tisp_gamma_interp_by_ev, tisp_gamma_strength_transform (with
 * tisp_round_int64(x, 8)), the gate of tisp_gamma_ev_update.  Only stdint types: also built for the host.
 *
 * Deviations of the driver glue (t40_gamma_ev_update in tx_isp_t40_recovered.c, not covered by the oracle):
 *  - fnum is t40_ct_fnum (tx_isp_t40_vawb.h, +1 per AWB process), not the OEM frame counter; only the write cadence
 *    (more than gamma_wlut_frequency = 5 counts since the last write) depends on it.
 *  - the LUT is written at once in the AWB/event thread (t40_soft_gamma_write: 129 registers + 0x50080) instead of the
 *    OEM "arm gamma_wlut_flag, write at frame done"; a change can therefore land mid-frame (only when the strength moves,
 *    which the Eufy sc830ai banks never reach: day strengths 255 up to EV 880000, night 255 everywhere).
 */
#ifndef TX_ISP_T40_GAMMA_EV_H
#define TX_ISP_T40_GAMMA_EV_H

#define T40_GAMMA_BIN_OFF	0x106ecU	/* gamma section in tparams (file offset - 0x18) */
#define T40_GAMMA_EV_NODES	0x204U		/* u32[10] EV nodes */
#define T40_GAMMA_EV_STR	0x22cU		/* u8[10] strengths */

/* OEM tisp_gamma_interp_by_ev(ch, -, ev, wdr_skip, force): stores ev in the state, strength from the node tables
 * (first node above ev, linear between neighbours, rounded); 2 = two equal nodes (nothing stored, unreachable: a tie
 * cannot be the first node above ev),
 * 1 = unchanged and not forced, 0 = *cur updated */
static int t40_gamma_interp_by_ev(const uint32_t *node, const uint8_t *str, uint32_t *cur, uint32_t *ev_saved,
				  uint32_t ev, uint32_t skip, uint8_t force)
{
	uint32_t s = 0, d, k;
	unsigned int i;

	*ev_saved = ev;
	for (i = 0; i < 10U; i++) {
		if (!skip && ev < node[i]) {
			if (!i) {
				s = str[0];
			} else {
				d = node[i] - node[i - 1U];
				if (!d)
					return 2;
				k = ev - node[i - 1U];
				s = ((uint32_t)str[i - 1U] * (d - k) + (uint32_t)str[i] * k + (d >> 1)) / d;
			}
			break;
		}
		if (i == 9U)
			s = str[9];
	}
	if (*cur != s || force) {
		*cur = s;
		return 0;
	}
	return 1;
}

/* OEM tisp_gamma_strength_transform: out[i] = round((curve[i] * k + i * (8192 - 32 k)) / 256), k = s + s / 128,
 * i.e. curve blended with the 32 * i ramp; out[128] = 4095.  32-bit arithmetic like the OEM (mul / addu). */
static void t40_gamma_strength_lut(const uint16_t *curve, uint32_t s, uint16_t *out)
{
	uint32_t k = (s >> 7) + s, step = 8192U - (k << 5), acc = 0, v;
	unsigned int i;

	for (i = 0; i < 128U; i++) {
		v = (uint32_t)curve[i] * k + acc;
		out[i] = (uint16_t)((v >> 8) + ((v >> 7) & 1U));
		acc += step;
	}
	out[128] = 4095U;
}

/* OEM tisp_gamma_ev_update(ch, -, ev_lo, ev_hi, fnum_lo, fnum_hi) gate: EV >> 10 (saturated when ev_hi >> 10),
 * no manual curve, strength changed, and the frame number strictly past saved + wlut frequency (64-bit);
 * returns 1 when the caller must re-transform the curve and arm the LUT write (*saved = fnum) */
static int t40_gamma_ev_due(const uint32_t *node, const uint8_t *str, uint32_t *cur, uint32_t *ev_saved,
			    uint32_t ev_lo, uint32_t ev_hi, uint8_t manual, uint8_t freq, uint64_t fnum, uint64_t *saved)
{
	uint32_t e = ev_hi << 22 | ev_lo >> 10;

	if (ev_hi >> 10)
		e = 0xffffffffU;
	if (manual || t40_gamma_interp_by_ev(node, str, cur, ev_saved, e, 0, 0) != 0)
		return 0;
	if (*saved + freq < fnum) {
		*saved = fnum;
		return 1;
	}
	return 0;
}

#endif
