# Ingenic T23 ISP Recovery

This directory is the T23 bring-up workspace for matching the OEM
`tx-isp-t23.ko` behavior on Linux 3.10.14 targets.

## Sensor-generic contract

The T23 ISP module contains SoC and ISP-block behavior, not sensor tuning.
Sensor identity, I2C address, native geometry, media-bus format, exposure
limits, gain allocation, integration-time allocation, and FPS changes come
from the sensor module that actually binds. Sensor-specific image parameters
come from `/etc/sensor/<bound-driver>-t23.bin` (or the explicit
`source_core_tuning_path` override). A missing, short, or invalid profile
fails closed with tunable blocks bypassed; it does not select a compiled
fallback image.

The source startup path derives Bayer order and MIPI packing from the bound
media-bus/attribute data, builds the AE ladder through the sensor callbacks,
and loads Gamma, LSC, AWB, CCM, DPC, GIB, YDNS, DMSC, ADR, HLDC, BCSH, CLM,
MDNS, SDNS, and sharpen data from the selected IQ file. No executable T23
source names a sensor model and no generated sensor-profile tables are linked
into the module. The current direct input path accepts the T23 MIPI RAW8, RAW10,
RAW12, and YUV422 format identifiers; unsupported formats and buses are
rejected rather than guessed.

Sensor FPS (`IMP_ISP_Tuning_SetSensorFPS`, tuning CID `0x80000e0`) is sent to
the sensor as `TX_ISP_EVENT_SENSOR_FPS`; the sensor rewrites VTS and its
integration limits and syncs them back through `module.notify`, which this
driver installs on the bound sensor (`tx_isp_notify`). A request made before
the first sensor stream-on is held and programmed after the sensor init table
runs. Each accepted rate rebuilds the AE ladder for the new maximum
integration time. GET and `/proc/jz/isp/isp-m0` (`ISP OUTPUT FPS`) report the
rate the sensor driver holds.

The 2026-09-01 MIS20C1 smoke test proved the generic contract on hardware:
procfs reported the bound sensor's `0x20c1` chip ID, 1920x1080 mode, 30 fps,
and registered `0x30` address; the selected `mis20c1-t23.bin` loaded; AE
settled at luma 64; AWB continued updating; and both scaler channels produced
frames. The MIS20C1 saturation curve decreases with exposure, which also
verified that CCM interpolation handles either curve direction without the
old unsigned-underflow assumption. The tested module SHA-256 is
`09a237b32bfecf1c78191aeb5bee7f38aab64bbf2baf7faed69c036289dbdd74`.

The recovered whole-driver seed from `tx-isp-t23-v1` now lives in
`tx_isp_t23_core.c`, with separate math, sensor-registry, mode-profile,
subdevice, callback-plan, register-profile, frame-layout, scaler, and
tuning-ABI adapter objects. Kbuild links all ten into the existing
`tx-isp-t23.ko` canonical module identity expected by current sensor builds.
The math adapter delegates to the cross-SoC primitives, the registry adapter
delegates slot/procfs ownership to the common typed implementation, and the profile
adapter supplies the shared top-bypass flag merge. The T23 mode adapter owns
the SoC masks and exact 17-block refresh order used by day/night, custom-mode,
and tuning-bin transitions. The scaler adapter owns the recovered T23 sinc
table and four-tap correction order while delegating checked fixed-point
interpolation and normalization to the common T23/T41 generator.

The tuning-ABI adapter supplies checked shared libimp envelopes, command
descriptors, and expression/EV response packers. The frame-layout adapter
supplies overflow-checked NV12 geometry and the shared T23/T31 MDNS auxiliary
layout. Its private frame-channel arrays use the shared 68-byte frame-buffer
wire ABI and named word/flag constants. Its recovered 112-byte frame-image
format is compile-time checked against the shared format ABI. The
frame-channel compatibility aliases now use the common legacy-`V` ioctl
envelopes. Its request-buffer compatibility path uses the shared five-word
layout and named count/type/memory positions. T23 still owns dispatch, queue state,
alignment policy, register writes,
sensor-derived values, and its 12-byte allocation ABI's page padding.
Pad creation and recovered link teardown now consume the common pad/link ABI
offsets. The shared detach operation captures the three endpoints and clears
the first four link words while preserving link state, without changing the
linked module image.
Pad construction now also delegates the complete five-word active-link
initialization to the shared subdevice library. This is behavior-equivalent
to T23's zeroed allocation plus local flag write, but makes the initialized
record contract explicit and shared with T31.
The subdevice adapter supplies T23's graph table and legacy pad-slot offsets
to the shared name/type/index resolver. Its recovered graph descriptor reads
also use the common 8-byte endpoint wire positions.

## ISP OSD

The ISP-drawn OSD (libimp `IMP_ISP_Tuning_*OsdRgn` / `IMP_OSD_*_ISP`, used by
raptor and prudynt) is drawn by the MSCA into output 0 from ARGB pictures in
rmem. libimp sends `SetOSDAttr` (0x08000181, 12 bytes: type, byte order,
alpha disable) and `SetOSDBlock` (0x08000182, 20 bytes: slot 0..7, enable,
position, size, physical address, stride); `tx_isp_t23_tuning_ext.h` stores
them in the stock mscaler object and marks the slot dirty.

The core frame-done interrupt (`t23_osd_commit`) writes the dirty slots into
the MSCA, like stock `ispcore_irq_thread_handle -> tisp_msca_Shd_ctrl ->
tisp_msca_set_omi_api -> tisp_msca_api_set_osd`: inside `0xe000 = 0x101 /
0x01010102`, (value, register) pairs on the shadow port `0xe004` (order
`0x754`; per slot n `0x760 + 16n` left/top, `+4` width/height, `+8` address,
`+12` stride; enable `0x048`; format `0x750` = type | 0x70 | alpha << 8),
then `0xe100 = (pairs - 1) << 4 | 1`. Helpers and register map:
`tx_isp_t23_osd.h`; emulator audit against the stock code
`audit/osd_commit_emu.py` (bit-exact but for the enable word); host test
`tests/tx_isp_t23_osd_test.c`.

Beyond stock: the enable word follows the stored slots (stock only ORs bits
in, so a hidden picture kept its bit), a busy shadow port (`0xe100` /
`0xe00c` bit 1, or the MSCA curve loader writing the same port) defers the
update to the next frame, and a channel 0 start sends the shown pictures
again. Parameters: `isp_osd` (0644, default 1; 0 stores the requests
without writing the MSCA), `osd_commits` and `osd_busy_skips` (0444).
The draw blocks (`SetDrawBlock`, stock `tisp_msca_api_set_line`) and the
mask blocks (`tisp_msca_api_set_mask`) are still stored only.

Beyond stock (stability guard): `SetOSDBlock` with enable = 1 and an odd
picture width returns `-EINVAL` and stores nothing (stock takes it). With
an odd width written into the MSCA the ISP stops delivering frames (QEMU
T23 model: an odd-width picture shown through the region API stopped both
frame channels; with the guard the call fails and frames keep flowing at
the same rate). Disabling a block (enable != 1) is not checked.

## MSCA geometry check (crop hang)

A front crop window smaller than a channel output (the MSCA cannot
upscale), or a frame-channel crop outside the scaler output or larger than
the frame buffer, stalled every MSCA output for good. Since the front crop
window stays locked in the channel records, the stall outlived the session
and only a reboot helped (imgfx crop batch on vorne). Such geometries are
now refused with -EINVAL (beyond stock). Counter: `msca_geom_rejects`.
Details: `docs/MSCA_GEOMETRY.md`.

## Output/channel restart hang

Status: fix in branch `claude/t23-chan-restart-hang`, built; **device
test pending** (cam-B). Same hazard class as the
T41 output restart hang (`driver/t41/README.md`, "Output restart hang",
branch `claude/t41-chan-restart-hang`): MSCA output reprogramming and
update requests while frames flow.

### Symptom

