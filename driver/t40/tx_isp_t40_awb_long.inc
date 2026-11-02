/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AWB per-frame zone pass.  Hand translation of the Eufy OEM module (tx-isp-t40.ko):
 *   tisp_awb_long_alogrithm   0x32784 (4348 B, 1087 insns)
 * Runs in place of the translated OEM code (VAE_STOP, tx_isp_t40_vawb.h), bit for bit the same
 * (tests/t40_vawb_host.sh with LA_REF: both versions on every call, replay dumps + FUZZL).
 *
 * a0 = ctx = pstMainAwbOri (u32 pointer table), a1 = pstMainAwbCtDetectOri (passed on to ct_detect).
 *   ctx[0]  outer: u16 rows at +2, cols at +6      ctx[1]  u32 minimum zone count
 *   ctx[3]  u16 [0] precision s1, [1] gain shift s3
 *   ctx[4]  u16 [0] history depth, [1] restart threshold, [2] start threshold, [3] stable threshold
 *   ctx[5]  u32 convergence state {state, step, target r, target b, current r, current b}
 *   ctx[7]  u32 colour temperature  ctx[9] u32 AWB gains r, b
 *   ctx[22] u16 at +18 weight-pair override (1..4)   ctx[23] u16 group weights [8]   ctx[55] u16 override weights [4]
 *   ctx[24] u16 saturation-weight mode (1/2: tisp_awb_sat_weight)
 *   ctx[39..42] u32 weighted sums R, G, B, count (zone z, second set at z + 225)
 *   ctx[43] u32 ratios: [z] R/G, [z + 225] B/G, [z + 450] / [z + 675] the second set
 *   ctx[44] u32 counts [z], [z + 225]       ctx[45] saturation plane (sat_weight)
 *   ctx[59..98] u32 raw statistics: 8 groups x 5 planes (R, G, B, -, count) per zone
 *   ctx[100] u8 history valid  ctx[103] u8 stable  ctx[118] / ctx[120] u8 hold flags
 *   ctx[104..106] u32 [15] history of gain r, gain b, CT      ctx[123] u16 [6] mean R/G, B/G, previous, last-used
 *   ctx[125..127] u32 per-zone means of the second set
 * Zone index z = r * 15 + c (hardware stride 15).  ctx[43] + 450 is the same memory as ctx[44] on the
 * device layout, so every load and store keeps the OEM order; table pointers are taken once per pass
 * (no table aliases the pointer table itself).  Divisions by zero give 0 like the translated code
 * (the OEM traps there; never seen with real statistics).
 */

#define T40_LA_P32(i) ((u32 *)(uintptr_t)ctx[i])
#define T40_LA_P16(i) ((u16 *)(uintptr_t)ctx[i])
#define T40_LA_P8(i)  ((u8 *)(uintptr_t)ctx[i])

static u32 t40_la_divu(u32 x, u32 y, u32 pc)
{
	if (unlikely(!y)) { vawb_fault_note(0, pc); return 0; }
	return x / y;
}

static u32 t40_la_divs(u32 x, u32 y, u32 pc)
{
	s32 a = (s32)x, b = (s32)y;

	if (unlikely(!b || (a == INT_MIN && b == -1))) { vawb_fault_note(0, pc); return 0; }
	return (u32)(a / b);
}

static u32 t40_la_mul2(u32 p, u32 a, u32 b)
{
	return (u32)fix_point_mult2_32((int32_t)p, (int32_t)a, (int32_t)b);
}

/* fix_point_div(p, num, den) of 32-bit operands.  den 0 (a ct_detect gain of 0): the translated OEM
 * quotient is 0 and its bit loop still runs - every step sets a bit, and the step where the shifted
 * remainder is 0 (equal to den) ends the loop with that bit and zeros below it */
static u64 t40_la_div(u32 p, u32 num, u32 den)
{
	u64 rem = num, frac = 0;
	u32 i;

	if (likely(den))
		return (u64)fix_point_div((int32_t)p, 0, (int32_t)num, 0, (int32_t)den, 0);
	vawb_fault_note(0, 4);
	for (i = 0; i != p; i++) {
		rem <<= 1; frac <<= 1;
		if (!rem)
			return (frac | 1) << ((p - 1 - i) & 63);
		frac |= 1;
	}
	return frac;
}

