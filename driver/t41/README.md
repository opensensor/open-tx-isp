# Ingenic T41 ISP Recovery

Latest tuning status: [the September IQ audit](../../docs/T41_STOCK_OPEN_IQ.md)
and [scalar TMO recovery](../../docs/T41_TMO_ALGORITHM.md). The older bring-up
profiles below are historical, not claims of generic tuning support.

Current T41 status (fully open from a flashed image, reload verified): see the
status table in the repository `README.md`. The recovery-grade wording below
describes the code quality, not the feature status.

This directory contains the recovered T41 TX-ISP driver baseline for the Wyze
Cam v4 T41NQ/OS04D10 Linux 4.4.94 target. It was generated from the OEM
`tx-isp-t41.ko` whose SHA-256 is
`2426eea9c3c8268373eccc3c3753424f0429ff02044e4ddd4e86c6caa40a6338`.

The source was salvaged from the June 2026 `tx-isp-t41-v1` reconstruction
workspace. All 1,510 function candidates were emitted and 1,508 compiled in
isolation, but only 157 were normalized exact matches. A later manual cleanup
made the whole driver build. It now has staged hardware coverage through the
OS04D10 sensor and Raptor consumer, but it remains recovery-grade code rather
than a production-equivalent replacement.

## Build

Build against the matching Thingino Wyze Cam v4 output:

```sh
ROOT=/path/to/thingino-firmware/output/<target> \
KDIR="$ROOT/build/linux-2aca1252ac4a304172b870777365f42bfb100674" \
SOC=t41 ./build_local.sh
```

Expected artifact:

- `driver/t41/tx-isp-t41.ko`

The source remains named `tx_isp_t41_recovered.c`, but Kbuild emits the
canonical module name expected by current T41 sensor modules
(`depends: tx-isp-t41`).

The module is linked from nine logical objects:

- `tx_isp_t41_recovered.c` — recovered core, pipeline, hardware, and tuning
- `tx_isp_t41_daynight.c` — T41 adapter for the shared day/night state machine
- `tx_isp_t41_math.c` — T41 ABI wrappers around shared math primitives
- `tx_isp_t41_sinfo.c` — T41 layout adapter around the shared sensor registry
- `tx_isp_t41_subdev.c` — extended T41 graph-layout adapter around the shared
  name/type/index pad resolver, link-state core, and checked remote-event
  route resolver
- `tx_isp_t41_tuning_abi.c` — shared tuning-envelope and command-descriptor
  implementation
- `tx_isp_t41_frame_layout.c` — shared checked NV12 geometry and vendor
  aggregate-line semantics used by set-format and QBUF; it also imports the
  shared 68-byte frame-buffer ABI, 116-byte extended frame-format ABI, and
  generation-specific flag policy
- `tx_isp_frame_channel.h` supplies the proven common event IDs and T41's
  exact private-`T` ioctl envelopes to the recovered dispatcher and IRQ paths
- `tx_isp_subdev_abi.h` names the pad/link fields used by remote event
  dispatch and frame-channel callback installation, and supplies the shared
  T23/T41 recovered link-detach prefix while retaining link state
- `tx_isp_t41_exposure.c` — T41 sensor/color adapter around the shared checked
  anti-flicker exposure planner
- `tx_isp_t41_scaler.c` — exact T41 coefficient-table adapter around the
  shared checked polyphase scaler generator

## Baseline risk

The recovered module is a bring-up artifact, not a production-ready driver.
The current linked-binary audit finds 18 stub functions, 91 collapsed
functions, 386 shorter functions, and 41 OEM-only symbols. Critical deficits
remain in core control/ioctl dispatch and tuning paths.

Completed static repairs restore all 31 OEM exports and replace the recovered
IRQ wrappers that previously requested IRQ 0 with null handlers and disabled
IRQ 0 regardless of their arguments. The linked audit now classifies the IRQ
enable/disable helpers as shorter rather than stubs, and the request/free paths
as similar in instruction count.

The T41 module now reuses the common day/night state machine,
interpolation/fixed-point helpers, checked exposure and scaler arithmetic, and
the T23/T31/T41 typed sensor-registry implementation. Full sensor/Raptor smoke
tests pass, both MSCA streams run, and ISP interrupts advance. The static AWB
safety fallback is now `R=1800, B=3000`; both shadow banks retain those values
across forced day/night transitions. It runs with the exact active OEM OS04D10
day CCM and unity GIB. The older half-GIB/custom-CCM combination remains
available only as an explicitly selected experiment. The shared
registry reports one active OS04D10 with chip `0x530444`, address `0x3c`,
native 2560x1440 geometry, and 25 fps; both driver-add and sensor-bind report
one successful lifecycle call.

The optional T41 safe-AWB path now consumes all eight packed 16-byte records
in every 128-byte DMA zone group. The earlier record-zero sampler appeared
valid in one spatial phase but changed its ratios by several times when the
hardware advanced the ring, producing red/green flashes. Runtime writes of a
negative value to `t41_safe_awb_controller` rearm the one-shot statistics
engine; disabling it cancels the worker and immediately restores the calibrated
fallback. Read-only parameters expose the selected bank, raw ratios, applied
gains, IRQ/update counts, and rejected samples. A 12.5% consistency gate rejects
partially replaced DMA groups while accepting a persistent illuminant change
after 32 samples. On the mixed daylight/incandescent test scene the controller
held `R=1438..1439, B=3819..3824` across bank transitions while rejecting the
transient groups that previously pulled either channel down by hundreds.
The aggregate controller remains opt-in: in the August 6 full-daylight scene
its current gray-world-to-gain mapping settled near `R=1127, B=1518` and made
the frame green. The fixed mixed-light stock snapshot (`1240/4624`) was also
not a safe daylight fallback: the neutral ceiling measured `U/V=186.05/79.28`.
A two-axis live sweep selected `1800/3000`, measuring `126.97/129.33` on the
same ceiling region and reducing its average saturation from `75.31` to `2.02`.
This closes the severe daylight color regression while the larger OEM AWB
model-selection path is recovered; it does not claim dynamic-AWB parity.

A later matched stock/open capture on August 6 bounded the live-profile state
more precisely. OEM AWB moved from `1484/3516` to `1476/3524` over 20 seconds;
the latter pair is now the deterministic security seed. Replaying the remaining
different GIB/CCM/BCSH writer words did not close the observed luma gap. Raising
the open safe-AE target from `14500` to `17600` did: whole-frame normalized Y
moved from `0.381` to `0.453`, versus `0.450` on stock. Two open-extension
tuning controls now switch the bounded AWB mode/gains and AE target in process
context, without stopping V4L2 capture or the encoder. Policy names and presets
remain in OpenIMP userspace; the experimental aggregate AWB controller remains
explicitly opt-in.

A matched nighttime oracle showed why that daylight seed cannot be the whole
security policy. Stock converged around `1240/4692`, lowered scene luma, and
selected a different 29-word `tisp_bcsh_write_reg()` bank. Replaying only the
gains left open too warm and saturated; replaying the writer-owned low-light
bank plus the matched `15800` AE target closed normalized YUV from stock
`109.568/116.295/138.708` to open `109.546/116.765/137.548`. A third open
tuning command now switches the complete day/low-light color-model bank live.
OpenIMP owns gain-threshold hysteresis and the sensor-specific trims; the
driver owns only the validated register transaction.

The August correctness cycle also restores the T41 1.2 tuning responses used
by RIC: running-mode GET, AE expression, the 256-bin/225-zone AE statistics
envelope, and AWB global statistics. Their packed layouts are implemented in
the common tuning-ABI unit and covered by host tests rather than being open
coded in the recovered ioctl dispatcher. The earlier AE target `17600`, profile
`1`, and the old AWB baseline measured
`Y/U/V/SAT=117.125/119.855/132.521/29.133`, versus
`118.832/119.857/132.143/25.161` on stock. After the aggregate-AWB correction,
the calibrated fallback measured `U/V=125.51/128.88` and the adaptive path
settled at `126.45/128.13`; the controlled stock oracle was `127.66/125.97`.
An in-place AE sweep selected the new `14500` default: it measured
`Y/U/V/SAT=97.54/126.96/128.42/30.57` versus the same-scene stock luma
`99.76`, retained the stock-like 737-line shutter, and reduced the flat-ceiling
standard deviation from `0.0444` at target `16000` to `0.0344`.
The open driver and OpenIMP ran together with no visible block corruption or
H.264 decode errors in repeated frames. All 15 host suites pass; the active
one-shot module SHA-256 is
`cf838ed8f4dfc612389fdee5aeb2377a16636818298b6087da278025a55e8814`.

The July 30 shared-format validation preserved the 3,133,440-byte 1080p pool,
full-rate output, and coherent geometry across two clean boots. It decoded
150 frames in six seconds and 125 in five, passed night/auto/day transitions,
and left the open module active with zero ISP interrupt errors. The validated
module SHA-256 is
`64e7103e81765b5c72a42088bb7b46a12cea1538aae21a9d3cfe4f802ffbc5da`.

The shared frame-channel contract now names the set/get-format, stream,
queue, and completion events plus every T41 private ioctl envelope. Its
REQBUFS path also consumes the common five-word count/type/memory positions
while retaining T41's local allocation, queue-free, and remote-event policy. The
deterministic sequential build's fail-safe boot reports both 1920x1080 and
640x360 streams at 25 fps and saved a fresh 379,001-byte main-stream JPEG.
ISP IRQs advanced, forced day mode applied, and kernel, Raptor, and Android
fault scans were clean. The active module SHA-256 is
`cf79410cf59b3140b4df3eb67b00d69f6fa99e6455b2181ad220cc1d5e73129a`.
The scene was darkening during a storm, so this cycle validates transport and
ABI behavior rather than brightness or noise parity.

The common graph resolver now owns the endpoint name/type/index search while
the T41 adapter retains the graph table at `0x3c`, extended pad slots, and
recovered pointer checks. Its setup path consumes the common 8-byte endpoint,
20-byte graph-link, and 8-byte record-set wire positions. Its one-shot boot bound
the OS04D10 once, applied
day mode, advanced both ISP cores with `error=0`, and decoded 150 1920x1080
frames in six seconds. `dmesg`, `logread`, and `logcat` fault scans were clean.
The tested module remains active with SHA-256
`34aaccbd070010bc704e9588182bfb9f3302a416bcd871111c53f82ae235cd1e`.