cam-B (Galayou Y4, T23N + sc2336, `isp_clk=200 MHz`, `direct_mode=0`,
`isp_memopt=1`, `shvflip=1`), streamer timps: silent hard hang, no oops,
both ping and the console die, the watchdog resets ~60 s later. timps
wakes frame channel 0 on demand (daynight boot measure, switch and two
re-asserts per switch, `DN_REASSERT_MS` 8000: `fs_kick_chn0` = EnableChn,
500 ms, DisableChn) and re-sends HFLIP/VFLIP/running_mode on every chn0
enable edge (`fs_edge_relatch`). openimp's DisableChn is STREAMOFF, close
of the frame-channel fd and `VBMDestroyPool()` (the buffers go back to the
rmem allocator); EnableChn opens, SET_FMT, REQBUFS, QBUF, STREAMON. With
all channels idle the driver stopped the whole input with the last
STREAMOFF (CSI, sensor, VIC, TISP core `0x800 = 0`, IRQs) and started it
again on the next wake. Cameras whose streamer keeps the channels running
do not hang.

### Evidence (kmsg timestamps in s, logs in the session's `t23reboot-repro/`)

| run | module / parameters | what happened |
|---|---|---|
| `2100` | agg-24 module (every wake: input restart, `tisp_msca_chx_cfg_load()` incl. 0xd010, noop HVFLIP 0xd010) | tx-isp STREAMON 3170.962; wakes ("EnsureLinkStreamOn already-started") at 3171.546, 3177.966, 3186.147, 3194.318, 3202.955, 3214.217, 3222.202, 3230.847; dead after the 8th wake (ping timeout) |
| `2118-fix` | b1a4a975 (flip skip, output always kept enabled, restart skip, rmem crumbs, no FIFO guard) | module reload, STREAMON 1012.344, dead before the first wake (+0.57 s expected); IRQ counters frozen (isp-m0 903); rmem crumbs read back zero after the reset |
| `2128-step3c` | d28a0177, `msca_flip_skip_noop=1 msca_keep_enabled=1 msca_restart_skip=1` | STREAMON 543.037, 25 wakes up to 1143.646 (10 min), alive |
| `2139-control` | same instance, switches set back to 0 at run time | 8 min / 34 wakes alive: inconclusive, the dangerous phase is the minutes right after a timps start |
| `2227-fixon` | as `2128-step3c`, loop of `S95timps restart`, 180 s each | run 1 alive; run 2: DisableSensor 4237.497 (old process), new SET_BUF 4237.612, **"framechan0 unmatched MSCA completion y=0x3047000 uv=0x3245000 count=5" 4237.759**, tx-isp STREAMON 4237.765, first wake 4238.342, dead |
| `2245-final` | a325b523 defaults (release on close, restart reuse = bit set again at a frame boundary) | guard start ok; first `S95timps restart`: tx-isp STREAMON 764.910, **"no frame boundary within 200 ms (framechan-streamon), applied directly" 765.101**, wake 765.850, dead. The released output of the old process was re-enabled without reload while the new input was starting (no frame-done yet) |
| `4ea284c9` | stock-exact immediate channel start, release before every input start, start deferred to the first QBUF on an empty FIFO, flips and stop clears via the frame-done ISR | fresh insmod, first timps start: dead within seconds (no kmsg captured). Abandoned: the first-start path must stay the d28a0177 one |

### Root cause

Observed on the device (each a single run, so "observed" rather than
statistically proven):
- The per-wake path of the agg-24 module hangs within ~60 s of a timps
  start (`2100`); skipping the MSCA reload and the redundant update
  requests while the output keeps its enable bit across the input stop
  survived 25 wakes (`2128-step3c`) and one full timps start (`2227` run 1).
- Keeping the output enabled into a new session is fatal: in `2227-fixon`
  run 2 the output kept from the old timps process completed a frame into
  an old FIFO address ("unmatched MSCA completion") and the SoC died 0.6 s
  later.
- Re-enabling a released output without reloading it, with the input of a
  new session already started, is fatal too (`2245-final`).
- Any change to the first-start path of d28a0177 so far made things worse
  (`2118-fix`, `4ea284c9`). Which of the `4ea284c9` additions killed the
  first start is open (candidates: flips applied from the hard ISR at
  frame-done, the start deferred to a QBUF while the input runs, the
  frame-boundary waits on stop).

Inferred (consistent with the evidence, not isolated on the device):
- `2227`: the MSCA wrote into memory the new process (or the kernel)
  owned by then; openimp frees the pool right after the close.
- `2245`: after a core restart and a release the MSCA state is not what
  "reuse" assumed, and/or enabling it under a starting input (the wait for
  the first frame-done timed out, the bit was set directly) is unsafe;
  stock always does a full `tisp_channel_start()` at STREAMON. The reuse
  shortcut is now limited to the device-tested case (bit kept across the
  input stop of the same session, FIFO rearmed with the input stopped).
- `2118-fix`: with the output always kept enabled and the input running,
  the STREAMON FIFO rearm (`tisp_channel_main_fifo_clear()`) cleared the
  address FIFO of a live enabled output; the MSCA then writes the next
  frame to address 0 (physical 0 = kernel exception vectors/text).
- `2100`: the T41 mechanism (`tisp_msca_chx_cfg_load()` reprogramming plus
  0xd010 update requests right around an output/input (re)start). On T41
  this was bisected on the device; on T23 only the combination is shown.

### Stock comparison (`tx-isp-t23.ko`, unstripped, disassembled)

- `ispcore_frame_channel_streamoff()` (0x687fc) writes no register: state
  4 -> 3, queue memset, counters cleared. Stock never clears a 0xd040 bit
  at run time; `tisp_channel_main_stop()` (0x16804, clears the mscaler
  state byte) and `tisp_channel_main_fifo_clear()` (0x16824) have no caller
  (exported only). The address FIFO is never cleared.
- Channel STREAMON (`ispcore_pad_event_handle()`, state 3) calls
  `tisp_channel_start()` (0x167a4) -> `tisp_msca_chx_cfg_load()` (0x19e48):
  `tisp_msca_para_calc`, curves, `tisp_msca_init_chx_cfg`,
  `tisp_msca_write_reg` (0xd090/0xd094 window, **0xd010 = 1**), 0xd140/
  0xd160, then 0xd040 |= bit. Stock reloads on every channel STREAMON,
  with the input running (the input runs from tx-isp STREAMON to tx-isp
  STREAMOFF).
- Flip: the HFLIP/VFLIP controls (0x980914/0x980915) call
  `tisp_s_mscaler_hvflip_mask()` + `tisp_hv_flip_enable()` at once, which
  always writes 0xd050 and 0xd010 = 1 (`tisp_msca_api_set_mirr_flip()`,
  0x1b22c, no no-op check). The combined HV flip control while streaming
  only marks the change pending and `ispcore_irq_thread_handle()` applies
  it from the frame interrupt, i.e. stock itself moves that flip to a frame
  boundary.

Stock is safe only as long as an output's buffers live as long as the
output; with openimp's free-on-DisableChn and the per-wake input restart
of this driver that does not hold, so the fix keeps stock's "no work for an
unchanged output" and adds the lifetime and frame-boundary rules.

### Release defaults (2026-10-06, branch `claude/release-t23-driver`)

The defaults are the stock-like set that ran 7 h overnight plus many
streamer restarts: `chan_stop_keep_input=1 msca_keep_enabled=2
msca_fifo_rearm=0 msca_flip_skip_noop=1 msca_restart_skip=1
msca_session_release=1 crumbs=0`. The hang needs `chan_stop_keep_input=0`
together with `msca_fifo_rearm=1` (the earlier defaults below).

Without the FIFO rearm, the cold-start snapshot 503 (stale FIFO entries,
1911bb83) is now prevented the stock way:

- STREAMOFF waits up to `chan_stop_drain` x 10 ms (21, as stock) until the
  channel has no buffer left in the hardware.
