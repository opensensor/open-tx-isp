# ISP Tuning Math — Ingenic T31 Tiziano Pipeline

Reference document for the fixed-point math, algorithm structures, and OEM
behavioral patterns discovered during the open-source driver reimplementation.

---

## 1. Fixed-Point Conventions

The T31 ISP uses Q-format fixed-point arithmetic throughout.  The precision
parameter `q` (typically 10) is stored in `_AePointPos.data[0]`.

| Helper | Signature | Semantics |
|--------|-----------|-----------|
| `fix_point_mult2_32(q, a, b)` | `(a * b) >> q` via split-multiply | Q-format multiply |
| `fix_point_mult3_32(q, a, b, c)` | `mult2(mult2(a,b), c)` | Triple multiply |
| `fix_point_div_32(q, num, den)` | `(num << q) / den` | Q-format divide |
| `tisp_simple_intp(hi, lo, array[9])` | Linear interp in gain-indexed 9-entry curve | Gain-dependent parameter interpolation |

**Critical lesson:** `fix_point_mult2_32` and `fix_point_div_32` are NOT
interchangeable.  A single mult↔div swap produces overflow garbage that
corrupts entire processing blocks (see ADR weight normalization below).

---

## 2. AE (Auto Exposure) Convergence

### 2.1 Initial Exposure Seeding

The OEM initializes the AE algorithm's "current IT" from `IspAeExp`, which is
populated by `tiziano_ae_init_exp_th()` from `ae_exp_th[0]` (the sensor-clamped
maximum integration time, typically 1410 lines for GC2053).

**Bug found:** Our `_ae_reg.data[0]` started at 0, clamped to IT=1.  With IT=1:
- `var_b8` (base EV) = 0x400 (1.0 in Q10) — trivially small
- FIFO seeded with small value → `tisp_ae_target` maps to `lum_list[0]` = 10000
- Frame 2: FIFO value == target → ratio=1.0 → false convergence → stuck dark

**Fix:** `if (cur_it == 0) cur_it = ae_exp_th.data[0]` in both
`tisp_ae0_process_impl` and `ae0_tune2`.  AE now starts at max exposure and
converges downward — matching OEM "bright start" behavior.

### 2.2 EV FIFO and Convergence Check

```
ratio = s5 / s6        (target / FIFO average)
new_ev = var_b8 * ratio (base EV scaled by ratio)
```

The FIFO depth is controlled by `_exp_parameter.data[2]`.  With depth=1, only
the most recent entry matters.  If `ae0_conv_state[0]` (the target) is pushed
as the FIFO value AND equals `s5`, ratio=1.0 permanently → no further changes.

### 2.3 Gain Distribution (Phase H, Mode 0)

```
v0_121 = s2_2 / (AG * DG)           // needed total ratio
s2_3   = max_IT << q                 // IT headroom
IT_new = v0_121 >> q                 // integer part → IT
AG_rem = v0_121 / IT_new             // remainder → AG
DG_rem = v0_121 / (IT_new * AG_max)  // overflow → DG
```

IT is computed as `(v0_121 >> qm) << qm` — rounds down to integer.  With
v0_121 < 2.0 in Q10 (< 2048), IT rounds to 1 and never increases.

---

## 3. ADR (Adaptive Dynamic Range) Tone Mapping

### 3.1 Architecture

ADR divides the frame into a **10×18 block grid** (180 blocks at 10 rows,
18 columns).  For each block it computes an 11-point tone curve that maps
input luminance to output luminance.  The curves are written as 264 packed
16-bit values to registers `0x4084..0x4290` (132 words).

Only 24 of the 180 blocks have independent curves; the hardware interpolates
between them spatially.

### 3.2 Tone Curve Computation (`subsection`)

The `subsection()` function computes 9 kneepoints (indices 0-8) for a given
light level using the gamma LUT:

1. **Kneepoint 4** (midpoint): `subsection_map(0x1388, ...)` → gamma lookup
2. **Kneepoint 2**: `subsection_map(lut[idx4]/2, mapped/v0, ...)` → gamma lookup
3. **Kneepoint 1**: `subsection_map(lut[idx2]/2, mapped2/v0, ...)` → gamma lookup
4. **Kneepoint 3**: `subsection_map((lut[idx4]+lut[idx2])/2, (mapped+mapped2)/v0, ...)` → gamma lookup
5. **Kneepoints 5-7**: `result[4] + {1, 2, 3}` (fine steps above midpoint)
6. **Kneepoint 0** = 0, **Kneepoint 8** = 0xFFF

**Bug found:** Kneepoint 1 was set to `result[2]` (placeholder).  The OEM
computes it via a third `subsection_map` call with `lut[idx_from_result2]/2`
and `mapped2` as inputs.

### 3.3 Gamma Lookup Convention (CRITICAL)

The `subsection` function and `subsection_map` use **opposite gamma lookup
directions**:

| Function | Iterates | Interpolates | Direction |
|----------|----------|-------------|-----------|
| `subsection_map` | `gam_lut_a` (param 4) | `gam_lut_b` (param 5) | Forward gamma |
| `subsection` inline | `gam_lut_b` (param 4) | `gam_lut_a` (param 3) | Inverse gamma |

This is intentional in the OEM — `subsection_map` finds an output Y for a
given input X (forward), while `subsection`'s inline lookups find an input X
for a given output Y (inverse).