Link setup now delegates link-type/stream-state validation and the symmetric
source/sink record write to the common subdevice library. T41 retains
generation-local conflict teardown calls and their recovered ordering. The
one-shot candidate bound the OS04D10 once, accepted forced day mode, advanced
both ISP cores with `error=0`, and decoded 150 1920x1080 frames in six
seconds. `dmesg`, `logread`, and `logcat` fault scans are clean. The candidate
remains active with SHA-256
`7f385cf872d21568dc105b85ca852a4f33a5ade30c72f52451acd880dfeee9d4`.
The scene was darkening during a rainstorm, so this gate covers graph, stream,
and ABI behavior rather than comparative brightness or shadow-noise quality.

Remote-event dispatch now delegates the local-pad, active-sink, and handler
lookup to the shared checked resolver while retaining T41's pointer policy,
event diagnostics, and callback invocation. The fail-safe cycle registered
and bound the OS04D10 once, accepted forced day mode, advanced both ISP cores
with `error=0`, and decoded 151 1920x1080 frames in six seconds. Early kernel
capture shows repeated resolved remote callbacks returning zero, and the final
`dmesg`, `logread`, and `logcat` scans contain no driver faults. The candidate
remains active with SHA-256
`07166ce513a884029b90c3250976da957fd4d6439932cbc17ef67f4946a3f7ae`.
Changing storm light excluded visual-quality comparisons from this gate.

The OEM `check_state` queue/state policy is now shared with T23 while T41
retains its `0x1fc` queue and `0x224` byte-state positions. This replaces the
recovered unconditional-zero body with the OEM decision. The fail-safe boot
bound the OS04D10 once, accepted day mode, advanced both ISP cores with
`error=0`, and decoded 151 1080p frames in six seconds without driver faults.
The candidate remains active with SHA-256
`adb6e008067e4e44f909d6695a6a3f53ac87355e9d5c8766f6d1a5b3e3e84f96`.

The same cycle validates the shared NV12 DMA binding plan in the recovered
late-link queue path. It decoded 150 main frames in six seconds, 75 substream
frames in three, and 103 main frames in the four-second final check without
rejecting a live buffer or changing stream geometry. Later live tuning fixed
the pink-red error and 120 Hz recessed-light shadow cycle with the shared
exposure planner plus the T41 GIB/CCM adapter. The scaler investigation then
found that the recovered path programmed 2560x1440-to-1920x1080 ratios while
leaving ratio-specific hidden filter RAM uninitialized. The shared fixed-point
generator now reproduces the stock unity curve exactly and emits the missing
0.75x Lanczos coefficients. A clean boot logged two successful exact-stock
curve commits, held 1920x1080 at 25 fps, and restored visibly sharper detail
without changing the accepted color profile. The validated module SHA-256 is
`687a90404e6d204e2030c381df4ae1890dfefd1333244115f55ce0f448c35376`.

The shared T41 math adapter now also owns `fix_point_div_32`, backed by the
common OEM-compatible divider while preserving its wrapped 32-bit quotient and
remainder behavior. The hardware cycle held 1920x1080 at 25 fps through a
forced day transition, logged zero ISP interrupt errors, and preserved the
accepted color, clarity, and lighting profile. The validated module SHA-256 is
`27cb2801e4a0b9609b2db175acdfc39be2ab5e2b1ab63e6d956e4574793833d4`.

The common library and T41 math adapter now also own the 32-bit fixed-point
add/subtract entry points, retaining T41's underflow diagnostic locally.
These entry points currently have no live callers. A clean boot decoded 150
frames in six seconds and recorded 125 in five, preserved the accepted
red/color and sharpness profile, passed night/auto/day, and logged zero ISP
interrupt errors. The active module SHA-256 is
`8ff2f59a2c2e555d88b2a9bd7d5f08911b2e84be33a0e9e75c4af1fdafc61a2c`.

The SDK-declared 64-bit add/subtract entry points now live in the same adapter
and delegate to common unsigned wraparound primitives. The recovered six-word
forms represented the MIPS O32 expansion of `(pointpos, u64, u64)`; keeping the
official C signature in the adapter makes that ABI explicit while retaining
T41's underflow diagnostic. These entry points currently have no live callers.
A one-shot boot decoded 151 frames in six seconds, passed night/auto/day,
advanced both ISP cores with `error=0`, and preserved the accepted red/color
and sharpness profile. No driver fault appeared in `dmesg`, `logread`, or
`logcat`. The active module SHA-256 is
`11c850f8dc83fecaeda9fba627e5c1bbeb5db4f77bf851b34adbd4a8432a161f`.

The unsuffixed SDK add/subtract pair exposes the same `(pointpos, u64, u64)`
contract and now lives beside the `_64` pair in the adapter. Both symbol names
are retained for vendor ABI compatibility; neither pair currently has a live
caller. The one-shot boot passed night/auto/day, decoded 126 frames in the
five-second final check, advanced both ISP cores with `error=0`, and logged no
driver fault. The active module SHA-256 is
`c60fddd5000f96a7bfea49e67f059d5417e79e7643395cfbfc093f269186414b`.

The signed 64-bit rounding entry point now lives in the math adapter and uses
the exact behavior recovered directly from both stock modules: arithmetic
shift by `p`, then add bit `p-1`. This replaces a recovered T41 body that added
the parity bit of the already-shifted result. The helper is live throughout
gamma, CSC, color, and filter coefficient generation, so this boundary
requires same-scene image validation in addition to the normal smoke cycle.
The candidate has the stock 140-byte routine size, decoded 152 frames in six
seconds, passed night/auto/day, and advanced both ISP cores with `error=0`.
The post-boot frame retained the accepted sharpness and color profile, while
`dmesg`, `logread`, and `logcat` showed no driver fault. The active module
SHA-256 is
`1aed03add34f3e213e39a654c0389603c23eecf2e39f6d1c9455df87248fbda6`.

The two-/three-operand unsuffixed and `_64` fixed-point multiply entry points
now live in the math adapter as official `(pointpos, u64, ...)` MIPS O32
interfaces. Their common limb implementation retains the full low word of the
128-bit product after the requested Q-format shift without compiler 128-bit
support. The active candidate decoded 152 main frames in six seconds and 75
substream frames in three, passed night/auto/day, kept `rvd` responsive, and
reported zero ISP interrupt errors. Its module SHA-256 is
`03e9f68a3740c03f51caae9269fa339d8d971d2c8566b1a8463daf7ffe1f904e`.

The matching unsuffixed and `_64` divide entry points now use a common
full-domain shift/subtract divider. This replaces one recovery-grade body and
one literal jump-to-null stub without introducing `__udivdi3` or 128-bit
compiler helpers. Ten thousand randomized host cases match a `__uint128_t`
oracle. The fail-safe device boot decoded 150 main frames in six seconds, 77
substream frames in three, and 125 post-day frames in five; night/auto/day,
`rvd`, and both ISP cores remained healthy with `error=0`. The validated
module SHA-256 is
`bc1a798d0dac2909657b87f11f65938aa1af849d0a12291bf58fcc3e1e010100`.

The integer/fixed 32-bit and 64-bit log2 family now lives in the math adapter
and delegates to the same normalized-square primitives already used by T23
and T31. Randomized host coverage verifies both integer and fixed wrappers.
Because these entry points are live in gain, color, and filter calculations,
the device gate included image inspection: the accepted red/color and edge
profile remained intact. The cycle decoded 150 main frames in six seconds, 75
substream frames in three, and 125 post-day frames in five, with successful
night/auto/day and zero ISP errors. The validated module SHA-256 is
`c8c94049aaf125798f1496e3b00dcac70f08c63461c5533349b747220b00a6ba`.

The complementary `tisp_math_exp2` entry point now delegates to the common
33-node Q30 lookup/interpolation helper, which rejects invalid precision or
table ranges instead of inheriting masked MIPS shifts. The active tuning paths
use valid Q5/Q16 inputs. The device cycle decoded 150 main frames in six
seconds, 75 substream frames in three, and 125 post-day frames in five;
night/auto/day, `rvd`, image color/detail, and zero-error ISP interrupts all
held. The validated module SHA-256 is
`b55cc521890fe4f37d4b19f67d59113784ed176e40fd7ab11a4e2e95a6044741`.

The live DMSC/SDNS `tisp_ratio` strength blend now comes from the common
three-segment Q7 primitive. All 256 ratio values are host-tested across both
increasing and decreasing output ranges. T41 must keep this entry in its
original recovered text slot: moving the body shifted unresolved indirect
targets and made Raptor stop during `IMP_ISP_AddSensor`. The shared return-body
form preserves the complete accepted `.ko` byte-for-byte. With
`tx_isp_bringup_level=3` retained in the one-shot argument file, the device
again passed night/auto/day, decoded 151 main frames in six seconds and 75
substream frames in three, kept both ISP IRQs advancing with `error=0`, and
showed no driver fault in `dmesg`, `logread`, or `logcat`. The validated hash
therefore remains
`b55cc521890fe4f37d4b19f67d59113784ed176e40fd7ab11a4e2e95a6044741`.

The OEM-derived leading-bit helpers now return their computed positions rather
than zero, and `private_copy_from_user` once again uses the kernel's checked
copy path. This restores a prerequisite for fixed-point tuning math and for the
many ioctl paths that consume userspace structures.

The complete T41 fixed-point log helper family was restored from the local
Ingenic Linux 4.4.94 T41 SDK source. Four helpers now have exact OEM
instruction-count parity and the 64-bit log conversion is within one
instruction of OEM.

The corresponding internal TISP fixed-point log family now returns its
calculated values instead of zero. The 32-bit integer helper is within one
instruction of OEM and both exported conversion wrappers are classified as
similar by the linked audit; the 64-bit integer helper is semantically restored
but remains shorter than OEM and needs runtime coverage during tuning bring-up.

Twelve more vendor shim functions covering I2C, GPIO input, module references,
completion handling, and interruptible timeout waits were restored from that
same SDK source. Each now has OEM instruction-count parity.

The CPM reset helper now polls the OEM `0xb00000c4` register for all 500
iterations and performs both completion writes at that same address. Recovered
pointer types had shortened the poll to 125 iterations and redirected the
completion pulse to `0xb0000310`; the repaired helper is within three
instructions of OEM.

The six fixed-point add/subtract entry points now implement the OEM 32-bit and
64-bit arithmetic instead of returning zero or one input operand. All three
add helpers have exact instruction-count parity; the subtract helpers preserve
OEM unsigned wraparound and underflow diagnostics and are classified as
similar.