- QBUF invalidates the buffer's cache lines, as stock does
  (`qbuf_cache_inv`).

Details, counters and the remaining exposure:
`docs/STREAMOFF_DRAIN_WAIT.md`. The section below describes the earlier
default set (history).

### The fix (defaults until 2026-10-05)

The device-tested path of d28a0177 (`2128-step3c`, first start plus 25
wakes) with its switches as defaults, plus one addition for the process
restart. Nothing else differs from that path.

1. `msca_flip_skip_noop=1`: a mirror/flip write with an unchanged 0xd050
   word issues no 0xd010 update request (timps re-sends HVFLIP on every
   chn0 enable edge).
2. `msca_keep_enabled=1`: the last STREAMOFF (input stops with it) leaves
   the output's 0xd040 bit set; a non-last STREAMOFF clears it as before.
3. `msca_restart_skip=1`: a STREAMON that finds the bit set and the same
   channel configuration does not reload the output (no
   `tisp_msca_chx_cfg_load()`, no 0xd010). Its FIFO is rearmed (cleared and
   refilled with the queued buffers) while the input is still stopped.
   Every other start does `tisp_channel_start()` as before / as stock.
4. New, `msca_session_release=1`: tx-isp STREAMON with the input still
   stopped (a new session, e.g. after a timps restart) switches off every
   output left enabled that no channel streams, drops its completions,
   clears its address FIFO and forgets its loaded configuration, so its
   next STREAMON loads it like a first start. No frame flows at that point.
   This closes the `2227-fixon` run 2 path (input started under an output
   still holding the old process's freed buffers). Counter `msca_releases`.

Per in-process wake on cam-B: STREAMOFF (bit kept, input stops), close,
REQBUFS/QBUF, STREAMON (FIFO rearm with the input stopped, input start,
no MSCA write). Per timps restart: release at tx-isp STREAMON, then the
first-start path.

Not done (tried in a325b523/4ea284c9, worse on the device): release on
close/REQBUFS, frame-boundary application of 0xd040/flip changes from the
core ISR, deferred starts, waits on the input stop, the stock-like input
that keeps running (`chan_stop_keep_input=1`, never device-tested here).

### Second look (2026-10-05, branch `claude/fable-chan-restart`)

Read from the hang logs and the stock module (`tx-isp-t23.ko`, unstripped,
galayou build), not from the device:

- **Trigger pattern in every T23 death:** a frame-channel STREAMON while the
  input is live, 0.5-1 s after a tx-isp STREAMON (`EnsureLinkStreamOn
  already-started`), death < 1 s later. With timps before `dac1200`
  (2026-10-05 22:34, kick reference held through the idle debounce) the
  wake was an input restart (`2100`: dead after 8 wakes); with the held
  reference the second EnableChn (chn1 or the JPEG channel) starts on the
  live input, and since `2245` every run died at that first one, the
  agg-24 module included (`2258-ch0only`), which had survived 8 wakes at
  `2100`. Which timps binary cam-B ran in each run is not recorded; check
  before the next bisect. This is the T41 pattern (channel start with the
  input live), so one mechanism is plausible for both.
- **Stock keeps the pipeline up between channel starts** (verified):
  `vic_core_s_stream(0)` only sets state 4 -> 3, `tx_isp_video_link_stream`
  walks the modules forward on both edges (core, VIC, CSI, VIN/sensor;
  the stop order is core first, sensor last), and
  `ispcore_frame_channel_streamoff()` writes no register. This driver
  (`chan_stop_keep_input=0`) stops sensor -> CSI -> core on the last
  channel off and starts CSI -> sensor (inside the VIC start, before the
  VIC unlock) -> VIC -> core on the next; the core is switched on after
  data already flows and off while it still flows.
- **`tisp_channel_main_fifo_clear()` has no caller in stock** (no
  relocation against it): the STREAMON FIFO rearm (`msca_fifo_rearm`,
  1911bb83) and the session release are the only run-time writers of the
  0xd?44/0xd?48/0xd?64/0xd?68 clear bits. The T41 fix (6dbe3f62) dropped
  the live-input rearm as part of what made its repro pass 35/35.
- **`isp_clk=` / `isp_clka=` never reached the hardware** (fixed here):
  `ispcore_activate_module()` set cgu_isp to `*(clk + 0x84)` and cgu_vpu
  (the ISP AXI clock) to `*(clk + 0x90)`, the flags / init_state words of
  the clk table entry three slots on, instead of `get_isp_clk()` /
  `get_isp_clka()` as stock does (0x6a4c0..0x6a518). The kmsg of every run
  shows only the insmod-time table rate (`cgu_isp can not set to
  153000000` = 1188 MHz / 8 = 148.5 MHz); cam-B's `isp_clk=200000000`
  was never in effect. With this fix 200 MHz becomes 198 MHz (1188 / 6),
  so set `isp_clk=153000000` in `modules.d` for an A/B against the old
  behaviour. `cat /proc/jz/clock` on the device shows the rate in use.
- The driver's own stream/MSCA/VIC lines are gated (`t23_runtime_trace`,
  default off); none of the hang logs has a single driver line between
  the second EnableChn and the reset. Next device run: `t23_runtime_trace=1`
  and `crumbs=2 crumb_addr=<hole>` (see Crumbs).

Device experiments, cheapest first (no build needed except the last):

1. Same binaries as `2128-step3c` (d28a0177, switches on, the timps of
   21:28) now. Dies -> environment or timps binary, not the driver state.
2. Stock-like input: `chan_stop_keep_input=1 msca_keep_enabled=2
   msca_fifo_rearm=0 msca_restart_skip=0 msca_flip_skip_noop=0` on the
   d28a0177/baf4ce2e module, or the `fs_keepalive` timps. Survives ->
   the per-start MSCA/FIFO path is the trigger; then bisect with
   `msca_fifo_rearm=0` alone.
3. `find /overlay` loop (10 min) with the ISP stack not loaded; reboot ->
   image/flash/PSU, stop driver bisecting. PSU swap for the same reason.
4. This branch's module with `isp_clk=153000000` vs `200000000`.

### Parameters (`/sys/module/tx_isp_t23/parameters/`, 0644 unless noted)

The defaults are the release set; the switches are debug escape hatches.

| parameter | default | meaning |
|---|---|---|
| `msca_flip_skip_noop` | 1 | 0: update request for every flip write (stock) |
| `msca_keep_enabled` | 2 | STREAMOFF: 0 bit off, 1 keep when the input stops too, 2 always keep (stock) |
| `msca_restart_skip` | 1 | 0: reload on every STREAMON (stock) |
| `msca_session_release` | 1 | 0: no release of left-enabled outputs at tx-isp STREAMON (d28a0177) |
| `msca_releases` | (0444) | outputs released at a session start |
| `chan_stop_keep_input` | 1 | 0: input stops with the last channel (before; hangs with `msca_fifo_rearm=1`) |
| `msca_fifo_rearm` | 0 | 1: clear and refill the FIFO at STREAMON (1911bb83, debug) |
| `chan_stop_drain` | 21 | STREAMOFF drain wait in 10 ms steps (stock), 0 off |
| `chan_drain_waits` / `chan_drain_timeouts` / `chan_drain_ticks_max` | (0444) | drain statistics |
| `qbuf_cache_inv` | 1 | cache invalidate at QBUF (stock), 0 off |
| `crumbs` | 0 | step markers: 1 rmem page behind the MDNS buffer, 2 page at `crumb_addr` |
| `crumb_addr` / `crumb_phys` | 0 / (0444) | crumbs=2 page / page in use |

### Crumbs (debug only)

