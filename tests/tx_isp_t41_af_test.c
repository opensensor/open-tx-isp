/*
 * T41 AF block (issue #179): driver/t41/tx_isp_t41_af.h against an oracle
 * transcribed literally from the Ghidra decompile of the OEM 1.2.5 module
 * (tisp_af_set_hardware_param, tisp_af_get_statistics, tisp_af_alogrithm,
 * tisp_af_api_get_metric, fix_point_mult2_32), with the decompiler's byte
 * offsets kept as they are.  Shapes the asm confirmed: unaligned u32 loads
 * (lwl/lwr), lhu u16 loads, unsigned divisions.  Random parameter blocks,
 * DMA buffers and workspaces; registers, workspace and parameter bytes
 * must match exactly.
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../driver/t41/tx_isp_t41_af.h"

typedef uint32_t uint;
typedef uint16_t ushort;
typedef uint8_t byte;

static uint32_t seed = 0x179u;
static uint32_t rng(void) { seed ^= seed << 13; seed ^= seed >> 17; seed ^= seed << 5; return seed; }

/* ---- oracle (decompile shape) ---- */
static uint o_regs[64][2];
static unsigned o_n;
static void system_reg_write(uint r, uint v) { o_regs[o_n][0] = r; o_regs[o_n][1] = v; o_n++; }
static void system_reg_write_af(int a, int ch, uint r, uint v) { (void)ch; if (a == 1) system_reg_write(0x1a000, 1); system_reg_write(r, v); }
static uint U16(const byte *p, int o) { ushort v; memcpy(&v, p + o, 2); return v; }
static uint U32(const byte *p, int o) { uint v; memcpy(&v, p + o, 4); return v; }
static void W16(byte *p, int o, uint v) { ushort s = (ushort)v; memcpy(p + o, &s, 2); }
static void W32(byte *p, int o, uint v) { memcpy(p + o, &v, 4); }
static const byte CSWTCH_12[15] = { 3, 5, 7, 9, 11, 13, 15, 17, 20, 22, 24, 26, 28, 30, 32 };

struct o_info { byte *params; byte *ws; ushort w, h; };

static int fix_point_mult2_32(uint param_1, uint param_2, uint param_3)
{
	uint uVar1 = 0xffffffff >> (-param_1 & 0x1f);
	uint uVar2 = param_2 >> (param_1 & 0x1f);
	uint uVar3 = param_3 >> (param_1 & 0x1f);
	param_2 = uVar1 & param_2;
	uVar1 = uVar1 & param_3;
	return param_2 * uVar3 + uVar2 * uVar1 + (uVar2 * uVar3 << (param_1 & 0x1f)) +
	       (param_2 * uVar1 >> (param_1 & 0x1f));
}