The 64-bit rounding, signed minimum/maximum, and three-operand 32-bit multiply
helpers now preserve their full return values. The multiplier and min/max
helpers have exact OEM instruction-count parity. A decompiler-only pair of
`muls_dp_*` calls in AWB distance calculation was also replaced with explicit
64-bit squares, eliminating two symbols that the target kernel cannot resolve.

The ISP-core pad event handler again accepts its data argument and dispatches
events `0x03000001` through `0x03000008` to the seven OEM callback slots (with
the OEM no-op sixth event). Missing callbacks return `-1`; disabled pads and
unknown events remain no-ops.

The media-bus Bayer writer now preserves the upper bits of ISP register
`0x88`, clears its low five bits, and applies the OEM `{1,3,2,0}` Bayer-order
mapping across codes `0x5200` through `0x5213`. Unsupported formats retain the
OEM diagnostic/no-op behavior.

The exports-only (`-1`) hardware smoke level inserts and removes cleanly on the
Wyze Cam v4 target. The first shallow-platform (`0`) run inserted successfully,
created `/dev/tx-isp`, and reached the recovered probe, but exposed word-scaled
decompiler offsets in `tx_isp_remove` during unload. The parent teardown now
uses the OEM byte offsets `0x0c` and `0x88`, preserves the proc pointer at
`0x138`, and guards an absent parent device before deregistration.

A second level-0 run passed that parent teardown but exposed heap corruption
when the kernel later freed module metadata. The recovered child-platform loop
had advanced 32 bytes instead of the OEM 8 bytes and called a math helper in
place of each child driver's remove callback. The repaired loop visits all 16
entries and invokes the callback at driver offset `0x04` before unregistering
each platform device. This repair requires a fresh level-0 hardware retest
before advancing to the device graph.

The next level-0 run reached the restored core remove callback and showed that
it unconditionally deinitialized TISP even though levels below 3 deliberately
skip TISP initialization. Core removal now mirrors that bring-up gate, while
still deinitializing the registered subdevice, and passes the OEM channel-buffer
and core pointers to the two recovered no-argument frees. This repair also
requires a fresh level-0 hardware retest.

The fourth level-0 run completed core teardown and reached CSI removal. It
exposed another scaled pointer (`0x40` instead of the OEM byte offset `0x10`)
and missing iounmap, resource-release, and free arguments. The CSI path and the
same statically visible VIN, IVDC, and frame-source teardown defects are now
restored from OEM disassembly. The VIC path was normalized at the same time.

The fifth level-0 run removed every driver object but detected a kernel bug
while the module's vmalloc area was released. The common subdevice destructor
had discarded its misc, heap, ioremap, and memory-region arguments, and its
clock-release helper became an infinite loop whenever clocks were present.
Those paths and the collapsed module deinitializer are restored from OEM
control flow. The smoke harness now also treats `Kernel bug detected` as a
fatal signature.

The sixth level-0 run is clean: module insertion, `/dev/tx-isp` creation,
parent/child removal, and module unload all return zero with no kernel fatal
signature. This clears the shallow-platform gate for device-graph testing.

The first level-1 run then showed that the graph was incomplete: IVDC probe
rejected zero input/output pad counts and graph creation reported that subdev
index 4 was missing. The common subdevice initializer was only 65 instructions
against the OEM's 420 and skipped IRQ, MMIO, clock, and pad setup. Its restored
implementation is now 306 instructions, the clock initializer is 132 against
OEM 136, and the module initializer is 48 against OEM 51. This lowers the
linked audit's collapsed count from 92 to 91.

Activating the recovered pad setup exposed two additional dormant teardown
chains at level 0. Frame-source probe used the address of its pad-pointer field
as the pad array, freed its live channel array on the success path, and used a
scaled loop index. The repaired probe is 204 instructions against OEM 206.
The VB2 queue cancel/free chain also unlocked a null spinlock and used scaled
list offsets; queue cancel now has exact OEM instruction-count parity and
queue free is within two instructions. Finally, child teardown is bounded by
the six platform entries actually registered instead of walking ten unused
slots. The resulting level-0 run at
`logs/20260720-2015-t41-level0-platform-table-dump-117` inserts and unloads
cleanly with no kernel fatal signature, clearing the updated initializer for a
fresh level-1 graph test.

The fresh level-1 run at
`logs/20260720-2019-t41-level1-restored-graph-117` inserts cleanly and no longer
reports the missing IVDC subdevice. Core, VIC, and IVDC IRQs 39, 38, and 21 are
registered, and `/dev/misc-ivdc` is now present alongside `/dev/tx-isp`.

Static review held level 2 because the recovered private-memory initializer
aliased unrelated IVDC and frame-counter globals and both mutex wrappers used a
null lock. The restored allocator uses the OEM 20-entry block pool, the
reserved ISP base/size, and a real mutex; it includes split and coalescing
paths for later core use. `isp_mem_init` is now 47 instructions against OEM
40, `find_new_buffer` is 32 against OEM 37, and `isp_free_buffer` remains 67
against OEM 70. The level-2 run at
`logs/20260720-2025-t41-level2-private-memory-117` inserts cleanly with no
kernel fatal signature, clearing private-memory setup for level-3 static
review.

Level-3 static review then found that core probe passed the clock-name table as
its subdevice operations and initialized the core spinlock and mutex at
word-scaled offsets beyond the 880-byte allocation. The corrected shallow path
uses `core_subdev_ops` and byte offsets 276 and 280. The level-0 regression at
`logs/20260720-core-offset-fix-level0-117` inserts and unloads cleanly with no
kernel fatal signature. The still-guarded level-3 channel and tuning path
requires separate reconstruction before it is enabled on hardware.

The tuning object on that guarded path also initialized its lock and mutex at
word-scaled offsets, installed two unrelated recovered constants instead of
the tuning file operations and event callback, omitted the ISP debug-node open
callback, and freed no object during deinitialization. Those fields now match
the OEM byte layout and ownership flow. `isp_core_tuning_init` is classified
similar at 53 instructions against OEM 60, while `isp_core_tuning_deinit` has
exact 18-instruction count parity. This repair is compile- and audit-verified;
hardware coverage remains coupled to the pending core-channel restoration.

Core probe now builds its 232-byte channel records and embedded normal/IR
callback tables with OEM byte offsets and named function relocations. It also
restores channel dimensions and capability flags, pad event ownership, the
tuning/debug node hooks, and failure cleanup. The linked probe is classified
similar at 289 instructions against OEM 321. The insertion-only level-3 run at
`logs/20260720-level3-core-channels-117` registers AISP, creates `/dev/isp-m0`,
keeps core/VIC/IVDC IRQs 39/38/21 active, and reports no kernel warning or fatal
signature. Live unload and a sensor/Raptor consumer remain gated on repair of
the shorter recovered TISP deinitializer and review of the stream-init path.

Stream-init review found that several OEM firmware objects had been recovered
as single words even though the code indexes or clears them as structures and
per-channel arrays. The active storage now has the OEM symbol-table extents,
including 504-byte TISP parameters, 2,656-byte scaler state, 78-byte scaler
channel state, 7,744-byte event state, two-entry parameter/day/night tables,
and the corresponding callback, histogram, sensor-control, lock, completion,
and scratch objects. This prevents `tisp_init` from overwriting neighboring
globals before the stream path is enabled. The level-3 regression at
`logs/20260720-level3-tisp-storage-117` again registers cleanly with no warning
or fatal signature.

Hardware smoke tests must use a one-shot boot stage, capture kernel and
userspace logs, and reboot after each experiment. Do not install this baseline
into the persistent module tree or hot-unload an active camera pipeline.

`tools/open_tx_isp_boot_once_init.sh` is the fail-safe init hook used for full
consumer tests. It removes and syncs its armed marker before inserting the
staged module, so a watchdog or power-cycle loads the untouched persistent
module on the next boot.

Use the staged smoke harness after boot-time stock loading has been disabled:

```sh
T41_BRINGUP_LEVEL=-1 tools/t41_smoke_cycle.sh
```

The levels are intentionally incremental: `-1` exports only, `0` performs a
shallow platform probe, `1` adds the device graph, `2` adds ISP memory setup,
and `3` enables the recovered core/tuning path. The legacy harness refuses to
run if any `tx_isp*` module is already loaded and reboots the camera after
every experiment; use the one-shot init hook when the stock boot sequence
cannot safely unload its active module.

## Vendor AE (`t41_vendor_ae=1`, default 0)

`t41_vendor_ae=1` (load time) runs the OEM AE chain per frame instead of the
safe AE controller: `tisp_ae_calc_process` and its 62 callees (weight mean,
flicker detect, BV, tune, EV/list allocation, long/short exposure split, ROI,
sensor IT/gain callbacks, BLC/GIB digital gain, API copy) are translated
mechanically from the H20250310a SDK module by `tools/t41_vae/gen.sh` into
`tx_isp_t41_vae_gen.inc`: one C statement per instruction on 32-bit register
variables, relocations resolved by symbol name to the driver's own objects.
Every load, store, division and indirect call is guarded; a bad address is
counted and skipped (`t41: vendor AE guard ...`) instead of oopsing.

- The AE histogram IRQ (status bit 5) is dispatched with vendor AE as well;
  event 1 is bound to `t41_vae_calc_process`.
- Sensor writes go through the translated `sensor_set_integration_time` /
  `sensor_set_analog_gain` callbacks into the core's pending slots, which the
  frame-done work sends to the sensor (as in the OEM driver).
- OEM AE events (ids 4..6, EV/gain update for the gain-indexed modules) are
  dropped unless enabled in `t41_vae_events`; the driver's own gain fanout,
  TMO exposure feed and the proc/IMP exposure report use the realized vendor
  IT and gain instead.
- `t41_ae_diag=1` logs once a second, `=2` every frame.

Device result 2026-10-18 (gc5603 .32, sc5336 .34): per-frame regulation, IT
raised to its limit before gain, gain reduced before IT, 50 Hz IT lattice
(525-line steps on gc5603), light off -> max gain in 0.36 s, light on ->
mean back near target within ~0.5 s and settled in ~2 s, no guard faults,
no oops.

## Custom AE library (`IMP_ISP_SetAeAlgoFunc`, Lu-Fi/openimp#76)

The stock module serves four ioctls on `/dev/tx-isp` for the user-space AE library that libimp registers in `IMP_ISP_EnableSensor`
(one worker thread): `0xc004541d` open, `0xc004541b` get handle, `0xc004541c` set handle, `0xc004541e` close. Reference: the stock
`tx-isp-t41.ko` (symbols: `tx_isp_set_ae_algo_open`, `tx_isp_get_ae_algo_handle`, `tisp_ae_algo_init/handle/deinit`). They are served by
`t41_ioctl_ae_algo` (`tx_isp_t41_vae.h`), clean C on top of the translated vendor chain (`tx_isp_t41_vae_gen.inc`, roots `tisp_ae_algo_init`,
`tisp_ae_algo_handle`, `tisp_ae_algo_deinit_internal` added to `tools/t41_vae/gen.sh`):