`crumbs=1|2` (attached at the next SET_BUF) records the last steps in one
uncached page: layout and step codes in `tx_isp_t23_crumbs.h` (word 3 =
last step | arg << 16, word 5 = irq + 1 while in the hard ISR, ring of 64
steps). The next SET_BUF prints a valid record to kmsg (`previous record
...`, last 16 steps); devmem reads it directly. In rmem (crumbs=1) it
survives a timps restart or a module reload, **not a reboot**: the T23
U-Boot (2013.07, 64 MiB) relocates to the top of RAM and
`mem_malloc_init()` zeroes its 32 MiB malloc area below it, which covers
all of rmem (0x2a00000-0x3ffffff); cam-B read all zero after a reset. A
record that survives a watchdog reset needs a page below ~0x1e00000 the
kernel does not manage, i.e. a hole in the `mem=` boot arguments (e.g.
`osmem=16M@0x0 mem=26560K@0x1010000` leaves 0x1000000-0x100ffff free;
then `crumbs=2 crumb_addr=0x1000000`). The driver refuses a crumb_addr in
kernel RAM.

### Device test (cam-B)

1. Fresh insmod with default parameters; check
   `/sys/module/tx_isp_t23/parameters/{msca_*,chan_stop_keep_input,crumbs}`
   = Y, 1, Y, Y, 0, N, 0. Stream kmsg to the host.
2. Guard start of timps, >= 180 s (first-start path = d28a0177 step3c).
3. Ten `S95timps restart`, each >= 180 s; per run kmsg and
   `msca_releases` (expected +1 per restart, "released at session start"
   in kmsg, no "unmatched MSCA completion").
4. 30 min normal operation, then the overnight soak.
5. Negative control: `msca_session_release=0` plus `S95timps restart`
   loop should reproduce the `2227-fixon` run 2 hang; the agg-24 hang
   (`2100`) with `msca_flip_skip_noop=0 msca_keep_enabled=0
   msca_restart_skip=0`.

Results: pending.

## Historical recovery log

The entries below are chronological bring-up evidence. Earlier SC2336
observations describe the fixture used at that point and are superseded by
the sensor-generic contract above; they are retained as recovery history.

- `sensor_sc2336_t23.ko` loads against the recovered module.
- `/dev/tx-isp`, `/dev/isp-m0`, `/dev/misc-ivdc`, and `/dev/framechan0..3`
  are present.
- `/proc/jz/sensor/sensor0` reports the SC2336 metadata expected by Raptor.
- Raptor starts and publishes stable H.264 streams on both MSCA channels.
- The ten-object module passes a full one-shot device boot with advancing
  ISP/VIC interrupts and is followed by a verified persistent-driver reboot.
- Both enabled MSCA channels now generate their polyphase curves through the
  shared scaler library. Exact host regressions cover the T23 unity and
  one-third curves, and a clean device boot published stable 1920x1080 and
  640x360 streams at 25 fps with no fatal kernel, Raptor, or Android log
  entries. The tested open module remains active with SHA-256
  `d1b53dbe46435b1bc5bbb90d29a4b24185c368a79323b97b2432e839c8893848`.
- The math adapter now also owns `fix_point_div_32`, replacing the recovered
  pointer-arithmetic body with the common OEM-compatible wrapped divider.
  Hardware validation decoded 148 main frames in six seconds, 74 substream
  frames in three, and 124 main frames in the five-second post-transition
  check. Night/auto/day transitions passed, ISP/VIC interrupts advanced, and
  `dmesg`, `logread`, and `logcat` contained no new driver fault. The tested
  open module remains active with SHA-256
  `522d1324c640ab16ee1f5653407d275e06914cf4c1d255fa2b3cf4edd750a7f1`.
- T23's active `fix_point_mult2_32` entry point now lives in the math adapter
  and uses the common generation-compatible split multiplier. Unlike the
  T31/T41 full-range helper, this primitive deliberately preserves T23's
  32-bit fractional-product wrap before shifting. The device cycle decoded
  149 frames in six seconds, recorded 148 in six, and decoded 123 in the
  five-second post-transition check. Night/auto/day, image appearance, and
  ISP/VIC interrupts remained healthy; no ISP, Raptor, or kernel fault
  appeared in `dmesg`, `logread`, or `logcat`. The tested open module remains
  active with SHA-256
  `31418bfe7de79751d18e64ff46309fc0674cb7e6e9f39c7cca2055ea8b2b9f7e`.
- The common library and T23 math adapter now own the 32-bit fixed-point
  add/subtract entry points as well. This restores the recovered add function,
  which computed a value but returned zero, while preserving T23's unsigned
  underflow diagnostic in the adapter. The entry points currently have no live
  callers. Hardware validation decoded 149 frames in six seconds, recorded
  123 in five, and decoded 124 in the five-second final check; mode transitions
  and ISP/VIC logs remained clean. The active module SHA-256 is
  `7ec01426f8701170cd13feddba543c52e90cdb424122f47dc8e9949a8c07187c`.
- The same adapter now owns the SDK-declared 64-bit add/subtract entry points.
  Their recovered six-word declarations were the MIPS O32 expansion of
  `(pointpos, u64, u64)`; the adapter uses that authoritative C ABI, retains
  T23's local underflow diagnostic, and delegates wraparound arithmetic to the
  common library. These entry points currently have no live callers. A
  one-shot boot decoded 149 frames in six seconds, passed night/auto/day,
  advanced both ISP interrupt lines, and produced no driver fault in `dmesg`,
  `logread`, or `logcat`. The active module SHA-256 is
  `7ca7b50296bc689ec011ee77fa05efeb09d262eaeeacb555661b44e2456524ac`.
- The SDK's unsuffixed add/subtract pair has the same `(pointpos, u64, u64)`
  contract and now lives beside the `_64` pair in the adapter. There are no
  live callers; retaining both names is required by the vendor ABI. The
  one-shot boot passed night/auto/day, decoded 123 frames in the five-second
  final check, advanced both ISP interrupt lines, and logged no driver fault.
  The active module SHA-256 is
  `086c5467f5024c47ec04c945cd124bf6882b78be96e825c3c65c2215566291b8`.
- The stock T23 and T41 modules implement identical signed 64-bit fixed-point
  rounding semantics. T23's adapter now exports the official `(s64, s32)` ABI
  and delegates to the common helper, replacing a recovered body that invoked
  the arithmetic-shift helper four times and lost the high return word. T23
  currently has no live caller. The one-shot boot decoded 149 frames in six
  seconds, passed night/auto/day, advanced both ISP interrupt lines, and logged
  no driver fault. The active module SHA-256 is
  `3b95aabf4e5014f53ac4fa003553a3cdf86873bd727542723fb064564f5b5669`.
- The unsuffixed and `_64` two-/three-operand multiply bodies remain in the
  recovered core. An attempted adapter extraction built and inserted cleanly
  but made `rvd` exit during startup on two consecutive fail-safe boots.
  Rebuilding the committed local boundary reproduced the accepted
  `3b95aabf...` module byte-for-byte, restored Raptor control calls, passed a
  forced day transition, and decoded 124 main frames in five seconds. Treat
  this boundary as behavior/code-generation sensitive until its recovered
  call sites have typed signatures.
- The canonical `tx-isp-t23.ko` now consumes the shared legacy frame-channel
  ioctl envelopes. Its deterministic sequential build is active with SHA-256
  `214708e247d78178796bae93856c6210d4d045007ea98b73958e9c1f9fa02b0f`.
  Raptor reports 1920x1080 and 640x360 at 25 fps, an external RTSP consumer
  remains active, ISP/VIC interrupts advance, and the final `dmesg`,
  `logread`, and `logcat` fault scans are clean.
- The graph endpoint search now runs through the host-tested common subdevice
  resolver while its `0x38` graph table and legacy pad slots remain local.
  A one-shot boot bound the SC2336 once, applied day mode, advanced ISP/VIC
  interrupts, and decoded 148 1920x1080 frames in six seconds. All three fault
  logs were clean. The tested module remains active with SHA-256
  `865278fb52172ff948b4a4e2bc92c27680344c12b7b57dfcc9f1c94743fc4047`.