/* every pointer the pass uses must be a valid (aligned kernel) address, as the guarded loads require */
static bool t40_la_ctx_ok(const u32 *ctx)
{
	static const u8 w32[] = { 1, 5, 7, 9, 39, 40, 41, 42, 43, 44, 45, 104, 105, 106, 125, 126, 127 };
	static const u8 w16[] = { 0, 3, 4, 22, 23, 24, 55, 123 };
	static const u8 w8[] = { 100, 103, 118, 120 };
	u32 i;

	for (i = 0; i < ARRAY_SIZE(w32); i++) if (!vawb_ok(ctx[w32[i]], 3)) return false;
	for (i = 0; i < ARRAY_SIZE(w16); i++) if (!vawb_ok(ctx[w16[i]], 1)) return false;
	for (i = 0; i < ARRAY_SIZE(w8); i++) if (!vawb_ok(ctx[w8[i]], 0)) return false;
	for (i = 59; i <= 98; i++) if (!vawb_ok(ctx[i], 3)) return false;
	return true;
}

static void t40_awb_long_alg(u32 a0, u32 a1)
{
	const u32 *ctx = (const u32 *)(uintptr_t)a0;
	u32 loc[6];	/* OEM frame +32..+52: ct flags[2], targets r/b, ct_detect gains r/b */
	const u16 *v4;
	u32 *s6, *t39, *t40, *t41, *t42, *t43, *t44;
	u32 s1, s3, sh, unity, rows, cols, thr, s0, vp1, vp2, vp3, c0, c1, c2, c3, c4, c5;
	u32 aw0, aw1, aw2, aw3, tw2, tw3, tw4, tw6, sel, r, c, z, g0, g1;
	u32 cnt1, cnt2, sum1, sum2, half;
	u64 q1, q2;
	u16 *g;
	u8 *t100, *t103;

	if (unlikely(!vawb_ok(a0, 3) || !t40_la_ctx_ok(ctx))) { vawb_fault_note(a0, 206768U); return; }
	s1 = T40_LA_P16(3)[0]; s3 = T40_LA_P16(3)[1];
	unity = 1U << (s1 & 31);
	loc[0] = 0; loc[1] = 0; loc[2] = loc[3] = loc[4] = loc[5] = unity;
	cols = *(const u16 *)((uintptr_t)ctx[0] + 6); rows = *(const u16 *)((uintptr_t)ctx[0] + 2);
	thr = *T40_LA_P32(1);
	v4 = T40_LA_P16(4); s0 = v4[0]; vp1 = v4[1]; vp2 = v4[2]; vp3 = v4[3];
	s6 = T40_LA_P32(5); c0 = s6[0]; c1 = s6[1]; c2 = s6[2]; c3 = s6[3]; c4 = s6[4]; c5 = s6[5];
	t100 = T40_LA_P8(100); t103 = T40_LA_P8(103);
	{
		const u16 *w23 = T40_LA_P16(23), *w55 = T40_LA_P16(55);

		aw1 = w23[1]; aw2 = w23[2]; aw3 = w23[3]; tw3 = w23[5]; tw4 = w23[6]; tw6 = w23[7];
		sel = *(const u16 *)((uintptr_t)ctx[22] + 18);
		if (sel == 1) {
			aw0 = tw2 = w55[0];
		} else {
			aw0 = w23[0]; tw2 = w23[4];
			if (sel == 2) aw1 = tw3 = w55[1];
			else if (sel == 3) aw2 = tw4 = w55[2];
			else if (sel == 4) aw3 = tw6 = w55[3];
		}
	}
	t39 = T40_LA_P32(39); t40 = T40_LA_P32(40); t41 = T40_LA_P32(41); t42 = T40_LA_P32(42);
	t43 = T40_LA_P32(43); t44 = T40_LA_P32(44);

	/* (1) weighted sums of the 8 statistics groups: 4 groups per set, set 2 at z + 225 */
	{
		const u32 *a59 = T40_LA_P32(59), *a60 = T40_LA_P32(60), *a61 = T40_LA_P32(61), *a63 = T40_LA_P32(63);
		const u32 *a64 = T40_LA_P32(64), *a65 = T40_LA_P32(65), *a66 = T40_LA_P32(66), *a68 = T40_LA_P32(68);
		const u32 *a69 = T40_LA_P32(69), *a70 = T40_LA_P32(70), *a71 = T40_LA_P32(71), *a73 = T40_LA_P32(73);
		const u32 *a74 = T40_LA_P32(74), *a75 = T40_LA_P32(75), *a76 = T40_LA_P32(76), *a78 = T40_LA_P32(78);
		const u32 *a79 = T40_LA_P32(79), *a80 = T40_LA_P32(80), *a81 = T40_LA_P32(81), *a83 = T40_LA_P32(83);
		const u32 *a84 = T40_LA_P32(84), *a85 = T40_LA_P32(85), *a86 = T40_LA_P32(86), *a88 = T40_LA_P32(88);
		const u32 *a89 = T40_LA_P32(89), *a90 = T40_LA_P32(90), *a91 = T40_LA_P32(91), *a93 = T40_LA_P32(93);
		const u32 *a94 = T40_LA_P32(94), *a95 = T40_LA_P32(95), *a96 = T40_LA_P32(96), *a98 = T40_LA_P32(98);

		for (r = 0; r < rows; r++)
			for (c = 0; c < cols; c++) {
				u32 x;

				z = r * 15 + c;
				t39[z] = aw1 * a64[z] + aw0 * a59[z];
				t40[z] = aw1 * a65[z] + aw0 * a60[z];
				t41[z] = aw1 * a66[z] + aw0 * a61[z];
				t42[z] = aw1 * a68[z] + aw0 * a63[z];
				x = aw3 * a74[z] + aw2 * a69[z]; t39[z] += x;
				x = aw3 * a75[z] + aw2 * a70[z]; t40[z] += x;
				x = aw3 * a76[z] + aw2 * a71[z]; t41[z] += x;
				x = aw3 * a78[z] + aw2 * a73[z]; t42[z] += x;
				t39[z] >>= 3; t40[z] >>= 3; t41[z] >>= 3; t42[z] >>= 3;
				t39[z + 225] = tw3 * a84[z] + tw2 * a79[z];
				t40[z + 225] = tw3 * a85[z] + tw2 * a80[z];
				t41[z + 225] = tw3 * a86[z] + tw2 * a81[z];
				t42[z + 225] = tw3 * a88[z] + tw2 * a83[z];
				x = tw6 * a94[z] + tw4 * a89[z]; t39[z + 225] += x;
				x = tw6 * a95[z] + tw4 * a90[z]; t40[z + 225] += x;
				x = tw6 * a96[z] + tw4 * a91[z]; t41[z + 225] += x;
				x = tw6 * a98[z] + tw4 * a93[z]; t42[z + 225] += x;
				t39[z + 225] >>= 3; t40[z + 225] >>= 3; t41[z + 225] >>= 3; t42[z + 225] >>= 3;
			}
	}

	/* (2) per-zone R/G and B/G ratios scaled by the gains, and the counts */
	sh = (s1 - 10) & 31;
	g0 = t40_la_mul2(s1, unity, T40_LA_P32(9)[0] << sh);
	g1 = t40_la_mul2(s1, unity, T40_LA_P32(9)[1] << sh);
	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++) {
			z = r * 15 + c;
			if (t40[z] == 0) {
				t43[z] = 0; t43[z + 225] = 0; t44[z] = 0;
			} else {
				t43[z] = t40_la_mul2(s1, t40_la_divu(t39[z] << 10, t40[z], 208476U) << sh, g0);
				t43[z + 225] = t40_la_mul2(s1, t40_la_divu(t41[z] << 10, t40[z], 208552U) << sh, g1);
				t44[z] = t42[z];
			}
			if (t40[z + 225] == 0) {
				t43[z + 450] = 0; t43[z + 675] = 0; t44[z + 225] = 0;
			} else {
				t43[z + 450] = t40_la_mul2(s1, t40_la_divu(t39[z + 225] << 10, t40[z + 225], 208644U) << sh, g0);
				t43[z + 675] = t40_la_mul2(s1, t40_la_divu(t41[z + 225] << 10, t40[z + 225], 208728U) << sh, g1);
				t44[z + 225] = t42[z + 225];
			}
		}

	/* (3) global mean R/G, B/G of the second set (Q8 in ctx[123][0..1], previous in [2..3]) */
	cnt1 = cnt2 = rows * cols; sum1 = sum2 = 0;
	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++) {
			u32 vr, vb;

			z = r * 15 + c;
			vr = t43[z + 450]; vb = t43[z + 675];
			sum1 += vr; sum2 += vb;
			if (!vr) cnt1--;
			if (!vb) cnt2--;
		}
	q1 = t40_la_div(s1, sum1, g0);
	half = t40_la_divs(1U << (s3 & 31), 2, 208924U);
	q2 = t40_la_div(s1, sum2, g1);
	g = T40_LA_P16(123);
	g[2] = g[0]; g[3] = g[1];
	if (cnt1) {
		u32 lo = (u32)((q1 + (u64)(s64)(s32)half) >> (s3 & 63));

		g[0] = (u16)t40_la_divu(lo + (cnt1 >> 1), cnt1, 209164U);
	} else {
		g[0] = 256;
	}
	if (cnt2) {
		u32 lo = (u32)((q2 + (u64)(s64)(s32)half) >> (s3 & 63));

		g[1] = (u16)t40_la_divu(lo + (cnt2 >> 1), cnt2, 209232U);
	} else {
		g[1] = 256;
	}

	/* (4) per-zone means of the second set */
	{
		u32 *m0 = T40_LA_P32(125), *m1 = T40_LA_P32(126), *m2 = T40_LA_P32(127);

		for (r = 0; r < rows; r++)
			for (c = 0; c < cols; c++) {
				z = r * 15 + c;
				if (t42[z + 225] == 0) {
					m0[z] = 0; m1[z] = 0; m2[z] = 0;
				} else {
					m0[z] = t40_la_divu(t39[z + 225], t42[z + 225], 209344U);
					m1[z] = t40_la_divu(t40[z + 225], t42[z + 225], 209388U);
					m2[z] = t40_la_divu(t41[z + 225], t42[z + 225], 209432U);
				}
			}
	}

	/* (5) zones at or below the minimum count drop out */
	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++) {
			z = r * 15 + c;
			if (!(thr < t42[z])) { t43[z] = 0; t43[z + 225] = 0; t44[z] = 0; }
			if (!(thr < t42[z + 225])) { t43[z + 450] = 0; t43[z + 675] = 0; t44[z + 225] = 0; }
		}

	/* (6) saturation weight (writes the four gains at loc[2..5]) */
	if ((u32)(*T40_LA_P16(24) - 1U) < 2U) {
		t40_awb_sat_weight(T40_LA_P32(39), T40_LA_P32(40), T40_LA_P32(41), T40_LA_P32(42), T40_LA_P32(45), &loc[2], ctx);
	}

	/* (7) unchanged scene: keep the last result */
	g = T40_LA_P16(123);
	{
		u32 m0 = g[0];

		if (*T40_LA_P8(100) == 1) {
			u32 d0 = g[4] < m0 ? m0 - g[4] : g[4] - m0, d1;

			d0 &= 0xffff;
			d1 = g[5] < g[1] ? g[1] - g[5] : g[5] - g[1];
			d1 &= 0xffff;
			if (*t103 == 1 && ((d0 + d1) & 0xffff) < vp3 && *T40_LA_P8(120) == 0 && *T40_LA_P8(118) == 0)
				return;
		}
		g[4] = (u16)m0;
		g = T40_LA_P16(123);
		g[5] = g[1];
	}
	(void)tisp_awb_ct_detect(a1, (uintptr_t)&loc[4], (u32)(uintptr_t)&loc[0]);

	/* (8) 15-deep history of gains and CT, weighted mean over the last s0 entries (weights 16 - s0 .. 15) */
	{
		u32 *h0 = T40_LA_P32(104), *h1 = T40_LA_P32(105), *h2 = T40_LA_P32(106), i;

		if (*T40_LA_P8(100) == 1) {
			u32 w, sw = 0, ar = 0, ab = 0, ac = 0;

			for (i = 1; i < 15; i++) { h0[i - 1] = h0[i]; h1[i - 1] = h1[i]; h2[i - 1] = h2[i]; }
			h0[14] = loc[4]; h1[14] = loc[5]; h2[14] = *T40_LA_P32(7);
			if (s0 >= 16) s0 = 15;
			else if (s0 == 0) s0 = 1;
			for (w = 16 - s0; w <= 15; w++) {
				i = w - 1;
				sw += w; ar += w * h0[i]; ab += w * h1[i]; ac += w * h2[i];
			}
			loc[4] = t40_la_divu(ar + (sw >> 1), sw, 210192U);
			loc[5] = t40_la_divu(ab + (sw >> 1), sw, 210220U);
			*T40_LA_P32(7) = t40_la_divu(ac + (sw >> 1), sw, 210236U);
		} else {
			for (i = 0; i < 15; i++) { h0[i] = loc[4]; h1[i] = loc[5]; h2[i] = *T40_LA_P32(7); }
		}
		t100 = T40_LA_P8(100);
		if (*t100 != 1) {
			*t100 = 1; *t103 = 0; s0 = 1;
		} else if (h0[13] == h0[14] && h1[13] == h1[14] && *T40_LA_P8(120) == 0 && *T40_LA_P8(118) == 0 &&
			   s6[2] == s6[4] && s6[3] == s6[5]) {
			*t103 = 1;
			return;
		}
	}

	/* (9) targets 1 / gain and the convergence state machine in ctx[5] */
	{
		u32 rnd = 1U << ((s3 - 1) & 31), tr, tb, dr, db, d, n;

		loc[2] = (u32)t40_la_div(s1, unity, loc[4]);
		tb = (u32)t40_la_div(s1, unity, loc[5]);
		tr = (loc[2] + rnd) >> (s3 & 31); tb = (tb + rnd) >> (s3 & 31);
		loc[2] = tr; loc[3] = tb;
		dr = c2 < tr ? tr - c2 : c2 - tr;
		db = c3 < tb ? tb - c3 : c3 - tb;
		d = dr + db;
		if (c0 == 0) {
			if (!(vp2 < d) || loc[0] == 1) { s6[0] = 0; s6[1] = 0; return; }
			s6[0] = 1; s6[1] = 1;
			s6[2] = tr;
			n = t40_la_divs(tr - c2, s0, 210772U);
			s6[3] = tb;
			s6[4] = n + c4;
			s6[5] = t40_la_divs(tb - c3, s0, 210808U) + c5;
			return;
		}
		if (vp1 < d && loc[0] != 1) {
			s6[0] = 1; s6[1] = 1;
			s6[2] = tr;
			n = t40_la_divs(tr - c4, s0, 211020U);
			s6[3] = tb;
			s6[4] = n + c4;
			s6[5] = t40_la_divs(tb - c5, s0, 211056U) + c5;
			return;
		}
		if (c1 + 1 == s0 || s0 == 1) {
			s6[0] = 0;
			s6[4] = s6[2];
			s6[5] = s6[3];
		} else {
			s6[0] = 1;
			s0 -= c1;
			s6[4] = t40_la_divs(tr - c4, s0, 210948U) + c4;
			s6[5] = t40_la_divs(tb - c5, s0, 210980U) + c5;
		}
		s6[1] = s6[1] + 1;
	}
}

/* VAE_STOP adapter: same o32 arguments as the OEM call; the caller does not use the return value */
static u64 vawb_s_tisp_awb_long_alogrithm(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_awb_long_alg(a0, a1);
	return 0;
}

#undef T40_LA_P32
#undef T40_LA_P16
#undef T40_LA_P8