- open: `tisp_ae_algo_init(0, 1, attr)` fills the init attribute (limits from the AE parameters), the module adds the sensor values, allocates the 2002 byte
  info block and re-arms `ae_algo_comp`. Needs `t41_vendor_ae=1` (default) because the library is woken by the statistics event of the vendor AE.
- while a library is registered `vae_ta_custom_en[0] == 1`: the translated `tisp_ae_calc_process` still runs the statistics step (`tisp_ae_algorithm`),
  skips its own EV allocation and completes `ae_algo_comp` (that wakes the get-handle ioctl, about one call per frame).
- get handle: statistics (the tuning AE statistics block, 1934 bytes) + the exposure words + the sensor attribute words; the exposure is the library's last
  answer (AE state +8608..), before the first answer the exposure the sensor driver started with (the internal AE never ran).
- set handle: `tisp_ae_algo_handle(0, answer)` (translated): the integration time / analog gain / ISP digital gain go through the translated sensor
  callbacks into the pending slots the frame-done work sends to the sensor, exactly like the internal AE. The realized exposure of the proc file
  and the IMP getters is the library's answer while it controls the AE.
- close: `tisp_ae_algo_deinit` + `tisp_ae_algo_init(0, 0, 0)` + free the info block; the internal AE takes over again.

The stock module has ONE channel and no AWB library path: the second-sensor handle `0xc0045420` is not in the stock dispatcher and answers `-ENOTTY` here as
well; the AWB ioctls `0xc0045423..26` are not in it either, this module serves them as an extra (next section).
Differences to stock (hardening): the info block is cleared after close (a second close freed it twice), a get handle without open or after close
answers `-EINVAL` (stock dereferences NULL), an interrupted wait returns the error, channel numbers above 0 are refused. Source guard:
`tests/check_t41_custom_ae.sh`; QEMU (debug kernel with `slub_debug`) and camera evidence in Lu-Fi/openimp#76.

Extra beyond the vendor (Lu-Fi/openimp#197): the file that registered the AE library is remembered and `tx_isp_release` unregisters it (`t41_ae_algo_release`: the
same steps as the close). Stock leaves the library registered when its client is killed and every later open answers `-EBUSY` until the module is reloaded.
The protocol block of `tx_isp_t41_vae.h` (between `T41-AE-ALGO-PROTOCOL-BEGIN/END`) follows the AWB library: one mutex, a get without a registered library answers
`-EINVAL` at once (stock waits on a never initialised completion: an oops on the unmodified module), the unregister wakes every waiter (`complete_all`),
frees the info block once and clears the pointer (close plus release free nothing twice), the completion is initialised once, a failed copy of the open reply
unregisters again. Without a registered library nothing changes. Tests: `tests/t41_ae_algo_host.sh` (15 mutations), device client `tests/t41_algo/aerace.c`.

## Custom AWB library (`IMP_ISP_SetAwbAlgoFunc`, extra beyond the vendor, Lu-Fi/openimp#195)

The stock module has no AWB library path; this module serves the user-space protocol libimp and the T40 module use (`tx_isp_t41_awb_algo.h`):
`0xc0045425` open (reply: the 20 byte init attribute, the zone grid of the native AWB), `0xc0045423` get (waits for the next AWB frame, returns the
2732 byte block `{cookie, channel, IMPISPAwbInfo}`: current gains = the gains in the WB registers, global statistics, 2700 byte zone statistics),
`0xc0045424` result `{cookie, channel, change, r, b, ct}`, `0xc0045426` close. One channel (`0xc0045420`, the second-sensor handle, stays ENOTTY).
The wake-up is the end of the native AWB frame work (`t41_awb_algo_wake`); the library needs `t41_native_awb=1` (default). A result with `change == 1`
and both gains in 0x200..0x1800 (hardware unit, 1024 = 1.0, the range of `IMP_ISP_Tuning_SetWB`) switches to manual hardware gains
(`t41_native_awb_compat`, frozen), the colour temperature is ignored; close, a crashed client (file release) and a late close give the application's
state back. Locking, error codes and the differences to the stock AE path: see the header comment and `tests/t41_awb_algo_host.sh`.

## ioctl stack-overflow hardening and device test plan

The recovered `tx_isp_unlocked_ioctl`, `frame_channel_unlocked_ioctl` and the
isp-m0 `isp_core_tunning_unlocked_ioctl` dispatchers reached decompiler-emitted
tails that copied 8..80 bytes from userspace into 4-byte scalar locals
(`&local_20`, `&local_70`, `&local_10`) with hard-coded lengths, overflowing
the kernel stack for any command the typed handlers above did not already
serve. The full libimp/OpenIMP command surface (the `TISP_VIDIOC_*` set on
`/dev/tx-isp`, the eleven T41 frame ioctls `0xc0745451..0xc008545b`, and the
tuning envelopes `0xc0105435`/`0xc0085433`/`0xc0085434`) is handled by those
typed, bounds-checked paths; each dispatcher now refuses anything else with
`-ENOTTY` (logging `cmd`/`_IOC_SIZE` once) instead of running the overflowing
recovered tail. The vendor ABI (command numbers and struct layouts) is
unchanged. T21 (`int32_t buf[0x14]`), T23 (stub) and T31 (`sizeof()`-bounded
typed locals) do not carry this pattern.

When the camera leaves soak, extend the on-device check with ioctl fuzz-style
cases (no oops, correct errno) against `/dev/tx-isp`, each `/dev/isp-fsN` frame
node, and `/dev/isp-m0`:

- Every supported command with `_IOC_SIZE` mismatched (too small and too large)
  and with a NULL / unmapped / short user buffer must return `-EFAULT` or
  `-EINVAL`, never corrupt state.
- A sweep of unsupported/legacy command numbers (e.g. `0x80045413`,
  `0xc004541c`, the legacy frame `0xc07056c3` group, and random
  `_IOC` encodings) must return `-ENOTTY` with no log flood and no crash.
- Repeat each case a few thousand times during live capture and confirm the
  stream, encoder and `dmesg` stay clean (watch for the one-shot
  "recovered dispatch disabled" warning only).

## Output restart hang (MSCA output restart with live input)

Symptom (Vanhua T55A / gc5603, streamer idle-stop): one output stopped while
the other kept streaming (or both idle-stopped, input still running), then
started again: the SoC hard-hangs within a few frames of the restart. Both
CPUs stop, no oops or panic, the busybox watchdog resets ~60 s later.
Repro: ch0 client 2 s, pause 1.8 s, ch1 client 2 s, pause ~4 s, repeat -
hang within 1-6 cycles; a 30-60 min two-client mix hung in 10-15 min.

Evidence: a diagnostic build wrote step markers, a per-CPU register history
and IRQ/lock state uncached into the last page of rmem; after the watchdog
reset the tripped boot guard kept timps (which clears rmem) from starting,
so the markers were read back with `devmem`. Every hang came right after an
output was enabled/reprogrammed by `tisp_msca_chx_cfg_load()` while the
input ran; no CPU was inside the ISR or waiting on a lock. Most hangs were
bracketed by `0xf0010 = 1` (MSCA register update request) from
`tisp_msca_set_mirr_flip()` with unchanged flip bits (frame-channel SET_FMT
before the enable, the streamer's HVFLIP after it).

What the driver does now (each step was bisected on the device):
- `tisp_msca_set_mirr_flip()` requests the MSCA update only when the flip
  bits change (`t41_msca_flip_skip_noop=1`). This alone took the targeted
  repro from 1-6 cycles to 0 hangs in 90+ cycles (also with hflip=1), but
  the client-mix soak still hung after 10-15 min.
- STREAMOFF leaves the MSCA output enabled, as stock
  `tisp_channel_main_stop()`/`tisp_msca_chx_cfg_load()` do (enable bits are
  only ORed in); the address FIFO is cleared at REQBUFS 0 as before. A
  restart with unchanged geometry does not touch the output's MSCA registers
  (`t41_msca_stop_disable=0`; 1 restores clear-and-reprogram).
- QBUF no longer writes the FIFO control words back with bit 31
  (`t41_msca_fifo_ctrl_after_live_qbuf` now defaults to off). Stock writes
  only the Y/UV address registers; both outputs still run at 25 fps.

Experiments that did not help on their own: loading the staged MSCA
configuration (0xf0010 handshake) before the enable, delaying the
post-enable update request by a few frames, keeping the output enabled
without skipping the redundant update requests.

Residual risk: a real HVFLIP change still issues an update request; done
within a frame of an output start it may hit the same hazard.

Update 2026-10-06: the MSCA geometry, ratio, global input and flip words are
staged registers (written value applies at the next input frame after
`0xf0010 = 1`, reads return the active value; see
`tx_isp_t41_msca_shadow.h`). With the no-op flip requests skipped, the
outputs never latched their geometry and ran with the reset defaults
(1920x1080 / 1280x720, ratio 1:1, input 1920x1080), probably why the repro
above stopped hanging. `t41_msca_cfg_update=1` latches the programmed
geometry (correct pictures), and then the targeted repro hangs again after
4-13 cycles, also without any register write during the cycles (restarts
with unchanged geometry are not reprogrammed). The hang is therefore tied to
an output being idle-stopped and restarted while the MSCA really scales the
full 2880x1620 input, not to the update requests themselves. Default stays 0
until that is solved (superseded below).

Update 2026-10-10: `t41_msca_cfg_update=2` (opt-in, together with
`t41_msca_stop_disable=1`) requests the update with the output OFF and
enables it once the read-back shows the new words, as stock does (STREAMOFF
switches the output off; a restart with unchanged words requests nothing).
Defaults stay `cfg_update=0`, `stop_disable=0` (flashed behaviour) until the
960x540/1280x720 hang below is solved.
Targeted repro (ch0 2 s, ch1 after 1.8/2.5/4.0 s, `general.fs_keepalive =
off`), ch1 sizes: 320x180, 640x360 (2x), 704x400 21/21 cycles each, 768x432
9/9, pictures match ch0, no band on either buffer; `cfg_update=1` at 640x360
hung in cycle 2. Still open: ch1 960x540 and 1280x720 hang at the first
start while the input runs (960x540: 3/3 runs; also with a 120 ms wait after
the latch and with the ch1 latch skipped), while the flashed build that
never latches ran 960x540 21/21 (wrong picture). Separately, `rmmod
tx_isp_t41` sometimes oopses in `module_param_sysfs_remove()` (the param
attribute array holds the value 2), also with the flashed build loaded at
boot: a heap overwrite somewhere in the driver, maybe the same fault as the
hang. Static review (branch `claude/t41-heap-review`): the AE, AF, WDR and
TMO statistics engines DMA into `kmalloc`'d buffers (`tisp_ae_malloc_cfg`
0x1904c, `tisp_af_malloc_cfg` 0x1a0dc, `tisp_wdr_init` 0x6030,
`tisp_tmo_init` 0x1e020) and their deinit freed the buffer without switching
the engine off (only `tisp_awb_deinit` clears 0x1804c), so the ISP kept
writing statistics into freed pages every frame; `tisp_deinit()` now
disables all five engines and waits one frame before freeing. (2026-10-30: the
AE/AWB +0x4c writes were dropped again, as in the OEM 1.2.5/1.2.6: that
word is the buffer setup, 0 = one buffer, not off; the ISP clock gate and
reset in the core close path stop the DMA.) Untested on
the device at the time of writing. At 1280x720 the encoder also fails an order-9 DMA allocation (`avpu:
Can't alloc DMA buffer`, ch1 RTSP 503) when ch0 started first.