- The common pad-link state cycle booted once with marker consumption and a
  single SC2336 bind, accepted forced day mode, advanced ISP/VIC interrupts,
  and decoded 149 1920x1080 frames in six seconds. `dmesg`, `logread`, and
  `logcat` contain no driver faults. The candidate remains active with
  SHA-256
  `403bb2bbe4c81da5bd0bdc5ce81c7f4bdaa50ff9e268ac67e555a5f029fbb855`.
- The recovered remote-event export now has its OEM three-argument ABI and
  resolves the active-link sink and handler through the shared checked
  library instead of returning unconditional success. Its fail-safe boot
  registered and bound the SC2336 once, accepted forced day mode, advanced
  ISP/VIC interrupts, and decoded 149 1920x1080 frames in six seconds. All
  three fault logs were clean. The candidate remains active with SHA-256
  `d8f71fd58f2fde522b1cc61f8f29386bbf3c7869923a66003c9034b406801c58`.
- `check_state` now delegates its OEM queue/state decision to the common
  value-level policy while the T23 `0x1f8`/`0x20c` layout stays local. Its
  fail-safe boot bound the SC2336 once, accepted day mode, advanced both ISP
  interrupt lines, and decoded 149 1080p frames in six seconds with clean
  fault logs. The candidate remains active with SHA-256
  `86970c12687c268c795a53c91db734716662eefe2eaca4b41e6a45edf28ce61b`.
- The shared MDNS layout preserves the full 1080p `0x477e70` used size and
  T23's `0x478000` page-aligned allocation. Two July 30 validation boots
  decoded 127 frames in six seconds and 112 in five, passed night/auto/day,
  and left the open module active with zero ISP interrupt errors.
- The shared NV12 DMA plan now validates QBUF length, complete address range,
  and Y/UV placement before programming MSCA. Its two validation boots decoded
  125 main frames in six seconds, 73 substream frames in three, and 99 main
  frames in the four-second final check without rejecting a live buffer.
  The validated module SHA-256 is
  `0cd4c917624be506cfd35d233ea0aba11f9491486bbd981514de5c3993a4acf4`.
- The recovered child-platform path has symmetric remove handlers for its
  allocated subdevices, IRQs, MMIO mappings, clocks, pads, and channel state;
  the module can be unloaded after the sensor and consumers are stopped.
- The source-derived SC2336 GIB, LSC, DMSC, Gamma, static AWB, BCSH, and CLM
  startup images produce a clean, artifact-free image with working ISP/VIC
  interrupts. The exact LSC image programs all 651 OEM mesh nodes. The CLM
  image follows the T23 startup CT of 5000 K and programs both OEM LUT banks.
- Gamma runtime state now uses the OEM 129-entry `u16` table shape and an
  actual current-table pointer instead of a 16-byte array treated as a
  pointer. Linear and WDR payloads are exactly `0x102` bytes, the SC2336
  register image seeds both software tables, WDR selection switches the live
  table, and API updates refresh ADR's inverse-gamma tone-map data. Gamma init
  is 21 versus 24 OEM instructions and ADR gamma refresh is 145 versus 119,
  reducing the audit to 33 hard stubs and 77 collapses. A default device cycle
  decoded 261 measured RTSP frames at `YAVG/UAVG/VAVG/SATAVG`
  `114.9/128.4/125.7/6.4`, reached `12058/1048` ISP/VIC interrupts without
  faults, and rebooted module-clean.
- Both private and public 64-bit fixed-point log2 paths now retain their full
  normalization and iterative fractional-bit algorithms. The private routine
  follows the OEM helper-based leading-one path instead of collapsing to a
  tail wrapper; it is 69 versus 96 OEM instructions while the public routine
  remains 93 versus 129. This reduces the audit to 32 hard stubs and 77
  collapses. A default device cycle decoded 262 measured RTSP frames at
  `YAVG/UAVG/VAVG/SATAVG` `106.8/129.6/123.8/8.7`, reached `14774/1281`
  ISP/VIC interrupts without faults, and rebooted module-clean.
- The active LSC LUT writer now retains its CT-region interpolation, packed
  12-bit mesh blending, gain-strength scaling, and clamping in the matched
  function instead of having GCC outline that work into recovered-only helper
  symbols. Its emitted body is 337 versus 325 OEM instructions, reducing the
  audit to 32 hard stubs and 76 collapses without changing the register image.
  A default device cycle decoded 261 measured RTSP frames at
  `YAVG/UAVG/VAVG/SATAVG` `112.5/129.0/124.5/8.1`, reached `13920/1211`
  ISP/VIC interrupts without faults, and rebooted module-clean.
- Internal TISP stream-on now copies the OEM 156-byte channel descriptor
  fields, updates the shared sensor-info tail, and registers the total-gain,
  analog-gain, exposure, color-temperature, and IR event callbacks. The body
  is 80 versus 71 OEM instructions, replacing a two-instruction hard stub and
  reducing the audit to 31 hard stubs and 76 collapses. A default device cycle
  decoded 261 measured RTSP frames at `YAVG/UAVG/VAVG/SATAVG`
  `110.6/129.1/124.4/8.1`, reached `13673/1188` ISP/VIC interrupts without
  faults, and rebooted module-clean.
- Core startup derives the OEM `0xb5742209` non-WDR top-bypass mask from the
  deployed SC2336 tuning blob, with the same value as its read-failure
  fallback. The recovered block overrides produce final mask `0xb5742a89`.
  A 2026-07-16 no-argument run passed 256 RTSP frames and moved frame
  `UAVG/VAVG` from `122.8/128.2` to `128.2/127.3`, closely matching the OEM
  reference `127.9/126.8` while removing the green/purple spatial cast.
- Public module-control set/get now preserve the upper 13 top-bypass bits,
  replace the OEM lower 19-bit control field, and round-trip the MDNS luma
  filter state through bit 31. Both functions are within `0.92x..1.03x` of
  their OEM instruction counts. A 256-frame device regression retained live
  register `0xb5742a89`; the audit improved from 51 stubs/91 collapses to
  49/90.
- The CLM color-lookup runtime now implements the T23 HLIL five-region CT
  selector, 200 K transition margins, 32-unit update hysteresis, and exact Q12
  interpolation for all 1,050 hue/saturation entries. The register commit is
  bounded to the four 420-word OEM banks. Default CT5000 and diagnostic CT4200
  interpolation cycles each passed 256-frame RTSP tests; live AWB moved the
  latter from region 3 to region 4 with one table update. All three CLM profiles
  in this SC2336 tuning blob are zero, so this recovery is behaviorally neutral
  and does not address the remaining green/yellow cast.
- The full T23 MDNS temporal/spatial denoise path is enabled by default. Its
  473 tuning fields and 377 gain interpolations come from the T23 binary and
  SC2336 tuning blob, while the register packers are shared with the readable
  T31 implementation. `TX_ISP_SET_BUF` programs all OEM MDNS DMA planes and
  the stream-on path restores them after the core reset. Runtime total-gain
  changes refresh MDNS from process context with the OEM `0x100` hysteresis.
  A no-argument load has passed 256-frame RTSP tests with both luma and chroma
  filters active; `source_park_uninitialized_mdns=1` remains a diagnostic
  bypass.
- The T23 SDNS spatial denoise path is enabled by default. Its 123 tuning
  fields occupy the exact contiguous `0xbf18..0xd1d0` SC2336 payload that ends
  where MDNS begins. The register writers use the readable T31 packing with
  the T23 Gaussian-Y constant, and replace generated bodies that performed
  unaligned or out-of-bounds loads. Startup selects the non-WDR tables,
  commits the complete `0x8800..0x8b4c` image, and clears top-bypass bit 15.
  Runtime total-gain changes refresh the interpolation subset with OEM
  `0x100` hysteresis. Parked, explicitly active, and no-argument active device
  cycles passed full Raptor startup and RTSP checks; `source_sdns_internal_enable=0`
  retains a diagnostic top-level bypass while still validating register
  programming. The OEM 16-channel ratio scaler and complete linear/WDR table
  selector are recovered; their assembly sizes are 785/703 and 221/231 versus
  OEM. Both the default linear bank and diagnostic `source_sdns_wdr=1` bank
  passed 256-frame RTSP cycles with active ISP interrupts and no kernel errors.
  The latter changes only SDNS tuning tables; it does not enable sensor or core
  WDR mode.