static void o_set_hw(struct o_info *pi)
{
	byte *iVar8 = pi->params;
	if (pi->ws[0x191e] == 0) {
		uint uVar1 = U16(iVar8, 0x52);
		uint uVar9 = (uint)((int)((pi->w - U16(iVar8, 0x50)) + -0xe) / (int)uVar1);
		uint uVar2 = U16(iVar8, 0x4c), uVar3 = U16(iVar8, 0x4e), uVar4 = pi->h, uVar5;
		int iVar7;
		pi->ws[0x191e] = 1;
		uVar5 = uVar9 & 0xffff;
		if (uVar9 & 1) uVar5 = (uVar5 - 1) & 0xffff;
		for (iVar7 = 0; iVar7 < (int)uVar1; iVar7++) W16(iVar8, (iVar7 + 0x24) * 2 + 0xc, uVar5);
		uVar9 = (uint)((int)((uVar4 - uVar2) + -2) / (int)uVar3);
		uVar5 = uVar9 & 0xffff;
		if (uVar9 & 1) uVar5 = (uVar5 - 1) & 0xffff;
		for (iVar7 = 0; iVar7 < (int)uVar3; iVar7++) W16(iVar8, (iVar7 + 0x33) * 2 + 0xc, uVar5);
		system_reg_write(0x1a004, U16(iVar8, 0x52) << 0x1c | U16(iVar8, 0x50) << 0x10 | U16(iVar8, 0x4c) | U16(iVar8, 0x4e) << 0xc);
		system_reg_write(0x1a008, U32(iVar8, 0x54));
		system_reg_write(0x1a00c, U32(iVar8, 0x58));
		system_reg_write(0x1a010, U32(iVar8, 0x5c));
		system_reg_write(0x1a014, U32(iVar8, 0x60));
		system_reg_write(0x1a018, U32(iVar8, 100));
		system_reg_write(0x1a01c, U32(iVar8, 0x68));
		system_reg_write(0x1a020, U32(iVar8, 0x6c));
		system_reg_write(0x1a024, U16(iVar8, 0x70));
		system_reg_write(0x1a028, U16(iVar8, 0x78) << 0x18 | U16(iVar8, 0x76) << 0x10 | U16(iVar8, 0x72) | U16(iVar8, 0x74) << 8);
		system_reg_write(0x1a02c, U16(iVar8, 0x80) << 0x18 | U16(iVar8, 0x7e) << 0x10 | U16(iVar8, 0x7a) | U16(iVar8, 0x7c) << 8);
		system_reg_write(0x1a030, U16(iVar8, 0x88) << 0x18 | U16(iVar8, 0x86) << 0x10 | U16(iVar8, 0x82) | U16(iVar8, 0x84) << 8);
		system_reg_write(0x1a034, U16(iVar8, 0x8e) << 0x10 | U16(iVar8, 0x8c) << 8 | U16(iVar8, 0x8a));
	}
	system_reg_write_af(1, 0, 0x1a038, U16(iVar8, 0x92) << 0x10 | (uint)iVar8[0x202] << 8 | U16(iVar8, 0x90) |
			    (uint)iVar8[0x201] << 7 | (uint)iVar8[0x200] << 6 | (uint)iVar8[0x1ff] << 5 | (uint)iVar8[0x1fe] << 4);
	system_reg_write(0x1a03c, (uint)iVar8[0x20a] << 0x1c | (uint)iVar8[0x209] << 0x18 | (uint)iVar8[0x203] | (uint)iVar8[0x208] << 0x14 |
			 (uint)iVar8[0x207] << 0x10 | (uint)iVar8[0x206] << 0xc | (uint)iVar8[0x205] << 8 | (uint)iVar8[0x204] << 4);
	system_reg_write(0x1a040, U32(iVar8, 0x118));
	system_reg_write(0x1a044, U32(iVar8, 0x11c));
	system_reg_write(0x1a048, U16(iVar8, 0x120));
	system_reg_write(0x1a04c, U32(iVar8, 0x142));
	system_reg_write(0x1a050, U32(iVar8, 0x146));
	system_reg_write(0x1a054, U16(iVar8, 0x14a));
	system_reg_write(0x1a058, U16(iVar8, 0x170) << 16 | U16(iVar8, 0x16c));
	system_reg_write(0x1a05c, U32(iVar8, 0x172));
	system_reg_write(0x1a060, U16(iVar8, 0x17a) << 16 | U16(iVar8, 0x176));
	system_reg_write(0x1a064, U32(iVar8, 0x17c));
	system_reg_write(0x1a068, U16(iVar8, 0x1a4) << 16 | U16(iVar8, 0x1a0));
	system_reg_write(0x1a06c, U32(iVar8, 0x1a6));
	system_reg_write(0x1a070, U16(iVar8, 0x1ae) << 16 | U16(iVar8, 0x1aa));
	system_reg_write(0x1a074, U32(iVar8, 0x1b0));
	system_reg_write(0x1a078, U16(iVar8, 0x126) << 0x10 | U16(iVar8, 0x124) << 8 | U16(iVar8, 0x122));
	system_reg_write(0x1a07c, U16(iVar8, 0x12e) << 0x10 | U16(iVar8, 300) << 8 | U16(iVar8, 0x12a));
	system_reg_write(0x1a080, U16(iVar8, 0x150) << 0x10 | U16(iVar8, 0x14e) << 8 | U16(iVar8, 0x14c));
	system_reg_write(0x1a084, U16(iVar8, 0x158) << 0x10 | U16(iVar8, 0x156) << 8 | U16(iVar8, 0x154));
	system_reg_write(0x1a088, U16(iVar8, 0x184) << 0x10 | U16(iVar8, 0x182) << 8 | U16(iVar8, 0x180));
	system_reg_write(0x1a08c, U16(iVar8, 0x18c) << 0x10 | U16(iVar8, 0x18a) << 8 | U16(iVar8, 0x188));
	system_reg_write(0x1a090, U16(iVar8, 0x1b8) << 0x10 | U16(iVar8, 0x1b6) << 8 | U16(iVar8, 0x1b4));
	system_reg_write(0x1a094, U16(iVar8, 0x1c0) << 0x10 | U16(iVar8, 0x1be) << 8 | U16(iVar8, 0x1bc));
	system_reg_write(0x1a098, U16(iVar8, 0x15a) << 0x18 | U16(iVar8, 0x152) << 0x10 | U16(iVar8, 0x128) | U16(iVar8, 0x130) << 8);
	system_reg_write(0x1a09c, U16(iVar8, 0x1c2) << 0x18 | U16(iVar8, 0x1ba) << 0x10 | U16(iVar8, 0x186) | U16(iVar8, 0x18e) << 8);
	system_reg_write(0x1a0a0, U16(iVar8, 0x138) << 0x18 | U16(iVar8, 0x136) << 0x10 | U16(iVar8, 0x132) | U16(iVar8, 0x134) << 8);
	system_reg_write(0x1a0a4, U16(iVar8, 0x162) << 0x18 | U16(iVar8, 0x160) << 0x10 | U16(iVar8, 0x15c) | U16(iVar8, 0x15e) << 8);
	system_reg_write(0x1a0a8, U16(iVar8, 0x196) << 0x18 | U16(iVar8, 0x194) << 0x10 | U16(iVar8, 400) | U16(iVar8, 0x192) << 8);
	system_reg_write(0x1a0ac, U16(iVar8, 0x1ca) << 0x18 | U16(iVar8, 0x1c8) << 0x10 | U16(iVar8, 0x1c4) | U16(iVar8, 0x1c6) << 8);
	system_reg_write(0x1a0b0, (uint)iVar8[0x212] << 0x1c | (uint)iVar8[0x211] << 0x18 | (uint)iVar8[0x20b] | (uint)iVar8[0x210] << 0x14 |
			 (uint)iVar8[0x20f] << 0x10 | (uint)iVar8[0x20e] << 0xc | (uint)iVar8[0x20d] << 8 | (uint)iVar8[0x20c] << 4);
	system_reg_write(0x1a0b4, U16(iVar8, 0x166) << 0x18 | U16(iVar8, 0x164) << 0x10 | U16(iVar8, 0x13a) | U16(iVar8, 0x13c) << 8);
	system_reg_write(0x1a0b8, U16(iVar8, 0x1ce) << 0x18 | U16(iVar8, 0x1cc) << 0x10 | U16(iVar8, 0x198) | U16(iVar8, 0x19a) << 8);
	system_reg_write(0x1a0bc, U32(iVar8, 0x13e));
	system_reg_write(0x1a0c0, U32(iVar8, 0x168));
	system_reg_write(0x1a0c4, U32(iVar8, 0x19c));
	system_reg_write(0x1a0c8, U32(iVar8, 0x1d0));
}