Update 2026-10-13 (branch `claude/t41-ch1`, host analysis only): the
open `tisp_msca_chx_cfg_load()` path matches stock 1.2.6 in order
(para_calc, curve_calc, shadow-RAM curve, scaling_algorithm,
init_chx_cfg, strides 0xf0180/0xf0198 + ch * 0x100, enable OR), the ch1
coefficient RAM write (0xf1100/0xf1104, 33 phases x 8 taps) uses the
stock indices, and the generated ch1 curves for 2880 -> 640..1920 are
sane (every phase sums to 2048, taps -118..1372). Stock has no size or
ratio branch around 768/960. The ch1 frame buffers come from one rmem
block (OpenIMP `VBMCreatePool` -> `DMA_AllocDescriptor`), not from the
kernel heap, and no driver allocation scales with the output size, so a
512 KiB / page-order limit is ruled out on the ISP side (the order-9
failure above is in the encoder driver). Cause still unknown. Until it is
found, SET_FMT refuses ch1 larger than `t41_msca_ch1_max_w` x
`t41_msca_ch1_max_h` (768x432) with `-EINVAL` when
`t41_msca_cfg_update >= 2` (counter `msca_fmt_refused`).
Next device step: ch1 800x450 / 832x468 / 896x504 / 960x540 (limit set to
0), ch1 started before and after ch0, recording `msca_latch_timeouts` and
the "latch not seen" lines, to tell a width, ratio or size limit apart.

Device run 2026-10-13 (T41 .32, agg-38 kernel, this branch's module loaded
at runtime, `t41_msca_cfg_update=2 t41_msca_stop_disable=1`, a libimp
test tool without encoder: ch0 1920x1080 scaled from 2880x1620, ch1
started 4 s after ch0 or before it; numbers only):
- default `cfg_update=0`: ch1 640x360 broken as described above (SSIM
  against downscaled ch0 about 0.6, chroma near zero, `csc_latch_skipped`
  counts up).
- `cfg_update=2`: ch1 640x360, 768x432, 800x450, 832x468, 896x504,
  960x540 and 1280x720 all correct (SSIM 0.993-0.996 full frame and top
  1/8, so no band; ch1 Y and R/G, B/G within 1 % of ch0); 800..960 also
  with ch1 started first; 960x540 stopped and restarted 10 times with ch0
  running; no hang, no oops, no "latch not seen" during the ch1 starts
  (one timeout at the very first ch0 start), `csc_latches` counts up.
- the SET_FMT gate refused 960x540 with -EINVAL (`msca_fmt_refused` 1).
So the 960x540/1280x720 hang does not reproduce with the frame source
alone; it needs the full streamer path (encoder running, client-driven
start), which was not run here.

Streamer run 2026-10-13 (same camera and module, timps with a /tmp copy
of its configuration, `general.fs_keepalive = 1`, gate off; local
snapshot status codes, logs and counters only):
- ch1 960x540: 30 min, every minute both snapshots 200, no oops, no
  "latch not seen", no encoder errors in the log; then 10 timps
  stop/start cycles, each start latched and served both snapshots.
- ch1 1280x720: 10 min the same, then 5 timps stop/start cycles, clean.
- defaults candidate (`cfg_update=2`, `stop_disable=1`, gate 1280x720,
  loaded with the boot parameters only, unchanged timps configuration,
  ch1 640x360): 98 alternating ch0/ch1 snapshot rounds in 10 min, all
  200, clean. timps kept both channels running during these rounds, so
  the client-driven idle-stop/restart of the old repro was not exercised
  (no RTSP client was used); the restarts were covered by the timps
  stop/start cycles above.
Defaults since then: `t41_msca_cfg_update=2`, `t41_msca_stop_disable=1`,
ch1 SET_FMT gate 1280x720 (`t41_msca_ch1_max_w/h`); the old behaviour is
`t41_msca_cfg_update=0 t41_msca_stop_disable=0`.


Update 2026-10-19 (cause found, branch `claude/t41-restart-reload`): an
uncached flight recorder at the nmem end (`t41_fr_phys=0x7ff7000`) caught
the hang twice: output stop, then REQBUFS 0 cleared the output's MSCA address
FIFO (`tisp_channel_main_fifo_clear`, error IRQ 0x20 right after), and the
next output enable with the input running froze the SoC within 3 jiffies.
The 2024 Cinnado stock module never clears that FIFO.
`t41_msca_freebufs_fifo_clear=0` (new default) skips it: ch0 1920x1080 +
ch1 1280x720 AutoZoom restart (zr0+zr1) 10/10 and 3/3 cycles, ch1 1600x900
and 1920x1080 5/5 each, 60/60 frames per channel and cycle, ch1 picture
matches ch0, then timps 10 min clean; with the clear the same test hung 3/3
(twice at the first ch0+ch1 start). The ch1 SET_FMT gate is now 1920x1080.

## MSCA zoom, mask and scaler level (branch `claude/t41-zoom-mask`)

Host- and build-tested only; not run on a camera yet (test plan below).
Reference: `tisp_s/g_autozoom_control`, `tisp_msca_crop_api`,
`tisp_s/g_mscaler_mask_block_attr`, `tisp_msca_set_mask`,
`tisp_msca_cfg_shd_ram` and `tisp_set_scaler_level_control_set` of
`libt41-firmware-1.2.6`, and `IMP_ISP_Tuning_Set/GetAutoZoom`,
`Set/GetMaskBlock`, `SetScalerLv` of the vendor libimp 1.2.6. Pure helpers
in `tx_isp_t41_msca_ctl.h`, host test `tests/tx_isp_t41_msca_ctl_test.c`.

Stock does all three live: AutoZoom reprograms all three MSCA outputs
(`para_calc`, `curve_calc`, `init_chx_cfg`) and requests the MSCA update
(`0xf0010 = 1`) while they run, ScalerLv writes `0xf0708 + ch * 8` /
`0xf0028` and requests `0xf0010 = 0xffffffff`, MaskBlock marks the block
dirty for the per-frame shadow-RAM writer. On this driver an update request
that reaches a running output can hang the SoC (sections above), so:

| state of the output (per output, `msca` descriptor byte 0) | what happens |
|---|---|
| not streaming | request stored; programmed at the output's next start |
| streaming, `t41_msca_cfg_update=2` and `t41_msca_stop_disable=1` and output <= `t41_msca_live_max_w` x `t41_msca_live_max_h` (768x432) | applied now (LIVE) |
| streaming, anything else (default: `cfg_update=0`) | request stored, applied at the output's next start (DEFER, KERN_INFO line, `msca_ctl_deferred`++) |

LIVE for AutoZoom and ScalerLv = `tisp_msca_chx_cfg_load()` with the
latch-while-off sequence of `cfg_update=2` (output off, staged words
written, `0xf0010 = 1`, output on once the read-back shows the words, up
to `t41_msca_latch_timeout_ms`), so the output loses one or two frames.
Only outputs whose descriptor changed are reloaded (stock reloads all
three). If the reload fails (busy shadow port) the output is switched back
on with its old geometry, `msca_ctl_failed`++, and the request applies at
the next start. LIVE for MaskBlock = the dirty blocks of that output go
through the shadow port at once (no `0xf0010` request), up to 3 tries.
The ioctl returns 0 in all three cases, as stock. Counters (read-only
module parameters): `msca_ctl_live`, `msca_ctl_deferred`, `msca_ctl_failed`.
Note that with `cfg_update=0` no MSCA geometry ever latches (section
above), so AutoZoom has no visible effect in that mode, like every other
geometry change; with `cfg_update=1` it applies at the output's next start.

AutoZoom (0x08000077, 60 bytes `IMPISPAutoZoom`: s32 en[3], left[3],
top[3], width[3], height[3], sensor coordinates; libimp passes it 1:1):
- per output, `en == 1`: descriptor (26-byte stride) +8 = 1 (lock: the
  FrameSource crop no longer overrides it), +10/+12 = left/top (register
  `0xf00a0 + ch * 8`, masked `0x0fff1fff` as stock), +14/+16 = width/height
  (source of the scaling ratio); any other `en`: window = whole sensor
  (0, 0, sensor w, sensor h) and the lock byte is left as it was (stock;
  a FrameSource crop set later is then still ignored until the lock is
  dropped by a restart, which is stock behaviour).
- beyond stock: the whole request is refused with -EINVAL (nothing stored)
  if an enabled window is empty, negative, outside the sensor picture,
  has left > 4095 / top > 8191, or the sensor size is still unknown.
- GET fills left/top/width/height of all outputs; the en words are
  returned as the caller passed them (stock returns its stack buffer).
- the window is re-imposed after the late-start SET_FMT rebuild of the
  first output start (it used to overwrite +10..+16).
- the input crop position is now a 7th start word (`0xf00a0 + ch * 8`):
  a pure pan with unchanged size latches like a size change (whether that
  register is staged is not measured; if it is immediate the compare is a
  no-op).

MaskBlock (0x08000074, 24 bytes `IMPISPMaskBlockAttr`: u8 chx, pinum, en,
pad, u16 top, left, width, height, s32 type, u8 r,g,b, u8 y,u,v): libimp
converts an enabled RGB block to YUV in place (BT.601 full); the kernel uses
only window and y,u,v.
- SET: `en == 1` stores window and colour, other values only disable the
  block (window and colour keep their values); the block is marked dirty.
  chx >= 3 or pinum >= 4 -> -EINVAL (stock does not check and writes past
  its table).