- The T23 ADR front end now loads all 44 tuning regions from the exact
  `0x13f7c..0x14b44` SC2336 payload, reconstructs the 5x5 geometry, and writes
  the static tone-map register image. Parked and explicitly active cycles both
  passed 256-frame RTSP tests. Static activation increased contrast and
  highlight clipping without correcting the remaining color cast, so
  `source_adr_internal_enable=0` is the default. The large recovered
  `tiziano_adr_algorithm` and `Tiziano_adr_fpga` bodies remain unsuitable for
  dynamic use; `source_adr_dynamic=0` prevents their event registration.
- The T23 defog front end loads its exact `0x13728..0x13f7c` SC2336 payload,
  programs the OEM 10x18 block boundaries, and recovers the 3x3 max filter,
  weighted spatial filter, 32-bin LUT reducer, strength interpolation, and
  arbitrary-resolution radial geometry builder. Default parked, dynamic
  geometry, and static-active cycles each passed 256-frame RTSP tests. Static
  activation did not materially change channel means or the severe highlight
  clipping, so `source_defog_internal_enable=0` remains the default. The large
  statistics-driven `tisp_defog_soft_process` is still a hard stub and is not
  registered on the source event path.
- The source-derived AWB statistics setup produces valid 15x15-zone data in
  all four DMA banks when top-bypass bit 25 is cleared. The T23 tuning blob's
  input selector (`0xb004` bit 16 set) is required; the T31-derived selector-0
  override leaves every T23 AWB DMA bank empty.
- Optional `source_ae_stats_init` programs the exact T23 AE0 15x15 statistics
  geometry and thresholds. The DMA format and event cadence are verified.
  `source_ae_force_packed` is a zero-default bring-up control that sends one
  packed integration/gain value through the real sensor-ops ioctl after
  stream-on. For the verified SC2336 gain codes, packed `0x0080059c` is unity
  gain at maximum integration and
  packed `0x00c0059c` and `0x0880059c` select 1.5x and 2x respectively. The
  matching OEM GIB and DMSC total-gain state is inferred automatically; a
  nonzero `source_total_gain_q16` remains available as an explicit override.
- Optional `source_ae_hlil` adds a bounded process-context exposure controller.
  Its sorted ladder covers short unity-gain integration times through the
  sensor's real 1195-line boot setting and maximum integration, then the nine
  verified analog-gain states. Every `source_ae_hlil_interval` snapshots it
  selects the nearest proportional exposure for the tuning-derived luma target
  of 60, with a default deadband of 5 and a four-rung slew limit. Sensor I2C
  never runs in IRQ context, and gain-dependent GIB/DMSC/DNS/sharpen tuning is
  reapplied only when analog gain changes. Read-only counters expose runs,
  updates, dropped schedules, last luma, current state, raw Q10 EV, and status.
  This is the proven active branch, not the full recovered OEM AE solver, and
  requires `source_ae_stats_init=1`.
  The 2026-07-16 default device smoke converged from 1195 to 600, 256, 128, and
  96 integration lines while measured AE luma fell from 216 to 61. The stream
  passed 256 RTSP frames; frame `YAVG` fell from the prior clipped 222.1 to
  116.8 and `YHIGH` from 255 to 188.
- The T23 integer and 64-bit fixed-point log2 family now follows the HLIL
  normalization and fractional-bit iteration instead of returning zero. This
  restores the gain-conversion helper used by sensor analog/digital gain and
  EV reporting; the private 64-bit entry intentionally forwards to the same
  recovered implementation. The 32-bit core compiles to 63 instructions
  versus 65 OEM, and its fixed-point wrapper is 14 versus 14. A default device
  cycle decoded 257 measured RTSP frames at `YAVG/UAVG/VAVG`
  `109.6/128.0/126.3`, retained active ISP/VIC interrupts with `ERR 0`, and
  completed without kernel errors. The binary audit moved from 46 stubs and
  87 collapses to 45 and 86.
- The active BCSH RGB/YUV transforms now implement the T23 HLIL sign/magnitude
  expansion, both fixed-point matrix products, hue interpolation, and signed
  chroma rotation. `tiziano_bcsh_Tccm_RGBYUV` now compiles to 453 instructions
  versus 559 OEM, and `tiziano_bcsh_Toffset_RGBYUV` to 107 versus 154; both
  moved out of the collapsed audit class, reducing the total to 84. The
  `/dev/isp-m0` shim also dispatches the OEM 8-byte basic and 16-byte extended
  set/get ioctl layouts instead of returning success without touching the
  driver. Brightness, contrast, saturation, sharpness, and hue now initialize
  and round-trip at 128 through `libimp`; a live `112/144/160/140/64` test
  visibly exercised the recovered matrix path before restoring neutral state.
  A no-argument device cycle decoded 258 measured RTSP frames at
  `YAVG/UAVG/VAVG` `105.2/129.3/126.1`, retained active ISP/VIC interrupts,
  completed without kernel errors, and rebooted cleanly.
- Highlight depression and backlight compensation now preserve the OEM
  44-byte AE scene layout instead of sharing an optimized two-instruction
  stub. Their setter/getter paths update the correct words, set the OEM AE
  refresh flags, and are dispatched explicitly for controls `0x0800002a` and
  `0x08000037`. Highlight round-tripped `0 -> 32 -> 0` through `libimp`;
  direct OEM-layout ioctls confirmed backlight `0 -> 3 -> 0` (Raptor does not
  include the backlight getter in its aggregate query). A restored no-argument
  cycle decoded 256 RTSP frames at `YAVG/UAVG/VAVG`
  `108.2/129.5/125.8`, retained `30432/2698` ISP/VIC interrupts without new
  errors, and rebooted cleanly. The binary audit now reports 44 hard stubs and
  84 collapses.
- The AE1 static interrupt handler now follows the T23 bank-select, 4 KiB DMA
  synchronization, AE statistics decode, and event-flag sequence. It compiles
  to 33 instructions versus 36 OEM with all three calls and ten relocations
  retained, reducing the binary audit to 43 hard stubs. A no-argument linear
  mode regression decoded 256 RTSP frames at `YAVG/UAVG/VAVG`
  `108.3/129.3/125.8`, retained `13680/1185` ISP/VIC interrupts without new
  errors, and rebooted cleanly.
- AE ROI and zone weighting now preserve the OEM two-argument ABI, 225-word
  inverse-ROI transform, day/night parameter-bank copies, 900-byte get/set
  contract, refresh flags, and AE trigger. This removes a latent null access
  in the generated zone setter, which consumed the context in `a0` instead of
  the weight pointer in `a1`. The ROI transform compiles to 76 instructions
  versus 77 OEM and the zone path to 39 versus 41. AWB day/night refresh also
  restores the OEM first-frame marker, parameter reload, and hardware reload.
  A default device cycle decoded 258 measured RTSP frames at
  `YAVG/UAVG/VAVG` `106.2/129.1/124.7`, retained active ISP/VIC interrupts
  without new errors, and rebooted cleanly.
- The shared T23 tuning object now has the OEM `0x28944`-byte extent, so its
  `0x15844`-byte active bank at offset `0x13100` no longer overwrites adjacent
  globals. Day/night, custom-mode, and binary switching copy into that bank,
  derive the top-bypass bits from 32 consecutive active-bank words, and run
  the OEM refresh sequence. Their recovered sizes are 160/180, 150/161, and
  151/183 instructions respectively; tuning disable is an exact 15/15. The
  audit now reports 42 hard stubs and 84 collapses. A default device cycle
  decoded 260 measured RTSP frames at `YAVG/UAVG/VAVG/SATAVG`
  `105.0/128.1/125.9/6.7`, retained `26075/2282` ISP/VIC interrupts without
  new faults, and rebooted cleanly.