static void o_get_statistics(struct o_info *pi, byte *param_2)
{
	uint uVar20 = U16(pi->params, 0x52), uVar1 = U16(pi->params, 0x4e);
	uint uVar2 = (uVar20 - 1) & 0xffff, uVar5 = 0x20, uVar17;
	int iVar18 = 0;
	if (uVar2 < 0xf) uVar5 = CSWTCH_12[uVar2];
	for (uVar2 = 0; uVar2 < uVar1; uVar2++, iVar18 += uVar5 * 2) {
		for (uVar17 = 0; uVar17 < uVar20; uVar17++) {
			byte *puVar3 = param_2 + (uVar17 * 4 + iVar18) * 4 + (uVar17 & 0xfffffffc);
			uint uVar15 = U32(puVar3, 0), uVar14 = U32(puVar3, 4), uVar12 = U32(puVar3, 8);
			uint uVar13 = U32(puVar3, 12), uVar6 = U32(puVar3, 16), uVar19 = uVar17 & 3;
			int iVar4 = uVar2 * 0xf + uVar17;
			int iVar16 = iVar4 * 4, iVar11 = iVar4 + 0xe0, iVar10 = iVar4 + 0x1c0;
			int iVar9 = iVar4 + 0x2a0, iVar8 = iVar4 + 0x380;
			byte *ws = pi->ws;
			iVar4 = iVar4 + 0x460;
			if (uVar19 == 0) {
				W32(ws, iVar16, uVar15 & 0x7fffff);
				W32(ws, iVar11 * 4 + 4, (uVar14 & 0x3fff) << 9 | uVar15 >> 0x17);
				W32(ws, iVar10 * 4 + 8, (uVar12 & 0x1f) << 0x12 | uVar14 >> 0xe);
				W32(ws, iVar9 * 4 + 0xc, (uVar12 & 0xfffffff) >> 5);
				W32(ws, iVar8 * 4 + 0x10, (uVar13 & 0xfffff) << 4 | uVar12 >> 0x1c);
				W32(ws, iVar4 * 4 + 0x14, (uVar6 & 0xf) << 0xc | uVar13 >> 0x14);
			} else if (uVar19 == 1) {
				W32(ws, iVar16, (uVar15 & 0x7fffffff) >> 8);
				W32(ws, iVar11 * 4 + 4, (uVar14 & 0x3fffff) << 1 | uVar15 >> 0x1f);
				W32(ws, iVar10 * 4 + 8, (uVar12 & 0x1fff) << 10 | uVar14 >> 0x16);
				W32(ws, iVar9 * 4 + 0xc, (uVar13 & 0xf) << 0x13 | uVar12 >> 0xd);
				W32(ws, iVar8 * 4 + 0x10, (uVar13 & 0xfffffff) >> 4);
				W32(ws, iVar4 * 4 + 0x14, (uVar6 & 0xfff) << 4 | uVar13 >> 0x1c);
			} else if (uVar19 == 2) {
				W32(ws, iVar16, (uVar14 & 0x7f) << 0x10 | uVar15 >> 0x10);
				W32(ws, iVar11 * 4 + 4, (uVar14 & 0x3fffffff) >> 7);
				W32(ws, iVar10 * 4 + 8, (uVar12 & 0x1fffff) << 2 | uVar14 >> 0x1e);
				W32(ws, iVar9 * 4 + 0xc, (uVar13 & 0xfff) << 0xb | uVar12 >> 0x15);
				W32(ws, iVar8 * 4 + 0x10, (uVar6 & 0xf) << 0x14 | uVar13 >> 0xc);
				W32(ws, iVar4 * 4 + 0x14, (uVar6 & 0xfffff) >> 4);
			} else {
				W32(ws, iVar16, (uVar14 & 0x7fff) << 8 | uVar15 >> 0x18);
				W32(ws, iVar11 * 4 + 4, (uVar12 & 0x3f) << 0x11 | uVar14 >> 0xf);
				W32(ws, iVar10 * 4 + 8, (uVar12 & 0x1fffffff) >> 6);
				W32(ws, iVar9 * 4 + 0xc, (uVar13 & 0xfffff) << 3 | uVar12 >> 0x1d);
				W32(ws, iVar8 * 4 + 0x10, (uVar6 & 0xfff) << 0xc | uVar13 >> 0x14);
				W32(ws, iVar4 * 4 + 0x14, (uVar6 & 0xfffffff) >> 0xc);
			}
		}
	}
}