- written as stock `tisp_msca_set_mask` does, bracketed like
  `tisp_msca_cfg_shd_ram` (`0xf8000 = 0x101`, pairs on `0xf8004`,
  `0xf8000 = 0x01010102`, `0xf8100 = (pairs - 1) << 4 | 1`): per dirty
  block `left << 16 | top -> 0xf0138 + ch * 0x100 + pinum * 12`,
  `y << 16 | u << 8 | v -> +8`, `en ? width << 16 | height : 0 -> +4`, then
  the output's "any block on" bit ORed into `0xf0014` (stock never clears
  that bit). Stored blocks of an output go out from
  `tisp_channel_main_start()`, which also rewrites the output's enabled
  blocks (an ISP reset at stream start may have cleared them; stock writes
  only on change).
- GET: window and y,u,v of an enabled block, zeros for a disabled one,
  `en` always 0 (stock); type and r,g,b come from the libimp cache.

ScalerLv (0x080000a6, 12 bytes `IMPISPScalerLvAttr`: u8 chx, s32 mode, u8
level; SET only, GET -> -EOPNOTSUPP as there is no stock handler):
- chx >= 3 -> -EINVAL (stock -1); mode 1 (FIXED_WEIGHT): the output's two
  mode bytes (`params + 0xdf + ch * 2`, `+ 0xe0 + ch * 2`) = 1 (bits of
  `0xf0028`), stored level dropped; mode 0 (FITTING_CURVE): level > 128 ->
  -EINVAL, mode bytes = 0, level into the low 16 bits of `0xf0708 + ch * 8`
  (`level << 8 | level`, bits 16..24 and 28..31 kept); other modes: no
  change, 0.
- beyond stock: the level is kept and put back at every reload of the
  output (stock writes only the register, so its next channel load drops
  it); this is what "applied at the next start" means for ScalerLv.

### Device test plan (T41, not run yet)

Preconditions: camera on this branch's module and an OpenIMP built from
`claude/t41-zoom-mask`, nothing else streaming, serial console attached,
watchdog on (a hang shows as a reset after ~60 s). Record `dmesg` and
`/sys/module/tx_isp_t41/parameters/{msca_ctl_live,msca_ctl_deferred,
msca_ctl_failed,msca_latch_timeouts,msca_live_disables}` after every step.
Daylight scene with straight edges for the zoom/mask pictures; no people;
pictures stay local.

Abort at once (and note the step) on: SoC hang / watchdog reset, any oops,
`MSCA channel %u still active`, `latch not seen`, `msca_ctl_failed` > 0,
VPU/encoder errors, a stream that stops delivering frames for > 2 s, a
green/garbage band in either buffer. After an abort reboot before the next
step and do not continue with larger sizes.

1. Default modes (`t41_msca_cfg_update=0`, `stop_disable=0`), ch0
   1920x1080, ch1 640x360 streaming. SetAutoZoom ch0 window
   (480, 270, 1920, 1080), ch1 (0, 0, 2880, 1620); expect 0,
   `msca_ctl_deferred` += 2, no register change (`t41_msca_regs` identical
   before/after), both streams unaffected. GetAutoZoom returns the windows.
   Invalid window (left = 2000, width = 1000 on a 2880 sensor) -> -1 from
   libimp (-EINVAL), nothing stored.
2. Same with `t41_msca_cfg_update=1`: stop and restart ch0 (prudynt
   restart); ch0 now shows the zoomed centre. Snapshot before/after
   (collage). Then en = 0: full picture after the next restart.
3. `t41_msca_cfg_update=2`, `t41_msca_stop_disable=1` (reload module),
   ch0 1920x1080 + ch1 640x360 streaming. AutoZoom on ch1 only, windows
   (0,0,2880,1620) -> (720,405,1440,810) -> (1440,810,1440,810): each call
   `msca_ctl_live`++, ch1 drops <= 2 frames, picture shows the window,
   ch0 untouched. 20 calls at 1 s spacing, then 100 calls at 200 ms.
   Same with ch1 768x432. ch0 change while streaming must be DEFER
   (1920x1080 > envelope): `msca_ctl_deferred`++, applied at ch0 restart.
4. Envelope edge: ch1 960x540 streaming, AutoZoom ch1 -> DEFER, no
   reprogram; restart ch1 only while ch0 stays stopped (the 960x540 start
   that is known safe: input stopped). Do NOT raise
   `t41_msca_live_max_w/h` in this run.
5. MaskBlock: ch0 block 0 YUV (16,128,128) at (100,100,200,100), ch1
   block 1 RGB red at (50,50,100,60). Default modes: DEFER on both,
   masks appear after the next start of each output. Mode 3 setup with
   ch1 640x360: ch1 mask appears within one frame, `msca_ctl_live`++.
   Disable (en = 0): mask gone. GetMaskBlock: window + yuv, en 0, type and
   rgb from the library. chx = 3 -> -1.
6. ScalerLv ch1: mode 0 level 0, 64, 128 (snapshots, sharpness visible),
   level 129 -> -1, mode 1, mode 2 (no change, 0). Mode-3 setup: LIVE,
   one-frame blip; default modes: applies at the next ch1 start and stays
   after further restarts.
7. Mixed soak 30 min (mode-3 setup, ch1 640x360): prudynt idle-stop
   cycles plus one AutoZoom/MaskBlock/ScalerLv call every 10 s from a
   script. Pass: no reset, `msca_ctl_failed` = 0, `msca_latch_timeouts`
   unchanged, both streams 25 fps at the end.

### Device results 2026-10-24 (Cinnado .34, sc5336, ch0 1920x1080 + ch1 640x360, FixQP)

- `t41_msca_ch1_max_w/h` is 1920x1080 in the shipped image (not 1280x720).
- Live envelope ladder (envelope raised at runtime via sysfs, `t41_msca_cfg_update=2`,
  `stop_disable=1`, no hang, 0 failures, no frame gap above 70 ms): ch1 960x540 21 live
  AutoZoom calls; ch1 1280x720 20 calls (+ base); ch0 1920x1080 from the
  2880x1620 sensor, 18 live calls (window 480,270 1920x1080 / full / 960,540),
  ch0 SSIM against a crop of the full picture 0.91 (0.42 for a wrong window).
  Default `t41_msca_live_max_w/h` is therefore 1920x1080 (was 768x432).
- ScalerLv on ch1 is LIVE (`msca_ctl_live` +1 per call, 0 failures, no frame
  gap above 75 ms). Fitting curve, level 0 against level 128, three
  alternations: no measurable difference in the decoded ch1 picture
  (Laplacian energy within the noise of 1 %) at 2880 -> 640 (4.5:1);
  `0xf0710` reads `0x80008080` at level 128. FIXED_WEIGHT (mode 1) against
  fitting curve level 128: reproducibly softer, Laplacian energy -12 %
  (143/138 -> 125/122 in two alternations). Mode 2: no change, ret 0.
  ret -1 for level 129.

## ISP OSD (branch `claude/t41-isp-osd`, 2026-10-26)

The ISP draws up to 8 ARGB pictures into MSCA output 0 (the main stream, and
everything taken from it: H.264/H.265, JPEG, NV12 frames). Controls (libimp
`IMP_ISP_Tuning_Set/GetOSDAttr`, `Set/GetOSDBlock`, sent by the region API
`IMP_ISP_Tuning_*OsdRgn` / `IMP_OSD_*_ISP` on every Show):

- `0x080000a1` OSD attribute, 12 bytes: osd_type (0 ARGB8888, 1 ARGB1555),
  osd_argb_type (component order), osd_pixel_alpha_disable.
- `0x080000a2` OSD block, 20 bytes: pinum 0..7, enable, left, top, width,
  height, physical picture address, stride in bytes.

Clean C in `tx_isp_t41_osd.h` (state, request decoding, register image; host
test `tests/tx_isp_t41_osd_test.c`), rebuilt from the behaviour of the stock
`tisp_s/g_osd_attr`, `tisp_s/g_osd_block_attr` and `tisp_msca_set_osd`
(1.2.6). The ioctl stores the request; the next frame's MSCA shadow commit
(`t41_msca_commit_frame_shadow`, the per-frame transaction stock does in
`tisp_msca_cfg_shd_ram`) writes the dirty pictures as value/register pairs
through 0xf8004:

| register | value |
|---|---|
| 0xf0064 | component order |
| 0xf0600 + 16n / +4 / +8 / +12 | left << 16 \| top, width << 16 \| height, address, stride |
| 0xf0018 | enable bit per picture |
| 0xf0060 | osd_type \| 0x70 \| alpha_disable << 8 |

then `0xf8100 = ((pairs - 1) << 4) | 1`. A picture must fit the output-0 crop
size (stock msca +22/+24). Output start of channel 0 marks the shown pictures
dirty again (an ISP reset may have cleared them). Read-only counter:
`osd_commits`. T40 has the same register block at 0x16000 (stock
`Tzn_Msca_Shd_osd`), programmed per output channel with one combined control.

Differences to stock: pinum >= 8 refused; a picture outside the limits
returns -ERANGE (stock: 0, nothing stored); stock first checks the stored
(old) size; the enable word follows the pictures (stock only ORs bits in, so a
hidden picture kept its enable bit); GetOSDBlock reports the requested block
(stock clears the request before it reads pinum and always reports block 0).

Device results 2026-10-26 (.34 sc5336 and .32 gc5603, ch0 1920x1080, ch1
640x360, the usual streamer call sequence, `tests/t41/devtest/isp_osd_devtest.c` in
OpenIMP): the pictures appear at the requested place in ch0 NV12 and ch0 JPEG
with exact colours (red 251,0,0 / green 0,252,0 / blue 0,0,251 / yellow
252,253,0 in NV12; 50 % alpha blends), move/update, a second region, hide and
destroy work (background restored to within 1-2 levels), fps unchanged (ch1
30.1-30.6 on .34, 25.2-25.6 on .32), 0 oops; the stock module was restored
after each run. Not drawn into ch1 (the scaled output): the hardware OSD
belongs to output 0 (vendor: "ISPOSD supports one channel"). Component
order: the hardware takes the order from the most significant byte of the
little-endian word, so a bitmap with the bytes B,G,R,A in memory needs
`IMP_ISP_ARGB_TYPE_ARGB` (0); with `BGRA` (13) byte 0
(blue) is the alpha and only blue/white parts are visible. The registers are
the stock ones, so the vendor stack should show the same (not compared on the
vendor stack).