- MSCA parameter updates now recalculate each enabled channel, pack both OEM
  scaler registers, regenerate/write the channel curves, and commit the
  shadow configuration. The public scaler-level control restores automatic
  versus fixed-level mode, the `0..128` bound, per-channel level fields, and
  global curve-mode bits. They compile to 141/130 and 91/131 instructions,
  reducing the audit to 40 hard stubs with 84 collapses. A default device
  cycle decoded 257 measured RTSP frames at `YAVG/UAVG/VAVG/SATAVG`
  `105.7/128.3/125.9/6.5`, retained `15305/1328` ISP/VIC interrupts without
  new faults, and rebooted cleanly.
- The MSCA global output-window writer now derives the active bounds from all
  three enabled channel geometries, falls back to the sensor dimensions when
  no channel is active, writes the T23 `0xd090/0xd094` extent registers, and
  reruns scaling before the shadow commit. It compiles to 113 instructions
  versus 143 OEM and moves out of the collapsed class, reducing the audit to
  40 hard stubs and 83 collapses. A default device cycle decoded 262 measured
  RTSP frames at `YAVG/UAVG/VAVG/SATAVG` `112.4/129.4/124.9/7.0`, retained
  `19594/1698` ISP/VIC interrupts without new faults, and rebooted cleanly.
- The T23 HLDC path now loads its exact 72-byte SC2336 tuning block from file
  offset `0x14b44`, packs all eleven `0x9000..0x9028` parameter registers,
  and commits shadow register `0x9044` from the direct source startup path.
  The recovered strength interpolation, validity check, radial fixed-point
  calculation, attribute controls, and parameter-array controls replace the
  generated hard stubs and unsafe pointer bodies. Every live HLDC register
  matched the OEM module in a same-device comparison. A default recovered
  cycle decoded 264 RTSP frames at `YAVG/UAVG/VAVG/SATAVG`
  `109.6/128.9/126.1/6.5`, retained `37615/3261` ISP/VIC interrupts without
  new faults, and rebooted cleanly. The binary audit now reports 39 hard stubs
  and 83 collapses.
- Sharpening now loads its 49 OEM curves and configuration words from the
  active IQ bank (bank offset `0xb3e0`, file offset `0xb3f8`, `0x6d8` bytes,
  the window the OEM `tiziano_sharpen_params_refresh` copies from
  `tparams+0x1e4e0`) and runs `tiziano_sharpen_init` on every source core
  start: all `0x7000..0x707c` registers are written at unity gain and
  committed through `0x7090`, then the gain refresh moves the block to the
  gain in use (refresh threshold `0x100`, as the OEM). Bit 14 of `0xc`
  follows the bank flag like the OEM once the block is loaded and stays set
  (bypassed) while it is disabled (`source_sharpen_tuning_init=0`) or its
  load failed; a failed load does not stop the stream. A day/night,
  custom-mode or bin switch reloads the curves from the new bank and
  rewrites all sharpen registers (OEM `tiziano_sharpen_dn_params_refresh`).
- Sharpening initialization now selects all nine OEM linear/WDR interpolation
  tables through live pointer state instead of nulling the threshold table and
  consulting an unrelated global. Gain refresh consumes those selected tables,
  and the first full refresh retains its requested Q16 gain. The initializer
  now compiles to 75 instructions versus 85 OEM and the WDR selector to 59
  versus 67, moving both out of the collapsed class. A default device cycle
  decoded 265 measured RTSP frames at `YAVG/UAVG/VAVG/SATAVG`
  `107.1/128.3/125.6/6.6`, retained `17829/1551` ISP/VIC interrupts without
  new faults, produced a normal detailed color frame, and rebooted cleanly.
  The binary audit now reports 39 hard stubs and 81 collapses.
- `tisp_set_fps` now implements the SC2336 timing contract directly because
  the deployed T23 sensor module has no functional FPS ioctl slot. It reads
  HTS over the captured sensor I2C client, derives VTS from the 81 MHz pixel
  clock, writes `0x320e/0x320f`, and synchronizes all four integration-limit
  fields. `source_sensor_fps=0x190001` exercised 25/1 fps and reported the
  expected `HTS=2250`, `VTS=1440`, and `max_it=1436`; the stream passed 256
  frames at `UAVG/VAVG` `128.5/126.5`. The recovered API is `1.28x` OEM size
  and reduces the audit from 48 to 47 hard stubs without adding a collapse.
- An optional `source_awb_hlil` workqueue implements the active SC2336 branch
  of the T23 AWB algorithm: calibrated zone ratios, tuning-mesh weighting,
  indoor light-source distance-LUT weighting, distance refinement, history,
  live-EV RGBG-weight selection, inverse-temperature interpolation, and OEM
  gain conversion. The T23 HLIL call frame supplies `_rgbg_weight[_ot]` as the
  zone-selection mesh and `_color_temp_mesh` as the final CT mesh; keeping
  those roles distinct corrected the collapsed port's roughly 61,000 K output
  to a stable 4,400 K result in the same 256-frame no-argument run.
  Public WB controls now implement the T23 mode table, auto-gain reporting,
  relative-manual mode, start-gain accessors, and a freeze state honored by
  the live workqueue. A second 256-frame no-argument run retained neutral
  `UAVG/VAVG` of `128.0/127.1`. The binary audit moved `tisp_g_wb_mode` from a
  hard stub to the OEM instruction count and `tisp_s_wb_mode` out of the
  collapsed class, reducing totals from 52 stubs/93 collapses to 51/91.
  The earlier Q12 gray-world loop remains available only as a diagnostic
  fallback.
- Dynamic BCSH color-temperature and exposure updates are enabled by default.
  Source startup now initializes the complete SC2336 BCSH tuning state before
  restoring the exact 29-register startup image, so later AWB/AE events no
  longer fall back to the compiled identity matrix. The recovered four-point
  CT sorter replaces generated byte-offset arithmetic that caused an unaligned
  kernel access, and the seven-region interpolator implements the T23 200 K
  plateaus, forced refresh, and redundant-plateau suppression from the HLIL.
  Its assembly size is 223 instructions versus 272 OEM and is no longer
  classified as collapsed. A no-argument device run followed live AWB into CT
  region 3, decoded 257 RTSP frames at `UAVG/VAVG` `128.0/125.4`, retained
  active ISP/VIC interrupts with `ERR 0`, and produced no kernel faults.
  `source_bcsh_trace=1` provides a bounded four-update matrix trace for tuning
  diagnostics.
- The exact T23 CCM startup path applies the tuning blob's EV-derived
  saturation transform instead of writing the raw daylight matrix. It is
  stable and less extreme than the raw matrix, but the best verified startup
  keeps the top-level CCM bypassed. A 2026-07-16 no-CCM run retained adaptive
  AE/AWB, passed 256 RTSP frames, and removed much of the recovered path's
  exaggerated saturation and purple cast. `source_ccm_tuning_init=1` remains
  available for diagnostics while the pre-CCM spatial color error is repaired.
  The shared `cm_control` now implements the T23/T31 sign-decomposed 3x3
  fixed-point saturation multiply instead of byte-stepping through globals
  and consuming an uninitialized matrix. The active CCM diagnostic exercised
  two runtime CT updates and decoded 258 frames at
  `YAVG/UAVG/VAVG/SATAVG` `106.0/128.2/125.0/9.3`; the expected saturation
  increase confirms the matrix was committed. The no-argument regression
  retained the preferred bypassed image for 258 frames at
  `107.5/128.5/125.4/6.7`. Both runs had active ISP/VIC interrupts, no new
  faults, and clean reboots. `cm_control` now compiles to 135 instructions
  versus 229 OEM and moves out of the collapsed class, reducing the audit to
  39 hard stubs and 80 collapses.