static void o_alogrithm(struct o_info *pi)
{
	byte *puVar26 = pi->params, *iVar28 = pi->ws;
	uint uVar2 = U16(puVar26, 0x1d8), uVar25 = U16(puVar26, 0x1dc), uVar3 = U16(puVar26, 0x1d4);
	uint uVar4 = U16(puVar26, 0x1da), uVar5 = U16(puVar26, 0x1d6);
	int iVar18 = 1 << (uVar25 & 0x1f);
	uint uVar6 = U16(puVar26, 0x4e), uVar20 = U16(iVar28, 0x191c), uVar27 = 0, uVar7 = U16(puVar26, 0x52);
	uint uVar29 = 0, uVar30 = 0, uVar21, uVar19;
	byte *iVar22 = iVar28 + 0x708, *iVar23 = iVar28 + 0xa8c, *iVar24 = iVar28 + 900, *iVar31 = puVar26 + 0x213;
	int i;
	for (uVar21 = 0; uVar21 < uVar6; uVar21++) {
		for (uVar19 = 0; uVar19 < uVar7; uVar19++) {
			int iVar13 = uVar19 * 4;
			uint uVar15 = U32(iVar23, iVar13), uVar16 = U32(iVar28, iVar13), uVar17 = U32(iVar24, iVar13);
			int a = fix_point_mult2_32(uVar25, (U32(iVar22, iVar13) >> (uVar20 & 0x1f)) << (uVar25 & 0x1f), uVar3);
			int b = fix_point_mult2_32(uVar25, (uVar16 >> (uVar20 & 0x1f)) << (uVar25 & 0x1f), iVar18 - uVar3);
			int c = fix_point_mult2_32(uVar25, (uVar15 >> (uVar20 & 0x1f)) << (uVar25 & 0x1f), uVar5);
			int d = fix_point_mult2_32(uVar25, (uVar17 >> (uVar20 & 0x1f)) << (uVar25 & 0x1f), iVar18 - uVar5);
			uVar15 = iVar31[uVar19];
			uVar27 += uVar15;
			uVar30 = ((uint)(iVar18 / 2 + a + b) >> (uVar25 & 0x1f)) * uVar15 + uVar30;
			uVar29 = ((uint)(c + d + iVar18 / 2) >> (uVar25 & 0x1f)) * uVar15 + uVar29;
		}
		iVar31 += 0xf; iVar28 += 0x3c; iVar24 += 0x3c; iVar23 += 0x3c; iVar22 += 0x3c;
	}
	if (!uVar27)
		return;	/* OEM: divu by zero */
	{
		int e = fix_point_mult2_32(uVar25, uVar30 / uVar27 << (uVar25 & 0x1f), uVar2);
		int f = fix_point_mult2_32(uVar25, uVar29 / uVar27 << (uVar25 & 0x1f), uVar4);
		int g = fix_point_mult2_32(uVar25, (uVar30 >> 3) << (uVar25 & 0x1f), uVar2);
		int h = fix_point_mult2_32(uVar25, (uVar29 >> 3) << (uVar25 & 0x1f), uVar4);
		byte *ws = pi->ws;
		int n = uVar7 * uVar6;
		char cVar1;
		uVar21 = (uint)(e + f) >> (uVar25 & 0x1f);
		uVar20 = (uint)(g + h) >> (uVar25 & 0x1f);
		for (i = 0; i < 14; i++) W32(puVar26, i * 4, U32(puVar26, i * 4 + 4));
		W32(puVar26, 0xe * 4, uVar21);
		W32(puVar26, 0xf * 4, uVar20);
		W32(puVar26, 0x11 * 4, n * (uVar30 / uVar27));
		W32(puVar26, 0x10 * 4, n * uVar21);
		W32(puVar26, 0x12 * 4, n * (uVar29 / uVar27));
		cVar1 = (char)ws[0x191f];
		if (cVar1 < 0 || cVar1 > 3)
			return;
		for (i = 0; i < 0xfe; i++) W32(ws, i * 4 + 0x151c, U32(ws, i * 4 + 0x1520));
		W32(ws, 0x1914, cVar1 == 0 ? uVar20 : U32(puVar26, (0x10 + cVar1 - 1) * 4));
	}
}