## Issue 171 controls (branch `claude/t41-isp-routes`, 2026-10-31)

Tuning controls (ioctl 0xc0105435) that the T41 libimp 1.2.5/1.2.6 sends
and the open module answered with EPERM before. Each follows the OEM
`tx-isp-t41.ko` of SDK 1.2.5 (`tx_isp_core_ops_s/g_ctrl`, Ghidra + objdump):

| control | call | OEM path | open |
|---|---|---|---|
| `0x08000036` 12 B get/set | Get/SetFaceAeWeiget | tisp_ae_api_set/get_face_ae_tune_params, ae_cache +0x5f8/+0x5fc/+0x600 | same fields of the vendor AE cache |
| `0x08000037` 8 B get | GetFaceAeLuma | tisp_ae_api_get_gobal_roi_luma, ae_cache +0x5f0/+0x5f4 | same (vendor AE writes them per frame) |
| `0x0800003a` 4 B get | GetAEFlickerFlag | tisp_ae_api_get_flicker_flag, ae_cache +0x67c | same |
| `0x080000b3` 4 B get | GetAeBv (libimp 1.2.6) | no handler in the 1.2.5 module | AE state +0x2614, the BV tisp_ae_get_bv stores per frame (inferred) |
| `0x08000097` 12 B get/set | Get/SetCsccrMode | tisp_csccr_api_set/get and the 3 presets | `tx_isp_t41_isp_extra.h` t41_csccr_plan, 0xf08e0..0xf08ec, 0xf0010 |
| `0x080000a0` 32 B get/set | Get/SetDrawBlock (and IMP_OSD_*RgnAttr_ISP line/rect) | tisp_s/g_draw_block_attr, drawn by tisp_msca_set_line | `t41_draw_set/get/emit`, drawn by the per-frame MSCA shadow commit after the OSD pictures |

The AE values need the vendor AE (`t41_vendor_ae`, default on): -EOPNOTSUPP
without it, -EAGAIN before its first frame. CSCCR GET returns the last
custom record (stock: the presets leave it unchanged). Draw units: 20 units,
registers 0xf0400 + 16n (position, size, colour | width << 24, control);
type 2 is a line between two points, sloped lines only on units 0..7 (stock).
Read-only counter `draw_commits`. Host test `tests/tx_isp_t41_isp_extra_test.c`.

Differences to stock: draw unit >= 20 refused (stock writes past its
table); GetDrawBlock takes the unit from the request (stock reads it from an
uninitialised stack buffer) and returns the YUV colour in its three bytes
(stock writes v over u); a custom CSCCR range with an empty input range is
refused (stock divides by zero); the AE reads check the AE is running.

### Issues 180 and 181 (branch `claude/t41-isp-routes2`, 2026-11-01)

| control | call | OEM path | open |
|---|---|---|---|
| `0x08000062` 56 B set | SetTmoFaceae | tisp_s_tmo_faceae -> tisp_tmo_faceae_refresh: request into the TMO runtime block (+0x00..0x2f, +0x2f8..0x2fe), registers 0x1e040..0x1e07c | same; the register words are written again from that block by `tisp_tmo_default_reg_refresh` on each EV/gain change, so the weighting stays. Under the TMO map lock, -EAGAIN until the TMO object exists. Helpers + host test in `tx_isp_t41_isp_extra.h` |
| `0xc0045430` 24 B get | GetInternalChnAttr | tx_isp_get_internal_channel_attr: scan core+0x234+0x1c*n for the descriptor each frame channel points at | same; the flag of types < 4 is 0 (uninitialised on stock) |
| `0xc004542f` 24 B set | SetInternalChnAttr | duplicate check, core events 0x01000004/05: repoints channel+0xd4 for types > 2, VIC internal input for types >= 4 | types 0..2 (no effect on stock either) are accepted, duplicates and types >= 6 give -EINVAL (stock: -EFAULT / uninitialised entry), types 3..5 give -EOPNOTSUPP: they need the VIC internal inputs that the open VIC frame-channel path does not provide (same limit as the ISP bypass) |

Device proof (T41 sc5336, flashed image, runtime register readback with a
diagnostic ko): SetTmoFaceae writes 0x1e040..0x1e07c and reads them back equal
(e.g. 0x1e064 = 0x10, 0x1e070 = 0x80, 0x1e07c = 1 for one region), zero region
restores all sixteen to 0; no visible brightness change with the apitest
request (the TMO weighting acts on face regions only). Set round trip of
SetInternalChnAttr runs only with `APITEST_RISKY=1` (QEMU: PASS).

AF statistics (issue 179): GetAfStatistics `0x08000031` (6 x u32[15][15],
5400 bytes) and GetAFMetricesInfo `0x08000034` ({u32 metric, u32 metric_alt,
u8 frame tag}, 12 bytes) are served from the re-translated OEM AF path, but
only when the module is loaded with `t41_af=1`. Default `t41_af=0`: the block
stays off as before (`tisp_af_init` writes 0x1a000 = 0, interrupt bit 6
masked) and both calls answer EPERM. With `t41_af=1`, `tisp_af_init` checks the
zone grid of the AF parameter block (tparamsP+0x17be8: 1..15 zones each way,
at least 2 pixels per zone), writes the OEM `tisp_af_set_hardware_param`
sequence (0x1a004..0x1a034 zone grid once, 0x1a000 = 1, 0x1a038..0x1a0c8),
unmasks status bit 6 (0x40020) and arms the handler. Per AF-done interrupt the
finished 4 KB ring buffer (index 0x1a0e0, masked to 0..3) is unpacked into the
workspace (OEM `tisp_af_get_statistics`, 136-bit zones, row length from the
OEM CSWTCH.12 table), the frame tag 0x1a120 stored, the buffer cleared and
written back; `tisp_af_alogrithm` (weighted IIR/FIR blend, metric history)
runs on the ordered tuning workqueue. `tisp_deinit` / `tisp_af_deinit`
disarm (bit 6 masked, 0x1a000 = 0, work cancelled) before anything is freed.
All arithmetic is in `tx_isp_t41_af.h`; `tests/tx_isp_t41_af_test.c`
compares it with a literal transcription of the Ghidra decompile of the 1.2.5
module (registers, workspace and parameter bytes, 20000 random cases);
`tests/check_t41_af_gate.sh` guards the default-off gate. Read-only
counters: `af_live`, `af_irqs`, `af_runs`, `af_bad_index`.
ISP-device ioctls (all follow the 1.2.5 `tx_isp_unlocked_ioctl`,
`tx_isp_t41_devioctl.h`, host test `tx_isp_t41_devioctl_test`):

- StartNightMode 0xc004542e: 4-byte vinum, stores 10 at core + 0x1d4 + 4 *
  vinum (stock: unchecked, here vinum 0..2). The word is the VIC frame
  counter that the next first `/dev/isp-m0` tuning open consumes (value 10
  sets tuning + 0x18 = 1 and clears it); it has no other effect.
- WDR_OPEN 0xc004548d: 8 bytes {vinum, mode}; a non-zero mode byte is stored
  (stock: core + 0x364, the WDR buffer mode 1 = line / 2 = frame; here a
  module variable, the open WDR buffer ioctl does not size from it), mode 0
  is answered -EFAULT as on stock.
- LDC 0xc0045479..7b and GPIO 0xc004548e/f: the 1.2.5 module has no handler
  and answers 0 without doing anything. Here the same: **vendor no-op, no
  lens-distortion and no GPIO function** (before: -ENOTTY).

## Known issues (2026-10-10)

- **Heap overwrite across module reloads.** `rmmod tx_isp_t41` sometimes
  oopses in `module_param_sysfs_remove()`: one entry of the module's
  kmalloc'd param attribute array (always index 113, offset 0x1c4 of a
  kmalloc-1024 object) holds a small value (2, later 3). `t41_heap_watch=1`
  showed the value already present at load time and changed one jiffy after
  `tx_isp_release`, so the writer stores small state values through a stale
  pointer that survives a module reload. Suspects are the sensor module and
  the i2c client. It is not statistics DMA: switching AE/AF/AWB/WDR/TMO DMA
  off before their buffers are freed did not change it, and no ISP register
  points near the hit. Not seen in 30 timps stop/start cycles without a
  reload; it shows up in about every 5th to 12th load/stop/unload cycle.
  Diagnostics: `t41_heap_watch=1` (checks and repairs the array every jiffy,
  prints a step trail), reading `t41_heap_census` lists ISP registers that
  point into kernel RAM. Both are off/inert by default.
  Device run 2026-10-12 (T41 .32, `claude/t41-isp-handlers` 72e92520, with
  `t41_heap_watch=1`): 16 load/stop/unload cycles clean, the 17th oopsed
  after heapwatch had reported `stopped hits=0`: "Unhandled kernel unaligned
  access" in `rmmod`, epc `__free_pages+0x8` (page pointer = 2, BadVA 0x12),
  ra `__vunmap+0xc4` from `sys_delete_module`. With the param array guarded,
  the same small value now lands in the module area's vmalloc `pages[]`
  array (also kmalloc-1024 for a ~600 KB module), so the writer hits
  whatever kmalloc-1024 object reuses the address, not the param array
  specifically. Still open; reload cycles stay unsafe on T41.
  Branch `claude/t41-reload-fix` (host/build-tested only): the hit lands at
  0x1c4 modulo 0x200 in every report (param array in kmalloc-512 builds,
  vmalloc `pages[]` in kmalloc-512 now), so the stale object is most likely
  a freed kmalloc-512 (or -256) object. Fixed there: `fs_channel_ops` had no
  `owner`, so an open `/dev/framechanN` did not pin the module and its
  release/streamoff could run after a reload against the freed channel
  array (they store channel states 3 and 2); `tx_isp_free_irq()` freed IRQs
  with a different `dev_id` than requested for index > 0. New diagnostic
  `t41_heap_decoys=N` (with `t41_heap_watch=1`) parks N pattern-filled
  kmalloc-256/512/1024 objects in the slots the previous lifetime freed and
  reports class, offset and driver step of any stray write.
  Device run 2026-10-12 (T41 .32, 397409ac, decoys=32 + heap_watch): 50
  load/stop/unload cycles, no oops, decoy/heap/proc watch hits 0 in every
  cycle (the earlier build hit a decoy in cycle 5). The "csi init ignored
  bad vinum" log line never appeared, so the bad csi caller was not seen
  in this run. Separately `IMP_ISP_WaitFrameDone` still fails on the device:
  the counter stays at 13 and every wait times out, so the frame-channel
  signal in 397409ac is not reached per frame.