- The VIN sensor-command interface now exposes the reconstructed file
  operations at `/proc/jz/isp/vin`, including bounded user-buffer handling,
  read-only sensor-register access, sensor-register writes, and complete
  procfs init/unwind/exit ownership. The open callback has the exact OEM
  instruction count, the show callback is 29 instructions versus 28 OEM, and
  the command parser is 236 versus 308 with 13 of 20 OEM calls retained. This
  removes `video_input_cmd_set` from the hard-stub class and reduces the audit
  to 38 hard stubs. On device, read-only commands returned the SC2336 ID bytes
  `0xcb/0x3a` from registers `0x3107/0x3108` before streaming.
- The full GIB de-IR table path now uses the OEM 33-word RGB bank dimensions,
  32-register channel packers, four-threshold region selector, linear
  interpolation, transition hysteresis, and update gate. Tuning is loaded
  from the SC2336 file's exact `0x2ab4..0x314c` range; the active-bank fallback
  observes the recovered `0x13100` tuning-object offset. This also replaces
  fourteen mis-typed 16 KiB globals and the four-byte blue table/header that
  received 132-byte/48-byte copies, reducing recovered BSS by 229,376 bytes.
  The parameter refresh is exactly 142/142 instructions, the interpolator is
  25/23, the LUT packer is 82/85, and the region selector is 143/164 versus
  OEM. Diagnostic `source_gib_ir_value=64` loaded IR points `5/50/51/128`,
  selected region 1, and decoded 259 measured frames at
  `YAVG/UAVG/VAVG/SATAVG` `108.0/129.3/125.1/6.8`. The no-argument regression
  decoded 259 frames at `109.8/129.3/125.0/7.2`, retained `17360/1507`
  ISP/VIC interrupts without faults, and rebooted cleanly. The audit now
  reports 38 hard stubs and 79 collapses.
- The T23 event subsystem now preserves the OEM two-channel shape: each
  channel has 80 reusable 48-byte records, separate pending/free lists, a
  20-jiffy completion wait, and ten callback slots. Push and process paths
  protect only list transitions, so algorithm callbacks run outside the
  queue lock as in the T23 binary. The recovered callback ABI also retains
  the OEM channel and duplicated event argument before the eight payload
  words. AWB, ADR, and defog producers now enqueue initialized records and
  register their actual interrupt/event functions instead of passing stack
  addresses or tuning-data offsets as callbacks. `tisp_event_process` is 145
  instructions versus 129 OEM, replacing its two-instruction hard stub and
  reducing the audit to 37 hard stubs and 79 collapses. A no-argument device
  cycle read the SC2336 `0xcb/0x3a` ID, decoded 260 RTSP frames, reached
  `18303/1590` ISP/VIC interrupts without kernel or Raptor faults, and rebooted
  module-clean.
- The custom-AE ioctl path now retains the OEM control snapshot and histogram
  metadata layout, normalizes long/short integration and gain through the
  sensor callbacks, computes the compensating ISP gains, and emits events
  4/5/6 only when analog gain, total gain, or exposure changes. Its init and
  handle functions audit at 86/99 and 240/322 OEM instructions instead of
  leaving the handle as a two-instruction stub. The shared AE register writer
  now performs both halves of the OEM transaction: it opens the `0xa000`,
  `0xa800`, or `0x1070` write gate and then writes the requested register.
  Hardware setup consequently commits the missing `0xa028/0xa828` terminal
  words. This reduces the audit to 36 hard stubs and 79 collapses. A default
  device cycle decoded 262 measured frames at `YAVG/UAVG/VAVG/SATAVG`
  `107.8/129.2/124.5/7.3`, reached `12917/1120` ISP/VIC interrupts without
  current-cycle faults, and rebooted module-clean.
- The ADR image interpolation helpers now use the T23/T31 bounded lookup
  algorithms instead of hard stubs. `subsection_map` finds the nearest entries
  in the 512-word response table, interpolates the selected point through the
  129-node gamma curve, and applies the requested fixed-point blend;
  `subsection_up` reconstructs all seven rounded interior breakpoints between
  the fixed 0 and `0xfff` endpoints. The AWB cluster ioctl wrapper also
  preserves all seven o32 stack arguments when forwarding its eleven-argument
  call. Their recovered/OEM instruction counts are `150/155`, `60/61`, and
  `55/26`, reducing the audit to 33 hard stubs and 79 collapses. A default
  device cycle decoded 261 measured RTSP frames at `YAVG/UAVG/VAVG/SATAVG`
  `111.6/128.9/124.9/6.9`, reached `13101/1138` ISP/VIC interrupts without
  faults, and rebooted module-clean.
- `source_lsc_ct` selects a generated SC2336 lens-shading image. The default is
  the OEM 5000 K startup; 3300 K is an exact A-to-T interpolation retained for
  indoor color diagnostics. The recovered transform primitives now use the
  exact 31-row by 42-node padded mesh, reverse its 252-byte packed rows through
  the OEM-sized `0x190` persistent scratch buffer, and exchange packed 12-bit
  mirror lanes without corrupting the adjacent coefficient. The public
  horizontal/vertical flip wrapper also forwards all five arguments. A
  256-frame device cycle retained neutral `UAVG/VAVG` of `128.2/127.1`; the
  binary audit moved the row transform out of the hard-stub class, reducing
  totals from 49 stubs/90 collapses to 48/90. Its recovered instruction count
  is `0.98x` OEM and the wrapper has the exact OEM instruction count. The full
  mirror/flip routine now seeds aligned mutable A/T/D tables, applies the OEM
  state-change transforms across all 1,953 words, and keeps that orientation
  through later CT and gain refreshes. It is `0.92x` the OEM instruction count
  and reduces the remaining collapse total from 90 to 89. Default and forced
  `source_lsc_initial_flip=1 source_lsc_initial_mirror=1` cycles each passed
  256 RTSP frames; the forced path retained neutral `UAVG/VAVG` of
  `127.9/126.6` without new shading or packed-coefficient artifacts. The exact
  T23 mesh-size allowlist, padded-stride check, and LUT-capacity check now
  guard that transform path, while day/night refresh resets the mutable tables
  and orientation state before forcing an update. The validator moved from
  `0.24x` to `0.69x` OEM size and the refresh is `1.12x`; a forced validator
  cycle passed 256 frames at `UAVG/VAVG` `128.5/126.7` and reduced the audit
  total from 89 to 88 collapses.
- Static initialization has reached the same visual plateau as the T31/T40
  recovery work. Further bring-up uses `tx-isp-t23-hlil.txt` as the behavioral
  specification for the dynamic 3A event path; T31/T40 source and history are
  used only to recover names and intent where the T23 HLIL is ambiguous.

Build from a compatible Thingino T23 3.10.14 kernel tree with:

```sh
make -C <kernel-src> M=$(pwd)/driver/t23 ARCH=mips CROSS_COMPILE=<mipsel-prefix> modules
```

Expected artifact:

- `driver/t23/tx-isp-t23.ko`

## Module parameter `isp_bypass_graph`

`isp_bypass_graph=1` enables the vendor ISP bypass graph (OEM `IMP_ISP_Tuning_SetISPBypass(DISABLE)`: link config 1, frame channel 0 delivers the sensor's raw frame from the VIC MDMA as `RG12`, 1280x720 = 1843200 bytes on the sc1a4t board; the frames do not go through the ISP pipeline or the MSCA). Default `0`: the link ioctls stay stubs and `ISP_PROCESS` accepts only 1, nothing else changes. Use order (as the OEM sample): create the channel, SetISPBypass(DISABLE), set the RAW format, enable the channel; after SetISPBypass(ENABLE) the raw channel delivers no more frames and has to be recreated (OEM behaviour). Only frame channel 0, only the sensor size. Read-only counters: `bypass_frames` (frames completed), `bypass_lost` (frame-done interrupts without a buffer owner). Bookkeeping of the five VIC banks: `tx_isp_t23_bypass.h` (host test `tests/tx_isp_t23_bypass_test.c`). Device-tested on the T23 (Jooan A6M, sc1a4t); nothing consumes it yet.