/* ---- test ---- */
static uint8_t pa[T41_AF_PARAM_BYTES], pb[T41_AF_PARAM_BYTES];
static uint32_t wsa_w[T41_AF_WS_BYTES / 4], wsb_w[T41_AF_WS_BYTES / 4];
static uint32_t dma[T41_AF_BUF_BYTES / 4];

int main(void)
{
	uint8_t *wsa = (uint8_t *)wsa_w, *wsb = (uint8_t *)wsb_w;
	unsigned int f, i, fail = 0, valid = 0, nonzero = 0;
	uint32_t regs[T41_AF_MAX_REGS][2], m[3];

	/* fpm2 vs OEM shape */
	for (f = 0; f < 100000; f++) {
		uint32_t s = rng() & 31, a = rng(), b = rng();
		if (t41_af_fpm2(s, a, b) != (uint32_t)fix_point_mult2_32(s, a, b) && fail++ < 10)
			printf("fpm2 %u %08x %08x\n", s, a, b);
	}
	for (f = 0; f < 20000; f++) {
		struct o_info oi;
		uint32_t w = 640 + rng() % 2300, h = 360 + rng() % 1300;
		unsigned int n;

		for (i = 0; i < sizeof(pa); i++) pa[i] = (uint8_t)rng();
		for (i = 0; i < sizeof(wsa_w) / 4; i++) wsa_w[i] = rng();
		for (i = 0; i < sizeof(dma) / 4; i++) dma[i] = rng();
		/* geometry: valid most of the time, sometimes garbage */
		if (f % 8) {
			t41_af_wr16(pa, 0x52, 1 + rng() % 15);
			t41_af_wr16(pa, 0x4e, 1 + rng() % 15);
			t41_af_wr16(pa, 0x50, rng() % 64);
			t41_af_wr16(pa, 0x4c, rng() % 64);
		}
		/* small shifts / weights so the metric path is exercised as well as wrap */
		if (f % 3 == 0) t41_af_wr16(pa, 0x1dc, rng() % 16);
		if (f % 5 == 0) t41_af_wr16(wsa, T41_AF_WS_SHIFT, rng() % 8);
		if (f % 7 == 0) memset(pa + 0x213, 0, 225);
		wsa[T41_AF_WS_HIST_SRC] = (uint8_t)(rng() % 6);
		wsa[T41_AF_WS_HW_DONE] = (uint8_t)(rng() & 1);
		memcpy(pb, pa, sizeof(pa));
		memcpy(wsb, wsa, sizeof(wsa_w));
		if (!t41_af_geometry_ok(pa, w, h))
			continue;
		valid++;
		oi.params = pb; oi.ws = wsb; oi.w = (ushort)w; oi.h = (ushort)h;
		o_n = 0;
		o_set_hw(&oi);
		n = t41_af_hw_param(pa, wsa, w, h, regs);
		if (n != o_n && fail++ < 20)
			printf("case %u: %u regs, OEM %u\n", f, n, o_n);
		for (i = 0; i < n && i < o_n; i++)
			if ((regs[i][0] != o_regs[i][0] || regs[i][1] != o_regs[i][1]) && fail++ < 20)
				printf("case %u reg %u: %05x=%08x OEM %05x=%08x\n", f, i,
				       regs[i][0], regs[i][1], o_regs[i][0], o_regs[i][1]);
		o_get_statistics(&oi, (byte *)dma);
		t41_af_unpack(pa, wsa, dma);
		o_alogrithm(&oi);
		if (t41_af_algorithm(pa, wsa)) nonzero++;
		if ((memcmp(pa, pb, sizeof(pa)) || memcmp(wsa, wsb, sizeof(wsa_w))) && fail++ < 20) {
			for (i = 0; i < sizeof(pa) && pa[i] == pb[i]; i++) ;
			printf("case %u: params differ at %#x", f, i);
			for (i = 0; i < sizeof(wsa_w) && wsa[i] == wsb[i]; i++) ;
			printf(", ws differs at %#x\n", i);
		}
		t41_af_metric(pa, wsa, f & 3, m);
		if ((m[0] != U32(pb, 0x40) >> (f & 3) || m[1] != U32(pb, 0x3c) >> (f & 3) ||
		     m[2] != (U32(wsb, 0x1518) & 0xff)) && fail++ < 20)
			printf("case %u: metric mismatch\n", f);
	}
	/* rejects: zero / too many zones, frame too small */
	memset(pa, 0, sizeof(pa));
	if (t41_af_geometry_ok(pa, 1920, 1080)) fail++;
	t41_af_wr16(pa, 0x52, 15); t41_af_wr16(pa, 0x4e, 16);
	if (t41_af_geometry_ok(pa, 1920, 1080)) fail++;
	t41_af_wr16(pa, 0x4e, 15);
	if (!t41_af_geometry_ok(pa, 1920, 1080) || t41_af_geometry_ok(pa, 40, 1080)) fail++;
	printf("t41 AF vs OEM decompile: %u valid of 20000 cases, %u with metric update, %u mismatches\n",
	       valid, nonzero, fail);
	return fail || valid < 10000 || nonzero < 5000 ? 1 : 0;
}