- **TMO does not run (2026-10-12).** `t41_tmo_frames=0`, `t41_tmo_error=-11`
  is the value set at stream start, not a returned error: the TMO worker is
  only queued from ISR status bit 17, and no bit-17 IRQ was logged in the
  whole run although bit 17 is enabled in 0x40020. Stream start holds the
  TMO top bypass (bit 22) until the first map is built from TMO statistics,
  and with the block bypassed its statistics engine apparently produces no
  bank, so the map is never built. Not changed: releasing the bypass before
  a map exists shows the calibration curve unvalidated; needs a device A/B
  first. SetTmoCurve has no visible effect until then.
- **No MSCA word latches with the default `t41_msca_cfg_update=0` (2026-10-13,
  read-only register dump on T41 .32, agg-38).** The active values are the
  reset defaults: global input 0xf0084 = 1920x1080 (the ISP input is
  2880x1620), ch0 0xf0100 = 1920x1080, ch1 0xf0200 = 1280x720, both ratios
  1:1 (0xf0728/0xf072c = 0x4000), CSC off (0xf08ec = 0), while the
  streamer runs ch1 at 640x360 (stride 0xf0280 = 640). So ch1 writes
  1280x720 lines into 640x360 buffers, which explains the band in buffers
  idx >= 1 and colours/brightness that do not follow ch0. The CSC words
  never latched for a second reason, fixed on `claude/t41-ch1` (CHANGELOG).
  Making the substream correct needs latching (`t41_msca_cfg_update=2`),
  which is blocked by the ch1 >= 960x540 hang below.
- **ch1 >= 960x540 started mid-stream can hang the SoC** with
  `t41_msca_cfg_update=2` (no oops, watchdog reset), also on a fresh boot
  without any earlier reload (960x540: one run 21/21 cycles, one hung in
  cycle 14). ch1 at <= 768x432 is stable (320x180, 640x360, 704x400,
  768x432); ch1 started as the first output while the input is stopped ran
  960x540 21/21. At 1280x720 the encoder additionally fails an order-9 DMA
  allocation when ch0 runs first. Default stays `t41_msca_cfg_update=0`.
- **Recommendation for streamers:** keep the T41 sub-stream (ch1) at
  <= 768x432.
- **Oops reading /proc/jz/isp (2026-10-11, once, agg-36 soak).**
  `grep -rh ... /proc/jz/isp/` died with "unaligned instruction access" at
  epc 0x30886b47, ra in `proc_reg_unlocked_ioctl()`: uClibc's `fopen()`
  issues TCGETS on every file, and `pde->proc_fops->unlocked_ioctl` held
  garbage. No fops of this driver has an `unlocked_ioctl`, so a
  `proc_dir_entry` (kmalloc-128) or a fops struct had been overwritten. The
  same pass printed the audio AIC register dump, which only
  `/proc/jz/audio/audio_aic_info` produces, so the directory's rbtree likely
  reached a foreign entry too. A per-file second pass did not crash.
  `t41_proc_watch=1` (default) snapshots every entry the driver creates under
  /proc/jz/isp (inode, mode, iops, fops, parent, data, name, fops contents),
  compares them every 50 ms and prints the old/new value with the
  surrounding memory (first 10 reports in full, then counters only). It is
  report-only: nothing is written back to the kernel structures. It also reports rbtree links of the isp directory
  that point at entries the driver did not create. Counters:
  `proc_watch_hits`, `proc_watch_rb_hits`. It narrows the window but does not
  remove the writer; it only helps locate it.

- **Recovered out-of-object accesses (2026-10-11 scan).** `tests/t41_overrun/run.sh`
  lists every compiled load/store at `&object + N` beyond the object size
  and whether the function is reachable. In the agg-36 build the named
  candidates (`vic_cmd_buf + 4/8/0xc`, `direct_mode + 4`, `tgain_wdr_s + 4`,
  `ispmem + 0xc/0x1cc`) are dead or unreachable code; the only reachable
  out-of-object stores are in the WDR path (not used with linear sensors),
  and none targets a `proc_dir_entry` or `file_operations`. The proc oops
  cause is still open. GCC reorders the recovered statics after most code
  changes, so anchor-relative recovered accesses hit different neighbours
  in every build. WDR fusion is refused unless `t41_wdr_fusion_unsafe=1`.
- **Device run 2026-10-12 (reload-fix module, 50 reload cycles, heap_watch=1
  heap_decoys=32).** No oops, no open framechan fds before any rmmod, snapshot
  200 after every cycle, `proc_watch_hits` and `heap_watch_hits` stayed 0. In 10
  of 50 cycles a decoy fired: always a kmalloc-512 decoy (slot number varies),
  always offset +0x1c4, value 3 shortly after arming, then 2 one jiffy after
  `tx_isp_release` at the next rmmod. Same signature as the param-attribute
  hit above, so the stale writer is still there, but now it lands in a decoy
  instead of the param array and no longer oopses. **WaitFrameDone still not
  fixed:** the counter stays constant (13) and every call returns after its full
  timeout with ret 0; the `isp_frame_done_wakeup()` call in the core 0x0100000b
  path is not reached (or does not advance the counter) in steady state.

## Defaults since 2026-10-19

`t41_vendor_ae`, `t41_clm` and `t41_tone_trigger` default to 1 (translated
vendor AE per frame, OEM CLM LUT by colour temperature, per-frame tone worker).
Set them to 0 for the previous behaviour (0 for `t41_clm` = no LUT, 2 = bypass).
Device-tested: 16.6 h overnight run on a gc5603 camera without reboot, 0 BUG/oops.

## Defog and size switches (2026-10-24)

- `t41_defog` defaults to 1 again. The translated defog chain now takes its constant tables from `tx_isp_t41_dfg_rodata.inc` (14784 bytes, the `.rodata` of the module the chain was translated from); earlier it used the rodata image of the vendor-AE translation, whose offsets are 1056 bytes off, which scaled garbage into the curve and weight-table registers and drew a diamond lattice at the block corners. Regenerate both include files with `tools/t41_vae/gen_defog.sh`. Check: `tests/t41_dfg_host.sh`; on a gc5603 (2880x1620) the registers 0xc000..0xc28c equal a vendor dump. `Module_Ratio` index 4 sets the strength (0..255).
- Size: `TX_ISP_T41_BRINGUP_PARAMS` and `TX_ISP_T41_TMO_SELFTEST` (Kbuild) default to `n`. Scripts that read the bring-up parameters, such as `tools/rawchart/t41_isr_stages.sh`, need `TX_ISP_T41_BRINGUP_PARAMS=y`. Details in `docs/SIZE.md`.
- CPU-load measurements: the kernel is built with `NO_HZ_FULL` and `VIRT_CPU_ACCOUNTING_GEN`, so the system column of `/proc/stat` does not show the time of the ISP kernel threads reliably. Compare stacks by free CPU (one idle-priority busy loop per core, iterations per second) instead.
- Known open issue: a camera rebooted under 1080p + 360p at 25 fps 8000 kbit/s (three events on two cameras); not yet explained.

## Colour check (2026-10-24, evening)

A 24-patch chart was measured on both T41 cameras against the vendor stack in the same scene (same IQ bin on each camera). The CCM (colour-temperature / exposure interpolation of the bin matrices and saturation transform), the AWB statistics configuration, the white-balance gains (within the AWB convergence band), BLC, BCSH and the TOP enable word equal the vendor within frame-to-frame noise; the worst patches are the same on both stacks (calibration of the bin). No code change was needed.

## Testing in QEMU

The modules can be loaded, unloaded and exercised without a camera in the `ingenic-t41` machine of the [gtxaspec/qemu](https://github.com/gtxaspec/qemu) `ingenic-txx` branch (boots the thingino image (64 MB, gc5603 sensor model, `eth0` present), all modules load, the streamer starts and 10 reload cycles are clean; frames and encoder output are not verified there). It is a crash-test bench, not a picture-quality bench: the ISP is a register-file model with a modelled frame path (synthetic colour-bar frames), there are no 3A statistics, and timing and image quality cannot be tested. Setup, per-SoC status and limits: [docs/QEMU_TESTING.md](../../docs/QEMU_TESTING.md).

## AE tuning API (2026-10-27, issue 90)

With the vendor AE running (`t41_vendor_ae=1`, the default) the AE tuning calls use the vendor AE's own data:

- `GetAeStatistics`: `tisp_ae_hist_last` (256 bins x4 with bin 0 the remainder of width x height, 5-bin histogram over
  histThresh) and the zone Y of AE state +7648, copied with interrupts off like the vendor AE writes them.
- `SetStatisConfig` with the AE part enabled: histThresh to `tisp_ae_hist_last` +1044 (used from the next frame).
- `Set/GetFaceAe`, `Set/GetAeExpList`: stock layouts and stores (`tx_isp_t41_tuning_ctl.h`, host test
  `tests/tx_isp_t41_tuning_ctl_test.c`); the face window is programmed through `tisp_ae_roi_point`.
- The ROI-window statistics (0x19060..0x19074, stock IRQ 61) are copied to AE state +7448.. in `t41_vae_calc_process`
  (`t41_ae_roi_stats`, default 1); the face AE meters them. The face AE converges slowly (vendor AE steps): on .34 a
  centre window moved the frame mean 98 -> 88 (target 40) and -> 106 (target 180) within 9 s.


## Module parameter `isp_bypass_graph` (issue 125, QEMU only)

`isp_bypass_graph=1` serves the vendor ISP bypass (`IMP_ISP_SetISPBypass(ENABLE)`, ioctl 0x80085418 with a non-zero value, before `IMP_ISP_AddSensor` as the vendor header requires): frame channel 0 reads the VIC MDMA (RAW16 BGGR, 2 bytes per pixel, pixel format 7) instead of the ISP core. Default `0`: the request is refused with `-EOPNOTSUPP` and the VIC frame-channel ops answer `-EINVAL`, nothing else changes. `SetISPBypass(0)` plus the next frame-channel open restores the ISP channels. Round trips are clean in QEMU (SetISPBypass, SET_FMT, REQBUFS, QBUF, STREAMON/OFF, NV12 after restore); the QEMU VIC has no MDMA, and no camera has delivered a raw frame through this path yet (see `CHANGELOG.md`). Pure logic: `tx_isp_t41_vic_bypass.h`, test `tests/tx_isp_t41_vic_bypass_test.c`.