When calling `subsection_map` from within `subsection`, the original parameters
`gam_lut_a, gam_lut_b` are passed unchanged (matching OEM's `arg3, arg4`).

### 3.4 Per-Block Weight Normalization

```c
// OEM (correct):
mapped_weight = (fix_point_div_32(0xa, weight << 0xa, 0x19000) + 0x200) >> 0xa;

// Bug (overflow):
mapped_weight = (fix_point_mult2_32(0xa, weight << 0xa, 0x19000) + 0x200) >> 0xa;
```

`0x19000` = 102400 = 100×1024.  Division normalizes weight (0-10000) into an
index (0-100) for tone curve interpolation.  Multiplication overflows to ~10^9,
producing garbage spatial indices.

### 3.5 Register Write Format

ADR tone curves are written as packed 16-bit pairs:
```c
for (i = 0x4084; i != 0x4294; i += 4) {
    system_reg_write(i, (mkp_y[1] << 16) | (mkp_y[0] & 0xFFFF));
    mkp_y += 2;
}
```

**Bug found:** Previous code used `tisp_adr_build_lut_payload()` which packed
weight LUTs and parameter arrays instead of `map_kneepoint_y`.  The hardware
read garbage as tone curves.

---

## 4. AWB (Auto White Balance) Gain Application

### 4.1 Gain Computation

```
gain = (fix_point_mult2_32(pp, mf << q, wb_static) + rounding) >> q
```

Where `pp` = `_AwbPointPos.data[0]` (typically 0xa = Q10), `mf` = moving filter
output, `wb_static` = calibration base gain from tuning binary.

### 4.2 Register Packing

```c
reg = (gain << 2) | 0x04000000;   // gain in bits [17:2], 0x400 in bits [31:26]
// 0x1804/0x180c = reg_pair[0]    (R/Gr channel)
// 0x1808/0x1810 = reg_pair[1]    (B/Gb channel)
```

Latch sequence: `system_reg_write_awb(2, ...)` writes `0x1800=1` before each
value register.

---

## 5. GIB (Gain Interpolation Balance)

### 5.1 BLC Register Gate

GIB uses double-buffered registers at `0x1060-0x106c`.  Writes require a gate
open via `0x1070=1`:

```c
void system_reg_write_gib(u32 arg1, u32 reg, u32 val) {
    if (arg1 == 1) system_reg_write(0x1070, 1);  // gate open
    system_reg_write(reg, val);                    // value write
}
```

### 5.2 BLC Configuration (`0x103c`)

```
bits [1:0]   = BLC_GAIN
bits [7:4]   = BLC_THR
bits [9:8]   = GIB_MODE
bit  [10]    = EN_BLC
bit  [12]    = config_line[0]
bits [13:12] = BLC_SHIFT
bits [31:16] = BLEND
```

For GC2053: BLC=257 per channel, BLC_SHIFT=1, EN_BLC=1.

---

## 6. Bypass Register (`0x0c`)

### 6.1 Non-WDR Mode

```
AND mask: 0xb577fffd    (preserves tuning-binary-controlled bits)
OR  mask: 0x34000009    (sets bits 0, 3, 26, 28, 29)
```

**Bug found:** OR mask was `0x34002029` — extra bits 5 (GIB) and 13 (GB) were
force-bypassed as a workaround for a since-fixed R=G=B equalization bug.

### 6.2 Bit Map (selected)

| Bit | Block | GC2053 Day | GC2053 Night |
|-----|-------|------------|--------------|
| 5   | GIB   | 0 (active) | 0 (active)   |
| 6   | LSC   | 1 (bypass) | 0 (active)   |
| 9   | CCM   | 1 (bypass) | 1 (bypass)   |
| 13  | GB    | 1 (bypass) | 1 (bypass)   |
| 16  | MDNS  | 0 (active) | 0 (active)   |

---

## 7. BCSH (Brightness/Contrast/Saturation/Hue)

### 7.1 H-Matrix Registers (`0x8024-0x8038`)

The H-matrix is a 3×3 color space conversion matrix written as 9 values
packed into 6 registers:

```
0x8024 = PACK16(Hreg[1], Hreg[0])
0x8028 = Hreg[2]
0x802c = PACK16(Hreg[4], Hreg[3])
0x8030 = Hreg[5]
0x8034 = PACK16(Hreg[7], Hreg[6])
0x8038 = Hreg[8]
```

Identity (0x3ff diagonal) means no color conversion — produces wrong YUV.

### 7.2 Saturation Vectors (`0x806c-0x8070`)

EV-dependent saturation is interpolated from 9-entry SminListS/SmaxListS
arrays loaded from the tuning binary's day/night parameter blocks.

**Known issue:** After day→night mode switch, H-matrix resets to identity
(`0x3ff` diagonal) while saturation shows high values (0x609=1545).  The
`tiziano_bcsh_dn_params_refresh` loads new params but may not trigger the
`tiziano_bcsh_Tccm_RGB2YUV` recomputation needed to rebuild the H-matrix.

---

## 8. Event-Driven Processing

The ISP uses an event system for per-frame updates:

| Event | Callback | Purpose |
|-------|----------|---------|
| 1 | `tisp_ae0_process` | AE frame processing |
| 2 | ADR update | Tone mapping refresh |
| 3 | Defog update | Dehazing |
| 4 | `tisp_tgain_update` | Gain-dependent block refresh (GIB, DMSC, sharpen, SDNS, etc.) |
| 5 | AG update | Analog gain tracking |
| 7 | EV update | BCSH/downstream EV tracking |
| 10 | AWB process | White balance frame processing |

Event 4 (`tisp_tgain_update`) is the master dispatcher that refreshes ALL
gain-interpolated parameters: GIB BLC, GB BLC, DMSC, sharpen, SDNS, DPC,
LSC strength, YDNS, RDNS, MDNS.

---

## 9. Tuning Binary Structure

The GC2053 tuning binary (`gc2053-t31.bin`) contains day and night parameter
blocks at known offsets.  `tparams_day` / `tparams_night` are loaded via
`tiziano_load_parameters()` and `tparams_active` points to the current bank.

Key AE offsets (relative to tparams base):
```
+0x0080  _ae_parameter      (42 uint32, 0xa8 bytes)
+0x0128  ae_exp_th           (20 uint32, 0x50 bytes)
+0x0178  _AePointPos          (2 uint32, 0x08 bytes)
+0x0180  _exp_parameter      (11 uint32, 0x2c bytes)
+0x01ac  ae_ev_step           (5 uint32, 0x14 bytes)
+0x01c0  ae_stable_tol        (4 uint32, 0x10 bytes)
+0x01d0  ae0_ev_list          (10 uint32, 0x28 bytes)
+0x01f8  _lum_list            (10 uint32, 0x28 bytes)
+0x0348  _ae_zone_weight     (225 uint32, 0x384 bytes)
```
