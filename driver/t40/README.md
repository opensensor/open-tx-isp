# Ingenic T40 ISP Recovery

This directory is the T40 bring-up workspace for matching the OEM
`tx-isp-t40.ko` behavior on Linux 4.4.94 targets.

The initial `tx_isp_t40_recovered.c` file is a recovered whole-driver seed plus
the local parity fixes from the Wyze Cam 3 Pro T40XP/GC4653 smoke-test loop.
Hardware sequencing and tuning remain local, while reviewed object-layout
adapters now let T40 consume the same small shared-library contracts as the
other open drivers.

Build from a compatible 4.4.94 kernel tree with:

```sh
make -C <kernel-src> M=$(pwd)/driver/t40 modules
```

Expected artifact:

- `driver/t40/tx-isp-t40.ko`

## Current organization

- `tx_isp_t40_recovered.c` owns the recovered pipeline, device lifecycle,
  hardware programming, diagnostics, and T40 tuning policy.
- `tx_isp_t40_sinfo.c` adapts the T40 sensor object layout to the common typed
  registry.
- `tx_isp_t40_subdev.c` adapts the extended T40 graph and subdevice layout to
  the common graph resolver, remote-event resolver, readiness policy, and
  pad-link operations.

The T40 adapter retains generation-local pointer validation and the recovered
queue/state offsets (`0x1fc` and `0x218`). Remote-event filtering, diagnostics,
and the local frame-done fallback also remain in the recovered driver.

The first shared-subdevice device cycle ran on a T40XP/GC4653 camera on
2026-07-31.  A later 2026-08-31 cycle restored sensor-owned geometry and
rational frame rate reporting, producing the GC4653's native 2560x1440 stream
through both OpenIMP and direct V4L2 without a Raptor resolution override.
The open module registered one sensor, accepted forced day/night transitions,
kept IRQ 38/39 active, and supplied valid H.264 frames without a kernel-fatal
signature during the sustained checks.

Do not use an unbounded full read of `/proc/tx_isp_t40_recovered` as a health
probe. That legacy diagnostic path remains unsafe and caused the one-shot
test boot to fall back to stock. Use the bounded T40 probe tooling and the
specific `/proc/jz/sensor` nodes instead. The fail-safe boot loader now keeps
its early dmesg and kmsg captures in its persistent state directory so this
class of watchdog fallback retains evidence.

## Validated parity repairs

The 2026-07-18 parity batch replaced three unconditional kernel-build stubs
with behavior checked against the T40 OEM disassembly:

- `fix_point_div_32`: unsigned integer and fractional Q-format division
- `tisp_round_int64`: signed 64-bit right-shift with half-up rounding
- `defog_wei_interpcot`: 32-bin accumulation, rounded averaging, clamping,
  and monotonic output
- `defog_count_weight35abc`: preserve the OEM reducer count across the final
  call's MIPS delay slot and restore cleanup of all 13 temporary buffers

The batch builds against the Thingino T40XP/GC4653 Linux 4.4.94 tree. A smoke
run on the `.242` test camera completed block initialization, produced a valid
1920x1080 RTSP frame, kept Raptor and both ISP interrupt lines active, and
returned the camera to a clean boot. Evidence is in
`logs/20260718-t40-parity-batch1-final2-smoke/`.

The final OEM/recovered assembly audit reports 32 hard stubs, down from 35
before this batch, with no increase in collapsed functions (18).

## Forensic image-quality checkpoint

The 2026-07-18 GC4653 comparison loop reached the retained "good enough"
checkpoint on the `.242` test camera.  The stock oracle is
`logs/20260718-t40-forensic-stock-2105/`; the most useful recovered-driver
evidence sets are:

- `logs/20260718-t40-v42-lsc-active-exposure-trim-settled/`: best stored
  full-frame score and the retained stable visual baseline
- `logs/20260718-t40-v52-ysp-lsc-gain-settled/`: independent YSP/DNS gain
  control with the fixed YSP register groups matching stock at gain 229376
- `logs/20260718-t40-v53-dmsc-literal-gain212541/`: complete literal DMSC
  smoke, state/core capture, frame comparison, and live gain sweep

The retained implementation includes the exact LSC mesh, fixed CLM topology,
live CCM/BCSH controls, independent `ysp_gain_ev`, and a self-contained
source-derived DMSC chain.  The DMSC literal path remains opt-in through
`enable_dmsc_lit=1`: its complete consumer/evidence cycle was run at the stock
event gain of 212541.  A disposable live sweep found that gain 229376 was the
closest match for the primary stock DMSC register groups, but it was not
promoted to the default because it did not receive a separate full consumer
cycle.  The sweep was discarded with a clean reboot.

The exact source-derived BLC/GIB paths now follow the active sensor IQ bank's
bypass flags on every day/night transition.  The GC4653 day and night banks
enable BLC and supply its gain curves, so BLC is initialized and updated from
the sensor's live analog gain.  Both banks explicitly bypass GIB; the driver
honors that calibration instead of force-enabling the block.  Force-enabling
GIB against those banks produced a nearly black/green frame and is retained
only as a forensic override.

The 2026-09-01 image-quality cycle also removed an uncalibrated coupling
between white-balance gains and colour temperature.  WBG gains alone are not a
portable CT measurement, and the old placeholder ratio mapped a neutral
GC4653 scene to the 2300 K endpoint, causing a yellow/green cast.  LSC and CCM
remain active on the tuning bank's calibrated 5000 K reference until the AWB
path supplies a real CT result.  The same cycle widened the frame-sampled AE
deadband to its configured value and limited highlight trimming to a scene
whose mean has actually reached target, eliminating the observed gain-index
ping-pong.

The date/time OSD in the upper-left corner is outside the ISP comparison.  It
is rendered by the userspace overlay using the camera's system clock, so any
remaining offset or formatting issue should be fixed in the Thingino
time/NTP/timezone and OSD configuration without changing this driver profile.

## Eufy T40XP / sc830ai bring-up (2026-10-12, branch `claude/t40-sc830ai`)

Second T40 device: Eufy T8416 (T40XP, sc830ai 3840x2160@20 on CSI0/i2c1
0x30, boot mode 4; the second sensor sc3338 is unused).  Linux 4.4.94
(`thingino-out/eufy_t8416_master/build/linux-3143636237cf5…`), vendor SDK
d30c0af with ISP firmware 1.3.1.

First open-driver boot (2026-10-12 19:20, commit 3bd3087b): insmod, sensor
detect, `IMP_ISP_Open/AddSensor/EnableSensor`, `FS_EnableChn` and
`StartRecvPic` all returned 0, but 0 frames, ISP IRQs 36-39 stayed at 0 and
the sensor never logged "stream on".  dmesg showed
`send_event … event=0x3000002 ret=-22` (SET_FMT), `0x3000005 ret=-22`
(QBUF) and `0x3000008 ret=-515` (SET_BANKS, expected) on framechan1.

Findings:

- `t40_devtest` streams frame channel 1 (1280x720 scaled).  The regtrace
  stream path handed the frame-channel index to `vic_core_s_stream`, the CSI
  state/stream helpers, `tx_isp_vic_index_cal` and the cached sensor
  attribute lookup.  On T40 those take the sensor number (vinum): frame
  channels 0..2 belong to vinum 0, 3..5 to vinum 1 (the OEM `tx_isp_core_probe`
  stores `index / 3`; the Eufy 1.3.1 module writes `index % 3` to +0x74 and
  `index / 3` to +0x78 of each core channel).  Channel 1 therefore addressed
  the unbound second sensor.  Fixed by `regtrace_channel_vinum()`.
- `AeIntegrationTimeUnit : -1064949056` plus a stack dump is not a sensor
  attribute problem: `frame_channel_unlocked_ioctl` prints a mis-resolved
  rodata literal (`LC79`) with `&__param_str_isp_dual_buf` for an
  unsupported ioctl; the value is that pointer.
- The rmmod oops recorded on the Eufy (`Kernel unaligned instruction access`,
  epc 0x6ef, module size 763904) was the vendor `tx_isp_t40`, not the open
  module.  The open module's unload path (`tx_isp_t40_core_exit`) frees IRQs
  with the same dev_id it requested them with and pins itself through the
  misc fops owners; it has not been rmmod-tested on the Eufy yet.
- `KERN_INFO` notes are suppressed unless `t40_runtime_trace=1` (only lines
  with `ret=-…`/`fail=…` pass), so the first boot's dmesg hid the whole
  core-event / VIC / CSI trace.  Test boots use `t40_runtime_trace=1` with a
  `dmesg -c` drain loop.
- `regtrace_core_event_tisp_bootstrap` only runs for frame channel 0, so a
  stream must start on channel 0 before channel 1 can be used.
- The driver still carries GC4653 fallbacks (synthetic attribute 2560x1440,
  literal LSC/CLM/DMSC tables, IQ bank names).  They are only used when the
  sensor attribute is missing, but image quality on sc830ai is GC4653-tuned
  until an sc830ai bank exists.

Open image recipe (firmware tree `claude/t40-prod-fw`): same camera config
`eufy_t8416_t40xp_sc830_aic8800d40`, the ISP choice comes from the user
overlay fragment (`BR2_PACKAGE_THINGINO_ISP_OPEN=y`, proprietary choice
unset), open-tx-isp + OpenIMP, SDK sensor modules unchanged (the stock
`sensor_sc830ai_t40.ko` resolves all 35 imports against this module,
`tests/check_ko_symbols.sh`).  Build with `OPEN_TX_ISP_SITE=<this repo>
OPEN_TX_ISP_VERSION=<sha>` on the make line.  Keep the camera name: the
user overlay (U-Boot 2026.07, the streamer, WiFi) is keyed by it.

### Device runs 2026-10-12 (test boots 1-3, commits 5e94df1e..68ac89d0)

| run | state | result |
|---|---|---|
| b1 | vinum fix | `sc830ai stream on`, CSI/VIC/core streamon ret=0, isp-w02/isp-m0 IRQs run, 0 frames: tisp_main_init and MSCA used the synthetic GC4653 2560x1440 attribute; framechan1 events resolved to ch=-22; rmmod oops in `ispcore_slake_module` |
| b2 | + early attr seed, late pad bind, slake call 1 | geometry 3840x2160, core frame-done IRQ (status0 0x2000) every ~106 ms, channel 0: `GetFrame` OK but 1 frame per 2 s (channel frame-done only every 1.65 s, buffer content all zero); pad 1 resolved to channel 0; rmmod oops at a second mis-resolved call |
| b3 | + slake call 2, pad ids | ch0 native 3840x2160 (no scaler): same 1 frame / 1.65 s; ch0 1920x1080 run ended in a kernel panic (`panic=2` reboot, log lost: the kmsg drain wrote to tmpfs); extra run ch0 1280x720 with `irq_frame_done_require_content=0`: unchanged, so the content gate is not the limiter |

Current state: sensor, CSI, VIC and the ISP core run; the MSCA output
completes a frame only every ~1.65 s and writes no data (the sampler reads
the buffer uncached, the zeros are real).  The deferred frame-done work
(`regtrace_irq_frame_done_workfn`) finds a done address in the MSCA address
FIFO (`Tzn_Msca_addr_fifo_read`) only at that cadence.

### Round 2, 2026-10-12 evening (boots r1-r3, commits 9fe90a6f, 64692b1d)

- r1/r2a `t40_profile_direct_vic_feed=1`, ch0 native 3840x2160: 41 frames
  per 2 s (20 fps) through the VIC MDMA qbuf ring, but the dumped frame is
  all zeros; 720p under direct feed panics (VIC writes full-width lines
  into the small buffer).
- r3a normal path, registers read with devmem while streaming and diffed
  against the vendor stack streaming the same sensor
  (`t40prod/out/oracle/vendor-regs.txt` vs `out/p4/r3a/*-regs.txt`): MIPI
  PHY and CSI identical (settle 0x1b, lanes 2, VIC 0x04 = 0x0f000870,
  0x0c = 2); the vendor programs the VIC output DMA block 0x300..0x350
  (0x304 = 3840x2160, four raw buffers at 0x318..0x350) plus 0x8c/0x90/
  0xa0/0xb0 and 0x3a4/0x3b0/0x3c0/0x3e0/0x3e4 (0x32/0x44000/0x37b/0x204);
  the open driver leaves 0x304 at the probe default 1920x1080, the bases
  at 0 and the latter group at 0x6f/0x4402b/0x499/0x81.  T40 runs 4K in
  VIC frame mode (VIC -> DDR -> ISP core); the open driver only brings up
  the direct (streaming) input that worked for GC4653 2560x1440, so the
  core and MSCA produce empty frames.
- Sensor swap inside one boot (sc3338 counter-check) is refused by the
  regtrace sensor capture ("sensor client exists but no tx_isp_subdev_init
  capture occurred"), so that check needs its own boot with the sc3338
  module loaded first.
- rmmod oopsed four times in the recovered tisp_deinit path; the loop is
  now skipped by default (`skip_tisp_deinit=1`), untested.
- The kernel has no netconsole (CONFIG_NETCONSOLE/NETPOLL unset); panic
  logs need the serial console.
- the streamer did not start on one vendor restore boot (no log line); manual
  `start` of the streamer init script worked.  Keep the streamer init script at mode 0755 when restoring.

### Round 3, 2026-10-12 night (A/B register oracle, commits f25ce716..0855c953)

Method: the same `t40_devtest` + OpenIMP `libimp.so` run on the vendor
1.3.1 module (39 fps at 4K) and on the open module (1 empty frame per
1.65 s), registers read with `devmem` mid-stream and diffed
(`t40prod/out/pv/v2/regs.txt` vs `out/p4/r11a/*-regs.txt`, full core
0x13300000-0x13320000, VIC, CSI, PHY).

- The vendor does not use the VIC DMA bank (0x13380300 stays idle); the
  frame-output path in f25ce716 is therefore off and only kept as an
  experiment.
- The vendor keeps the MSCA address FIFO like the open driver but with
  other words: Y 0x80021100 / UV 0x80022001, addresses tagged y|6 uv|7,
  1:1 coefficients 0x200/0/0x200/0, 0x1617c = 1, 0x16194 = 0x11001,
  0x1602c = 0x7600, shadow 0x50420 = 0, top 0x88 = 0x101, 0x40 =
  0x7fd0000d, `tisp_stream_on` writes 0x1010=0, 0x1014=0x11e, 0x1060=1,
  then 0x1010=1, 0x1014=1.  All of this is now reproducible through
  parameters (`t40_msca_fifo_ch0_*`, `t40_msca_fifo_addr_tag_mode=4`,
  `t40_msca_vendor_fixups`, `t40_quality_top40_override`,
  `tisp_main_init_reg88_override`, `t40_core_fixup_shadow0`,
  `t40_tisp_stream_vendor`, `sensor_full_*_override`) and was verified in
  the dump; the result did not change: the ISP core raises its frame-done
  (status0 0x2000) per frame, the MSCA FIFO keeps its two tagged entries
  (0x1617c/0x16194 = 0x22001) and never consumes them.
- What still differs after that: the tuning blocks the open driver never
  configures (DPC 0x3000, 0x4000/0x5000, AE/AWB statistics 0x7000/0x8000,
  0xb000, 0xe000, 0x10000/0x11000 and the LUTs) and the group
  0x13301104/0x1120/0x1134/0x1138/0x1160 (vendor 0x58f/0/0x333/0x100010/
  0xc700, open 0xde70716/0x20000/0/0x10002/0xa000; 0xa000 = 2560*16 again
  looks GC4653-sized).  Their writers are the tisp parameter tables, not
  direct register writes.
- Every second stream start after a 4K run panics (five of five), the
  first run never does; one run per boot until the cause is known.
  The kernel has no netconsole, so the panic text is lost.
- The sc3338 counter-check (sensor module loaded before the first
  AddSensor, CSI1, 2304x1296) detects and streams the sensor but oopses in
  `tx_isp_send_event_to_remote+0x3c0` at `FS_EnableChn`; not analysed.

### Night of 2026-10-13: ISP overflow

The vendor core ISR names error-status bit 0x20 "ispcore: isp overflow!!!"
(string `$LC183`); the open driver logged `err=0x20` on every frame.  The
seed's clock table pins `div_isp` to 200 MHz (168 MHz effective), the
vendor runs `isp_clk=300000000` (CPM ISPCDR 0x40000003 = MPLL/4).  Fixed by
taking the rate from the `isp_clk` parameter.  The vendor ISR also uses
status bit 0x400 for an MSCA work-enable countdown handshake (clear bit,
re-set after N frames); bit 0x400 never fired on the open driver while the
core overflowed.  Vendor counters are readable in `/proc/jz/isp/isp-m0`
(`debug0`), the sensor IQ bin is loaded from `/etc/sensor/sc830ai-t40.bin`.

After the clock fix the pipeline runs at 20 fps with 24/24 devtest passes
but all-zero output; the direct VIC feed dump (r15a) now contains pixel
data, so the black came from the sensor: the AE packed its GC4653 gain
index into the EXPO event while sc830ai's `set_expo` expects the LUT
register value (0x4080 = 1x).  b0611287 converts the index through the
sensor's `alloc_again`.

### 2026-10-13 00:28 – first real frames on the Eufy T40XP / sc830ai

Run r20a: open module (clock fix a16b94f3, AE alloc_again b0611287), 4K
channel 0, 39 frames per 2 s (20 fps), 2.4 Mbit/s H.264, decoded frame is
the IR night scene.  Parameters:

    insmod tx-isp-t40.ko isp_clk=300000000 t40_quality_profile=0 t40_generic_profile=1 \
        enable_mdns=0 enable_adr_reg_writes=0 enable_ydns=0 enable_sdns=0 \
        enable_ysp=0 sensor_full_width_override=3840 \
        sensor_full_height_override=2160 skip_tisp_deinit=1
    insmod sensor_sc830ai_t40.ko

With quality profile 5 (MDNS/YDNS/SDNS/YSP/ADR active) the core never
raised the late status bits 0x100/0x200/0x400 and the output stayed zero;
with profile 0 (blocks bypassed) the pipeline completes.

Block bisect (each run one boot, metrics only, media discarded):
- r21a profile 0 + `enable_mdns=1`: 20 fps, 2.3 Mbit/s, luma mean 42 -> MDNS
  is fine at 4K.
- r23a same: 186 frames / 10 s, consecutive-frame SSIM 0.977..0.997.
- r22a profile 0 + MDNS + YDNS + SDNS + YSP: immediate kernel panic
  (self-reboot, no console); one of the Y blocks crashes at 4K.
- r24a profile 0 + MDNS + YSP: kernel panic -> YSP is the crashing block
  (recovered `tisp_ysp_*` path at 4K); keep `enable_ysp=0`.
- r25a + SDNS, r26a + SDNS + YDNS, r27a + ADR, r28a + CCM + gamma, r29a + BLC + LSC + GIB: fine (200 frames / 10 s, 0 decode errors).
- r30a/r31a quality profile 5 with YSP off (and DMSC-lit off): black
  again; the profile >= 1 extras (GC4653 literal tables, top40 bit 2) are
  not usable on this sensor.
- Recommended for the Eufy: `t40_quality_profile=0 t40_generic_profile=1`
  (607695b7) = profile 0 plus MDNS, SDNS, YDNS, ADR, CCM, gamma, BLC, LSC,
  GIB; YSP and DMSC-lit off.
- r32a generic profile, channel 0 scaled to 1280x720: fine (201 frames /
  10 s, luma mean 53).  rmmod afterwards oopsed in the `isp_core_tuning_clear`
  model stub (bad pointer); guarded in 6b70a5e5.  r33a: rmmod still takes
  the camera down (no console); reload is not usable yet.
- t1 the streamer (OpenIMP backend, 4K main + sub stream) on the open module:
  the streamer oopsed the kernel in the recovered `tisp_s_antiflick` (bad AE
  parameter pointer) right after `SetISPRunningMode(night)` returned -1;
  antiflicker is now a no-op unless `t40_allow_antiflick=1` (open item: no
  50 Hz antiflicker on T40 until the recovered `tisp_s_antiflick` is fixed).
- t2: the next the streamer call, `tx_isp_sensor_g_attr` (IMP_ISP_Tuning_GetSensorAttr),
  oopsed on the empty core sensor slot; d3544601 answers it from the bound
  sensor's attribute and video state.
- WLAN failure of the agg38-fw/hybrid image (host-side diff): the user
  overlay `thingino-user/common/overlay/etc/wpa_supplicant.conf` bakes
  ssid FB_IOT_1 while the Eufy lives on FB_IOT_0 (its runtime overlay had
  FB_IOT_0 and the flash replaced it); S38wpa_supplicant in agg38-fw adds a
  preset/portal fallback on top.  Fix for the recipe: a per-camera
  `wpa_supplicant.conf` in the eufy user-overlay dir, or keep the overlay.
- t3-t6 the streamer (video0 1920x1080 scaled + video1 640x360): after the
  tuning fixes the streamer streamed, then died with SIGBUS on the first 1080p
  frames; devtest 1080p runs had panicked the kernel three times and every
  second stream start after a 4K run panicked.  Cause: the seed laid NV12
  buffers out as width*ALIGN(height,16); OpenIMP and the vendor use
  width*height*3/2, so 1080p frames overran their buffers by 8 lines.
  989e7424 makes the vendor layout the default (`t40_nv12_height_align=1`).
- t7 the streamer with the layout fix still died with SIGBUS right after
  "framesource 0 enabled".  kmsg showed the real cause: the second frame
  channel (video1 640x360) enabled the core IRQ with irq index 1 (= the
  second ISP core instance) -> `core IRQ OEM enable idx=1 ret=-22` ->
  `core-event streamon ch=1 ret=-22`, OpenIMP then crashed the streamer.
  f03d0700 maps the core IRQ to the vinum (channel/3, same as VIC/CSI)
  and reference-counts the streaming channels so the shared IRQ is
  enabled once and only disabled by the last channel.
- t8 (f03d0700): no -22 chain any more, but the streamer died again right after
  "framesource 0 enabled", now SIGSEGV pc=libimp VBMGetFrame+0xd4.
  Resolved via the crash maps + LD_TRACE: the crashing libimp is
  `/lib/libimp.so` = the **Ingenic vendor** library of the hybrid image
  (strings "IMP-ISP", "Ingenic High Pass Filter"), not OpenIMP.  All the streamer
  runs t1-t8 therefore ran vendor libimp against the open driver; its
  VBMGetFrame builds the frame pointer from an index the open DQBUF does
  not fill the vendor way -> wild pointer (t7 si_addr=0, t8 0x62dbef84).
  devtest always used OpenIMP (`LD_LIBRARY_PATH=/tmp/otx/lib`), which is
  why it streams.  p5-the streamer.sh now uploads lib2/libimp.so (OpenIMP
  t40-prod, frame gate) and starts the streamer with LD_LIBRARY_PATH=/tmp/otx/lib.
  For the open image: libimp must be OpenIMP (thingino-isp-open), the
  vendor ingenic-lib libimp cannot sit on the open driver.
- t9: the restored master image's /usr/bin/the streamer is the vendor flavour
  (USE_OPENIMP=0) and refuses the OpenIMP libimp ("libimp mismatch", exit
  78).  Built an OpenIMP-flavour the streamer from the image's own the streamer source
  (buildroot the streamer-custom copy, same USE_* set, USE_OPENIMP=1, linked
  against lib2/libimp.so): t40prod/bin-the streamer-oimp-t40; p5-the streamer.sh
  uploads it to /tmp/otx/the streamer.  Nothing in the streamer was changed.
- t9b (f03d0700, OpenIMP libimp + OpenIMP the streamer, fs_keepalive=1):
  framesource 0 (1920x1080 scaled) and 1 (640x360) both enabled, RTSP/HTTP
  up, local snapshot.jpg HTTP 200 (~44 kB), VIC IRQ exactly 20/s, the streamer
  RSS flat at ~3.4 MB, no kernel messages, 30 min clean (see
  t40prod/out/p5-t9b.log; the streamer left running afterwards).  Open item: the streamer reports "sensor fps:
  requested 20, driver holds 25/1" - sensor_g_attr returns the sensor
  module's 25/1, the stream runs at 20 fps.
- rmmod (2026-10-24, claude/t40-reload): FIXED and device-tested, 20 reload cycles plus 10 streamer
  restarts in one boot without oops or leak.  The first-unload oops was `private_wake_up_all` waking a
  NULL queue in the framesource remove (fs is now removed before the core); the probe objects, the
  tuning object, `/proc/jz/isp` and the sensor i2c client are released; lifted vmalloc areas are
  tracked and freed (per session for ADR/LCE/AE, the rest at exit).  The notes below are history.
- rmmod: 587502b1 splits the module exit into ten steps that can be run
  one by one with `echo exit N > /proc/tx_isp_t40_recovered` while kmsg
  streams (t40prod/p6-exit.sh); the step that takes the camera down is
  the one to look at.  Pending the next boot.
- YSP hypothesis for daylight: tisp_ysp_main_init is size independent
  (vmalloc 3432/420/146), so the "4K panic" is more likely a bus hang on
  YSP register writes while top40 bit 17 still gates the block (no kmsg
  at all in r22a/r24a, which fits a hang, not an oops).  Check the vendor
  order top40 -> ysp regs before enabling again.
- Second-start test (t40prod/p7-restart.sh, OpenIMP the streamer, keepalive=1):
  the streamer stop/start cycles die at a random cycle (c1: 3rd, c2: 5th, c3:
  2nd); the panic notifier (7c9f03a2) never fired, the watchdog reset the
  camera -> a hang, not an oops.  The flight recorder (fd83f4b7, 32 marks
  in the rmem tail, t40prod/panicdump.sh) shows for c3: stop of ch0/ch1
  completed (streamoff steps, release, tx-isp ioctls), the new start ran
  up to the ch1 stream-on, and the last mark is `isp_irq_handle irq=39`
  (ISP core IRQ) with nothing after it - the handler hangs on a register
  access right after the restart.  f337ddda marks every
  system_reg_read/write (offset) and the ISR entries to name the register.
- Panic/hang forensics on the Eufy: `panic_dump_phys=0xe9f0000` (module
  param, rmem tail): on panic the printk ring is copied there, every
  marked step writes into a ring at +0x100; after the reboot
  `t40prod/panicdump.sh out.txt` (mmap /dev/mem via t40prod/memdump) prints
  both.  `echo dumplog > /proc/tx_isp_t40_recovered` tests the copy.
- Flight recorder c5-c8c: the restart hung on a CSI or VIC register access
  at a random point of the CSI/VIC bring-up (CSI reg04/reg28, the first
  core IRQ after it, vic_core_s_stream).  CPM clock gates are identical
  while streaming and after a stop (p8-clk.sh), so no gated clock.  Root
  cause: frame channels 0..2 share vinum 0, but the direct stream path
  ran the CSI bring-up (reset, PHY) again for channel 1 while the sensor
  was already streaming, and the sensor was never stopped on streamoff -
  so a restart re-initialised CSI/VIC against live MIPI data.
  1284cb0e: CSI/VIC are started by the first channel of a vinum and
  stopped by the last one, and the sensor video stream is stopped before
  the last VIC stop (`t40_sensor_stream_off_on_stop=1`).  Result c10:
  15/15 the streamer stop/start cycles and 3/3 framesource idle off/on cycles
  (fs_keepalive=0) clean, snapshot 200 every time.  Second-start panic
  closed.  (906dacd0, CSI clocks re-armed after a slake, stays in: it is
  correct, just not the cause.)
- rmmod (p6 x1 on the same boot): exit steps 1-8 fine, step 10 (platform
  device unregister -> OEM remove callbacks) hangs the camera.  Split into
  one step per child device (fs, vin, vic, csi, core) with recorder marks.
- p6 x2 (03:57): exit step 10 again took the camera down, and this time it
  did not come back (no watchdog reset, no ping for >10 min) - the
  remove path can leave the SoC in a state the watchdog does not recover
  from; needs a power cycle.  Per-device bisect (steps 10-14 = fs, vin,
  vic, csi, core; 15 = parent/drivers; marks 0x80/0x81/0x91-0x95) is in
  62a1e4ea and waits for the next boot.  Until the remove path is
  understood: do not rmmod tx-isp-t40 on the Eufy; reboot instead.
Next: p6 per-device rmmod bisect (after power cycle); YSP order; sc830ai
tuning (daylight).

### Status 2026-10-13 04:15 (consolidated, end of the night shift)

Working on the Eufy T40XP (open driver `claude/t40-sc830ai` @ 62a1e4ea+,
module built against the Eufy 4.4.94 tree, `tests/check_ko_symbols.sh` OK):

    insmod tx-isp-t40.ko isp_clk=300000000 t40_quality_profile=0 \
        t40_generic_profile=1 sensor_full_width_override=3840 \
        sensor_full_height_override=2160 skip_tisp_deinit=1
    insmod sensor_sc830ai_t40.ko
    # streamer: OpenIMP libimp (lib2/libimp.so) + OpenIMP-flavour the streamer
    # (USE_OPENIMP=1); the Ingenic vendor libimp cannot sit on this driver.

- 4K and scaled 1080p/720p/360p frames, 20 fps, both frame channels (the streamer
  video0 1920x1080 + video1 640x360).
- the streamer 30 min soak clean (t9b), 15/15 stop/start cycles + 3/3 framesource
  idle off/on cycles clean (c10) after 1284cb0e.
- Forensics: panic log copy and flight recorder in the rmem tail
  (`panic_dump_phys=0xe9f0000`), reader `t40prod/panicdump.sh`.

Open:
1. rmmod: the core remove (exit step 10 = `tx_isp_core_remove`, run first
   because the child devices unregister in reverse order: core, fs, vin,
   vic, csi) hangs the camera; after p6 x2 the Eufy did not come back by
   watchdog (power cycle needed).  Core remove = isp_core_tuning_deinit,
   ispcore_slake_module (ISP clock/power teardown, only when core state
   >= 2), tx_isp_subdev_deinit (free_irq, iounmap, release mem),
   tisp_deinit (skipped).  Host-side prepared, untested: a per-device
   bisect (steps 10-14, recorder marks 0x80/0x81/0x91-0x97) and
   `t40_rmmod_skip_slake=1` (default on) that skips the slake in the core
   remove, since the slake tears down clocks the still-registered VIC/CSI
   removes touch afterwards.  Until tested: do not rmmod on the Eufy,
   reboot instead.  Also open: `gpio request fail 91` on a sensor
   restart (reset GPIO not freed on close, harmless).
2. YSP at 4K (panic in r22a/r24a): the vendor `tisp_main_init` runs every
   block init (ae, awb, blc, gib, lsc, dpc, adr, dmsc, gamma, defog, lce,
   mdns, af, ydns, cdns, sdns, ysp, bcsh, ccm, clm, hldc, gsm, tstp) and
   then writes the top register, all before `tiziano_enable`.  Our block
   init needs the tuning blob (`tparamsN`); without a bin file
   (`/usr/share/sensor/gc4653-t40.bin` missing on the Eufy, load ret=-2)
   it is skipped at tisp_main_init and re-run from the frame-done work,
   i.e. while the ISP is already processing 4K frames - the likely YSP
   crash.  Night-safe experiment: `t40_tuning_bin_path=/etc/sensor/sc830ai-t40.bin`
   (the vendor IQ bin is on the camera) so the blob exists and the block
   init runs pre-stream; then `enable_ysp=1` at 720p first, then 4K.
3. Daylight (image quality, needs a bright scene, metrics only, collage
   per the pictures rule): with the sc830ai bin loaded compare BLC/LSC/
   CCM/gamma against the vendor stream (A/B method, same scene); find the
   profile >= 1 black (top40 bit 2 and the GC4653 literal tables); ircut
   on, AWB/CCM check; 50 Hz antiflicker is a no-op on T40 for now.
4. sc3338 (CSI1) counter-check oops - low priority.

### 2026-10-13 image quality on the Eufy (noise, bitrate, tuning bin)

Metrics only (1080p JPEG snapshots of the streamer, static scene, 5 frames, no
pictures kept; temporal std = median per-pixel std over frames, Y 0..255):

| variant (all `t40_quality_profile=0` unless noted)            | temporal std Y | stream (CBR 3000, max_qp 51) |
|-----------------------------------------------------------------|---------------:|------------------------------|
| generic profile, no bin (previous recommendation)               | 30-32          | 10-12 Mbit/s at max_qp 45 (28 Mbit/s while AE dark) |
| generic profile + `t40_dns_ev_boost` 0.13 .. 8 (x65536)        | 30-32 (no change) | -                          |
| sc830ai bin, MDNS/YDNS/SDNS only (generic off)                  | 39, chroma 0   | 3.5                          |
| bin + generic profile (boot with bin1/bin2)                     | 92 % white or bimodal, AE stuck at max gain 22-25 | - |
| bin + `t40_quality_profile=1 t40_force_bypass=0x20000`          | 36 (picture ok, stable) | 3.0               |
| same + `t40_force_active=0x44000` (YDNS+SDNS forced on)         | 36-38, boost 0.5..1 worse | 2.9             |
| generic + `t40_quality_top40_override=0x7ffba8ff` (CCM/gamma/YDNS/SDNS HW on, no bin) | black (Y 0.6) | -   |
| generic + top40 override `0x7ffbaeff` (YDNS/SDNS on, no bin)     | black (Y 0.6) | -                            |

Findings:
- Bitrate: the streamer asked for CBR 3000 but the encoder sat at QP 45 (the
  `video0.max_qp = 45` default; slice QP read from the stream) and still
  produced 10-28 Mbit/s because the picture is noise dominated.  With
  `video0.max_qp = 51` the same stream holds 2.8-3.5 Mbit/s.  OpenIMP CBR
  itself is fine (devtest 4K at 2000 kbps: 2.15 Mbit/s).  The noise is the root
  cause; max_qp 51 is the config fix.
- The generic profile leaves the top40 bypass bits of CCM (9), gamma (10),
  YDNS (14) and SDNS (18) set (`0x7fffeeff`): those blocks are initialised
  but bypassed in hardware.  Clearing the bits without tuning data gives a
  black image, because the block parameter tables are empty without a bin.
  Only MDNS (bit 8) is active in the generic profile, which is why
  `dns_gain_ev` changes show no effect.
- The sc830ai bin loads (`ret=0`, 204800 bytes).  Its gates mark YDNS (14),
  SDNS (18) and GIB (5) as bypass (check whether the flags are read from the
  right offset), and with profile 0 + generic the BLC/LSC/GIB tables read from
  the bin give a mostly white picture (92 % of pixels >= 254, AE walking down
  one index per ~13 s from gain index 25).  That points to the bin AE/BLC
  sections being read with the wrong layout; unresolved.
- Forcing YDNS/SDNS on with the bin parameters did not reduce the temporal
  noise (36 vs 36).  The remaining noise is therefore probably upstream of
  the Y denoisers (raw level; compare a GetRaw dump: devtest mask 2000
  with `T40D_RAW_DIR`).
- New opt-in module parameters (all default 0, no behaviour change):
  `t40_dns_ev_boost` (16.16 log2 offset on the DNS gain EV, runtime),
  `t40_force_bypass` / `t40_force_active` (top40 bits forced after the bin
  gates; bit 17 keeps YSP off while the bin gates would enable it).
- Best stable set with a bin (boot 7, 5+ min, picture ok, no oops):
  `isp_clk=300000000 t40_quality_profile=1 t40_force_bypass=0x20000
  sensor_full_width_override=3840 sensor_full_height_override=2160
  skip_tisp_deinit=1 t40_tuning_bin_path=/etc/sensor/sc830ai-t40.bin`.
  Do not use `enable_ysp` or the WDR/ADR-linear/defog/DPC paths on a boot
  without a valid bin (NULL comb buffers).

### Daylight plan (image quality)
1. Load the sc830ai tuning (`t40_tuning_bin_path=/etc/sensor/sc830ai-t40.bin`)
   and compare BLC/LSC/CCM/gamma against the vendor stream with the A/B
   method (same scene, metrics only).
2. Find the profile >= 1 black (top40 bit 2 and the GC4653 literal tables).
3. Daylight colour check: ircut on, AWB/CCM, then YSP (720p, then 4K).

### Next steps (host side first)

1. Morning, after the power cycle: p6 per-device rmmod bisect with
   `t40_rmmod_skip_slake=1` first, then =0 to confirm the slake.
2. YSP order experiment (item 2 above), then the daylight plan.
3. Open image: `t40prod/build-img-open2.sh` already builds the streamer with
   USE_OPENIMP=1 (BR2_PACKAGE_OPENIMP=y via BR2_PACKAGE_THINGINO_ISP_OPEN);
   nothing to change there.

### Previous test plan (superseded)

1. Baseline ch0 1280x720 with `t40_profile_direct_vic_feed=1` (VIC frame
   MDMA to DDR, bypassing core/MSCA): proves CSI/VIC/sensor data flow and
   gives a raw picture to check the MIPI setup (2 lanes, 1080 Mbps, boot 4).
2. Same without the profile, read the bounded diag (`proc_live_reads=1`,
   `head -c` on the frame-done/MSCA sections) right after `StartRecvPic`:
   MSCA status/FIFO counters (0x16008, 0x1616c/0x16184 banks), core
   status0/err bits (0x1000 + err 0x20 appear once per frame), tisp event
   thread counters, `regtrace_irq_frame_done_*` counters.
3. Vendor reference on the same boot image is not possible (vendor rmmod
   oopses); take the vendor MSCA/core register values from a separate
   vendor boot (`/proc/jz/isp` or the ISP register dump tool) and diff them
   against the open driver's `regtrace_core_write` trace for 3840x2160.
4. Reproduce the 1920x1080 panic with the console log captured (serial or
   `netconsole`), it is the only kernel-fatal signature seen on this device.
5. rmmod after a run: the two mis-resolved calls in `ispcore_slake_module`
   are fixed on paper (68ac89d0) but untested; check with
   `dmesg | grep -c "Unable to handle"`.

## Eufy sc830ai: best tested picture (2026-10-13)

Device-tested on the Eufy T40XP (sc830ai, 4K sensor, 1280x720 capture, same-age frames). Each step was measured in one boot, numbers only:

| Step | Y (centre) | neighbour diff | U / V |
|---|---|---|---|
| morning baseline (profile 1 + bin) | 32.6 | 22.1 | 157 / 156 |
| + stale-TOP-replay fix + fixpoint/AE-writer repair (this commit) | 19.8 | 15.9 | 144 / 144 |
| + `enable_dmsc_static=1 dmsc_stock_current_overlay=1` | 29.7 | 12.3 | 130 / 132 |
| + `frame_3a_interval=3` | 125 | 23.5 | 131 / 131 |
| + `t40_force_active=0x4000` (YDNS) | 145 | 23.0 | 131 / 131 |
| `t40_force_active=0x6020` (YDNS + DMSC + GIB) instead | 137 | 8.9 | 131 / 131 |
| + Bayer phase BGGR: `tisp_main_init_reg88_override=0x101 core_bayer_reg8_value=0x10001` | 117 (frame) | 7.0 | 120 / 136 |

The Bayer step is the colour fix. The driver defaulted to the GRBG phase of the GC4653 bring-up, while the sc830ai delivers BGGR (`0x13300088` = `0x101`, as in the vendor stack). With the wrong phase the white-balance gains landed on the wrong colours, giving a grey picture with a magenta cast in shadows and clipped highlights. With BGGR the colours are natural. The frame white balance then started from GRBG-era gains and converged too slowly (warm picture). `frame_awb_bggr_fast=1` seeds the measured sc830ai daylight gains R 1060 / B 2640 on the first BGGR frame and then trims proportionally inside the existing deadband: full-frame U/V 128.1/130.7, neighbour diff 6.4.

Rejected:
- `t40_force_bypass=0x20001` (BLC off): U/V rise to 172.
- `dmsc_stock_high_gain_overlay=1`: U/V rise to 142.
- `enable_clm=1`: no change.
- `t40_quality_top40_override=0x7FD0000D` (vendor TOP word): black frame. Bit 18 (SDNS) is the cause, because its initialiser is not run.

Recommended insmod line (since the defaults patch the best settings are the driver defaults):

    insmod tx-isp-t40.ko isp_clk=300000000

(Since claude/t40-bind-fix the IQ bin is derived from the registered sensor:
IMP_ISP_SetDefaultBinPath path > `t40_tuning_bin_path=` > `/etc/sensor/<name>-t40.bin`
> the old gc4653 fallback; before that the parameter had to be given, otherwise
`tiziano param load ... gc4653-t40.bin ret=-2` and the pipeline ran untuned.)

All former tuning parameters (t40_quality_profile=1, t40_force_bypass=0x20000, t40_force_active=0x6020, enable_dmsc_static, dmsc_stock_current_overlay, frame_3a_interval=3, frame_3a_slide_window, frame_awb_bggr_fast, t40_gamma_from_bin) are now defaults and stay overridable. The BGGR white-balance seed is only applied when the sensor runs 3840x2160 (the calibrated sc830ai); the sensor frame size is taken from the sensor instead of sensor_full_*_override. Device check on the Eufy: same picture as the old long line (frame Y 184, neighbour diff 3.15, TOP 0x7FFF08D8).

The Bayer phase is now taken from the sensor media-bus format (sc830ai SBGGR10 -> `0x13300088` = `0x101`), so no override is needed; `tisp_main_init_reg88_override` / `core_bayer_reg8_value` still work for experiments. Without overrides: full-frame U/V 129.9/128.0, neighbour diff 6.0.

Native 4K (3840x2160, scaler off): the frame-3A sampler mapped a fixed 32 MiB window and silently skipped frames whose planes left it (7 of 7 samples missed, frame Y 77, dark). `frame_3a_slide_window=1` remaps per frame: 0 misses, frame Y 153, midtones neutral (U/V +2.5/+0.6).

Gamma: the driver used a hard-coded GC4653 curve whose first 11 nodes are zero, which crushed the shadows. `t40_gamma_from_bin=1` uses the sc830ai bin curve (nodes 0/144/1070/2879/4095): at 4K the shadow share drops from 47 % to 21 % of the samples, frame Y 134 -> 158, neighbour diff 4.8 -> 3.9.

Still open: white-balance fine tuning; YSP (sharpness) is still forced off, and day/night has not been checked on this baseline. Analyses and reviews by external helpers are in the session notes.

## Eufy sc830ai: integration state 2026-10-15 (`claude/t40-integration-1015`)

Device run on the board: test application 24 results / 0 failures with the defaults and with `t40_gates_oem_offset=1 t40_gates_day_blc=1`; 10 minutes of streaming without an oops.

Corrections to the notes above:
- The "bit 18 (SDNS)" explanation of the black frame with the vendor TOP word is withdrawn. SDNS with the bin runs fine and its registers equal the vendor values; that override also released DPC, ADR, defog, CDNS and LCE without an init.
- The gate pass read the bin's bypass flags at +0x20 (the WDR set). The OEM uses +0x00 for a linear sensor and +0x20 only in WDR mode (`tisp_main_init`); `t40_gates_oem_offset=1` does the same. In the sc830ai bin the linear set enables YDNS, SDNS, GIB and YSP and bypasses BLC.
- The "YSP panic" was a NULL dereference: without a tuning bin the YSP init failed before its tables were set up, and the per-frame refresh still ran. An init guard now blocks every refresh until the init succeeded; `t40_ysp_on=1` lets the bin gates enable YSP.

TOP 0x40 bit map (from the OEM update callbacks): 0 BLC, 1 LSC, 2 WBG/AWB stage, 3 WDR, 4 DPC, 5 GIB, 6 AWB stage, 7 ADR, 8 MDNS, 9 CCM, 10 gamma, 11 defog, 13 DMSC, 14 YDNS, 15 BCSH, 16 CLM, 17 YSP, 18 SDNS, 19 CDNS, 21 LCE; bit set = bypass. Vendor stack on the board in daylight: `0x7FD9004D`.

Colour: with the OEM gate offset BLC is bypassed and the black level is left to GIB, which sits behind the white-balance gains, so the pedestal is amplified per channel before it is subtracted (green/yellow cast, violet shadows). `t40_gates_day_blc=1` keeps BLC active in day mode with the GIB black level `t40_gates_day_gib_blc` (default 0); night keeps the bin mask. Colour-saturation index on the board: 7.9 (day_blc) against 20 (offset only) and 8..9 (defaults).

Opt-in vendor blocks: `enable_cdns` (CDNS, plain C in `tx_isp_t40_cdns.h`; the vendor stack keeps it bypassed on the Eufy sc830ai), `t40_ysp_on` (YSP), `t40_adr_on` (ADR, needs `t40_gates_oem_offset=1`; the per-frame part runs once the core interrupt dispatches IRQ 9 / event 2). Desk notes: `audit/chroma_gap.md`, `audit/ysp_gap.md`, `audit/adr_gap.md`.

Recommended line for colour work on this board:

    insmod tx-isp-t40.ko isp_clk=300000000 t40_tuning_bin_path=/etc/sensor/sc830ai-t40.bin t40_gates_oem_offset=1 t40_gates_day_blc=1

## Substream, NV12 layout and AutoZoom (2026-10-18)

- Output 1 (substream) delivers frames: the interrupt handler pops MSCA output 1 like the OEM ISR (`t40_isr_ch1_direct`, default 1). Device-tested on the T40XP / sc830ai board: 1080p + 360p/720p 226/226 frames in 15 s, 10 min at about 20 fps per stream, no oops.
- `t40_nv12_height_align=0` (auto): chroma plane at width*ALIGN(height,16) when the queued buffer is large enough, else width*height (older libraries). Removes the green bottom strip and the chroma shift on small outputs.
- AutoZoom (CID 0x08000077): per-output source window in the MSCA, applied live. The window must lie inside the sensor and be at least as large as the output (no upscale in the MSCA); invalid requests return `-EINVAL`. Second sensor refused. Parameters/counters: `t40_az_live_max_w/h`, `t40_az_{live,deferred,stored,failed}`. Device-tested on the same board (outputs up to 2560x1440 zoomed, 4K only full window); ch1/ch2 zoom not device-proven.
- Open: the stop path (`Tzn_Msca_Work_en`) mask is not OEM-exact (harmless in tests); `tisp_gib_ae_write_dgain` still returns -1 per frame (GIB AE dgain not applied).

## AWB statistics and AE limits (2026-10-19)

- Tuning control `0x8000011` (AWB statistics) fills a kernel-allocated block
  from the main/sec AWB tables as the OEM does; the plane is zero until the
  first AWB frame. Older builds oopsed in `tisp_awb_get_zone` here.
- The AE clamps its maximum/minimum integration time and gains against the
  sensor attributes like the OEM. A frame-rate request before the first
  delivered frame is held and sent with the first exposure update. The read-only
  module parameter `t40_ae_limits` shows the limits the AE uses.
- Known, not changed: second-sensor `ae_cache` stride, `fs_work` dispatch and the
  sensor-control stubs that still hard-code GC4653 values.

## Eufy sc830ai: picture quality against the vendor stack (2026-10-24, `claude/t40-quality`)

A/B on the Eufy .184 (same scene, basement lamp 3649 K, `audit/ab-t41/measure.sh`, data in the session's
`audit/ab-t41/COMPARE.md`): the agg43c open image was orange (R/G 1.85, no AWB), 45 % softer, the AE 5-10x slower and the
night picture 69 % darker than the vendor. Findings and fixes, all device-tested with a test module built from this branch
(0 oops in 5 runs, 50 min stream):

- `enable_core_ops_cb` now defaults to 1. Only the real ops tables hand the OEM core ISR to the AWB statistics interrupt,
  and only that path runs `tisp_awb_main_process` -> the translated vendor AWB (`t40_vawb`) per frame. The image had
  `t40_vawb_frames=0`; the 10-19/20 basement runs all carried `=1` on the insmod line. With it: R/G 1.03, B/G 1.00,
  grey cabinet/tiles channel deviation 12 %/10 % (vendor 12 %/11 %), saturation 53 (vendor 51).
- The OEM ISR also pushes event 1 to the lifted OEM AE, which oopses (`tisp_ae_long_tune2`, BadVA 0x1774); it is now
  behind `t40_oem_ae` (default 0). (2026-10-26: the lifted OEM AE and `t40_oem_ae` are removed, see below.) The ISR delivers frames itself (leg A, hard IRQ), so the frame-3A sampler that only
  lived in the FIFO frame-done work item never ran; the tick moved to `regtrace_irq_frame_done_send` with its own work
  item (`frame_3a_work_runs`).
- AE: integration ceiling from the sensor attribute (`ae_soft_max_it_from_sensor`, sc830ai boot 4 = 2241), target
  110 -> 118 (vendor day luma 122 at the same EV; ours now 127), two gain steps per sample far from target, and gain
  bands (`9 %` analog / `5 %` ISP dgain of the target) so a 1.17x gain step cannot limit-cycle inside the 4-level
  deadband (it did: frames alternating 113/124). Settle after a light step < 1 s (vendor 1.5 s).
- ISP digital gain stage (`ae_isp_dgain_max`, Q10, default 4096 = 4x like the vendor's AeIspDGain at night): after
  integration time and sensor analog gain (the sc830ai ends at 32x), the AE raises the GIB final gain through the OEM
  entry `tisp_gib_ae_write_dgain` (0x8000/0x8004 + latch 0x8040; checked by devmem: 0x0445 -> 0x1116 lifts the night
  luma 24.6 -> 64.0). Night luma 66 vs vendor 79 (was 24), light step to 100 holds 124 (vendor 105, was 63).
- The per-frame tuning follow (DNS/YSP gain refresh, DMSC, LSC gain/CT, manual WBG, CCM, BCSH saturation) is shared by
  both frame delivery paths (it used to live only in the FIFO work item, so with the OEM ISR nothing of it ran), and
  the BCSH saturation is re-applied on a day/night change (it stayed at the night value after the return).
- `t40_ysp_on` defaults to 1: the bin gates enable YSP like the vendor TOP word (TOP 0x7FF9089D, init ok, 0 oops at
  4K). Day edge energy 2.89 -> 3.76 (vendor 5.23); the remaining sharpness gap is open.
- The open timps stops the framesource without a viewer (`framesource.keepalive=0`), so the ISP idles at 0 IRQ/s and the
  3A only runs in snapshot bursts; the A/B runs therefore keep a stream consumer open. Not a driver difference.
- Frame 3A without a main-stream consumer (2026-10-25): the sampler took only channel-0 completions, so a sub-stream-only
  consumer (ch1 RTSP, 20 s: `frame_3a_samples` 834 -> 834) left the AE frozen at the last exposure. After an IR-off day
  switch a streamer then read the IR-lit exposure for seconds (timps: 554 after 8 s, 22117 14 s later) and kept a
  wrong "day". Channel 1 now feeds the same loop when channel 0 has not completed a frame for
  `frame_3a_ch1_idle_ms` (default 300, 0 = old behaviour; `frame_3a_ch1_samples` counts them). Device (.184, dark, ch1
  only, IR off): EV 3375 -> 286830 (max) in ~3 s, back to 3375 ~4 s after the streamer returned to night (stock: frozen).

## Eufy sc830ai: defog, LCE, DPC and the GIB gain follow (2026-10-24, `claude/t40-quality2`)

The vendor's TOP word on this camera is `0x7FD9004D` in daylight; ours was `0x7FF9089D`. The difference is four blocks the
sc830ai linear bank enables and the driver never released: DPC (bit 4), ADR (7), defog (11) and LCE (21). The recovered
defog lift could not have worked (its init calls `tisp_defog_main_interrupt_static(10, &isr)` where the OEM calls
`system_irq_func_set(10, isr)`, and `tisp_event_set_cb` with one argument), the LCE lift is fragmentary. Without defog and
LCE the black level sits higher and the contrast is compressed, which is exactly the day/night gap measured against the
vendor (`audit/ab-t41/COMPARE.md`, open184d).

- `t40_defog_on`, `t40_lce_on`, `t40_dpc_on` (default 0, need `t40_gates_oem_offset=1`): literal OEM chains generated by
  `tools/gen_t40_defog_lit.py`, `gen_t40_lce_lit.py`, `gen_t40_dpc_lit.py` from the Eufy production module (function
  sizes identical with the 1.3.1 `libt40-firmware.a`), same scheme as the ADR chain (`tx_isp_t40_adr_lit.inc`): private
  OEM objects with the OEM `.data` initial bytes, one emulated MIPS stack per entry context, every `jalr` through a
  dispatcher on the register value. Init runs in the block init after ADR; the TOP bit is cleared only when the init
  returned 0. Defog hooks IRQ 10 / event 4, LCE IRQ 8 / event 0x10 (counters `dfglit_*`, `lcelit_*`, `dpclit_*`,
  `*_bad_call` must stay 0). Day/night: `tisp_*_dn_params_refresh` from the day/night pipeline; module exit: the OEM
  deinit after the event threads stopped.
- The sensor gain update (`regtrace_gc4653_tuning_again_update`) is the OEM `tisp_main_long_tgain/ev_update` fan-out
  for these blocks: `tisp_lce_tgain_update(0, total)`, `tisp_dpc_refresh(0, total)` with the 16.16 log2 total gain,
  `tisp_defog_ev_update(0, -, IT x gain Q10)` (the stored value >> 10 equals the vendor's `ExposureValue`), and, with the
  OEM GIB flow, `tisp_gib_a_gian_update(0, again)` so the GIB black level follows the gain tables of the bin (it stayed at
  the init interpolation before: night Y p1 16 against the vendor's 7).
- Device (Eufy .184, test module against the agg43d kernel, `measure.sh open184e`, defog + LCE on): day contrast std
  53.3 (vendor 50.8, before 47.0), day edge energy 4.69 (vendor 5.23, before 3.76), day black p1 17 (vendor 17, before
  26); night luma 82.3 (vendor 78.7, before 65.9), night std 36.6 (35.6), night edge 3.00 (2.44); grey balance 7 / 4 %
  (vendor 12 / 11 %); 0 oops, ISR and process once per frame. With all four chains (`open184f`, defaults since
  cf49b97c): TOP `0x7FD9000D` (vendor `0x7FD9004D`, bit 6 = AWB stage 2 differs), day edge 5.02 / luma 120 / std 49.6 /
  p1 15, night luma 88 / std 37.1 / edge 2.8 / p1 20 (vendor 7), grey balance 1.5 / 0.9 %.
- AE gain ceiling from the sensor attribute (`ae_max_again_from_sensor`, default 1; `t40_ae_max_again_index_eff`
  read-only): the gain ladder (`regtrace_gc4653_again_log2_gain`) is the GC4653 one, index 25 = 76x, while the sc830ai
  attribute says max_again 5.0 log2 (32x). The sensor's alloc_again clamped indices 21..25 silently, but AeAGain and
  every gain-indexed table saw 76x at night. The ceiling is now the highest ladder step within the attribute's
  max_again (index 20 on the sc830ai), the ISP digital gain stage starts there like the OEM `tisp_ae_main_s_max_again`.
  Night re-test pending (candidate for the night black level p1 20 against the vendor's 7).
- Open: colour saturation after the night -> day return (HSV S 15 against the vendor's 51, also before this branch;
  `enable_bcsh=Y`), TOP bit 6.

## Eufy sc830ai: AE EV fan-out, user AE caps, ratios (2026-10-24, `claude/t40-quality3`)

- The OEM AE fans its EV (IT x gain, Q10; `>> 10` = the vendor's ExposureValue) out to defog, ADR, CCM and BCSH on
  every change (`tisp_main_long_ev_update`) and its total gain to ADR (`tisp_adr_tgain_update`). The open driver fed
  only defog (quality2); `ccm_ev` / `bcsh_ev` were module parameters frozen at 400 and the ADR private state
  (`adr_ev_top`, `adr_tgain_top`) was never written. `regtrace_t40_ev_fanout()` (per frame in the tuning follow and
  on every sensor gain update) now feeds all four; `t40_ev_now` shows the value, `t40_ev_follow=0` keeps the frozen
  CCM/BCSH values for A/B. Effects: the CCM re-init after a night -> day return no longer runs at a stale EV (HSV S 15
  against the vendor's 51 before), ADR follows EV/gain at night.
- `frame_3a_target` default 122 (vendor day luma 122 at the same EV; ours was 120 at 118 with LCE).
- User AE limits (`IMP_ISP_Tuning_SetAeExprInfo`: max integration time in lines or us, max analog gain and max ISP
  digital gain x1024, each when its mode is 1) and `AeTargetComp` (target x comp/128 when `AeTargetCompEn`) now reach
  the open frame AE; read-only `ae_user_max_it`, `ae_user_max_again_x1024`, `ae_user_max_isp_dgain_x1024`,
  `ae_target_comp`. `GetAeScenceAttr` reports the open AE's compensation, last luma and effective target. HLC/BLC
  strengths are still stored only.
- `SetModule_Ratio`: DRC -> OEM `tisp_s_drc_ratio` translated into `tx_isp_t40_adr_lit.inc` (private wal parameters,
  top-para refresh); Sinter -> after the hand-translated `tisp_s_sdns_ratio` scaled the bank, the literal SDNS chain
  reloads its tables and replays the live gain. Temper (MDNS), DPC and defog ratios are cached only.

## Client crash recovery: framechan release (2026-10-24, `claude/t40-stability`)

`regtrace_framechan_release` (misc fops of `/dev/framechanN`, also the v4l2 private file) used to only clear `private_data`. The OEM `frame_channel_release` streams off and frees the vb2 queue when the channel state is 4 (streaming). Without that, a client that died while streaming left the streaming flag (+0x244) set and every later STREAMON returned -EBUSY until reboot.
The driver now remembers per channel which file started the stream (`regtrace_framechan_stream_owner`) and which file owns the buffer set (`regtrace_framechan_buf_owner`, REQBUFS with count > 0). Closing that file issues STREAMOFF through the normal ioctl path and frees the repaired buffers (= REQBUFS 0). A failed streamoff still clears the stale flag (buffers kept, the next REQBUFS frees them). Closing any other fd on the channel does not stop a running stream (the OEM stops on any close).
Device test on the Eufy: kill -9 / SIGSEGV of the streamer, restart: video back (snapshot 200), no -EBUSY; stock ko without the fix: snapshot 503.

## Eufy sc830ai: night black level (2026-10-24, `claude/t40-quality4`)

The OEM `tisp_main_long_tgain_update` hands GIB (`tisp_gib_a_gian_update`) the total gain: the vendor's TotalGainDb
includes the ISP digital gain (458752 = 7.0 log2 at night = 32x sensor x 4x ISP). The bin's five GIB black-level
tables are interpolated by that gain (`tisp_gib_interp_by_gain`, integer part = node). The quality2 follow passed the
analog gain only (5.0 log2 at night), so the black level stayed at node 5 while the 4x stage ran, and the remainder
became a pedestal in the night picture (Y p1 12..20 against the vendor's 7). The sensor gain update now passes the
total gain (`regtrace_gc4653_tuning_again_update`: `tisp_gib_a_gian_update(0, total)`); day is unchanged because the
ISP digital gain is 1x there. `SetModule_Ratio` defog -> literal `tisp_s_defog_ratio`; Temper remains cached only.

## CSC gamut and Temper ratio (2026-10-24, `claude/t40-csc-temper`)

- Set/GetISPCSCAttr (CID 0x8000096): OEM `tisp_set_csc_attr` = `tisp_csc_set_attr` (registers 0xd010/14/18/20/30
  + 0x80 per vinum, state 92 bytes; libimp exchanges 64) + `tisp_bcsh_csc_attr`. The second call is the visible part:
  the BCSH block does the ch0 RGB -> YUV and `*ctx[27]` (0 BT601 full, 1 BT601 limited, 2 BT709 full, 3 BT709 limited,
  4 user tables) selects the matrix/offset/clip set in `tisp_bcsh_params_refresh` (bank + 0x11e38). Implemented in
  `t40_csc_bcsh_apply()` (vinum 0, under the running-mode lock): gamut byte, busy flag, params refresh, EV/CT update.
  `bcsh_mode` (module parameter, OEM init value 2) follows the gamut so a day/night BCSH re-init keeps it.
  Gamut 4 and the BCSH user CCM (`*ctx[28..30]`, enable byte `*ctx[35]`): the OEM refresh copies only the first word
  of each user table (offset, clips, M, Minv, CCM; the rest stays from the previous gamut / the bank). `bcsh_user_full`
  (module parameter, default 1, beyond stock) takes the whole tables; 0 = OEM, bit-exact (c_chains_host bcsh).
  `tisp_set_csc_version` is literal now (tables for standards 0..3). Device 2026-10-24: BCSH 0x11000..0x11014 follow
  the gamut, 0xd010.. read back the BT709-full init values after every write and 0xd000 reads 0; the ch0 picture is
  unchanged between gamuts (open, vendor register dump needed).
- Module_Ratio temper (index 1): `regtrace_mdns_ratio_lit()` = OEM `tisp_s_mdns_ratio` (1.3.1 0x5f540). Bank nodes at
  tparamsN[0] + 0x10000 + {4440, 4925, 4451, 4297, 4363, 4198, 4209} (WDR: {5805, 5937, 5816, 5739, 5772, 5706,
  5717}) x 11 are scaled into par through comb[9, 21, 10, 3, 6, 0, 1]: ratio <= 128 -> v * r >> 7, above ->
  v + ((r - 128) * (cap - v) >> 7), cap 230 for comb 9/21 and 250 otherwise; then `tisp_mdns_refresh(0, gain_old)`.
  Also called after the DN MDNS reload (OEM `tisp_mdns_dn_params_refresh` tail). Only the DPC ratio is still cached.
  Device: 28-35 MDNS registers change per ratio step (0/128/255); temporal noise 1.16 / 0.82 / 1.08.

## DMSC day/night (2026-10-24, `t40_dmsc_follow`)
- Default profile 1: DMSC (0xa000..0xa27c) uses the literal OEM chain at night only (active bank, total gain incl. ISP
  digital gain, re-interpolated per frame). The day block (static table + OEM init) is saved on the switch and written
  back with the trigger 0xa19c on the return (`t40_dmsc_day_restores` counts the restores). Host check:
  `tests/t40/dmsc_night_host` (bit-exact against the vendor night dump). `t40_dmsc_follow=0` = old static DMSC.
- Since 2026-10-25 `t40_dmsc_day_follow=1` (default): the literal chain runs in day too (vendor behaviour; .184 day
  edge energy +17 %, chroma unchanged). 0 = static day block, saved/restored around the night as above.

## Day/night TOP bit 6 (AWB1, 2026-10-25, `t40_dn_keep_awb1`)
- The night bank bypasses AWB1 (TOP bit 6). Re-enabling it on a running pipe broke the day colour in about half of the
  night->day switches (grey, green/magenta hues; registers unchanged, healed only by a later TOP change). Default 1
  keeps AWB1 at the day-bank state at night; night stays monochrome through BCSH saturation 0. 0 = follow the bank.

## Tuning controls and guards of the lifted bodies (2026-10-24, evening)

- **Guards.** Lifted OEM bodies that overran a small stack slot or dereferenced a NULL base oopsed the stock open module. Fixed: `SetModuleControl` (`tisp_lce_clear_stat_ram` / `tisp_lce_top_change_state` without LCE tool parameters), `SetMask`/`GetMask` on vinum 0, `SetWdrOutputMode` (a stored flag on the linear sensor, as the vendor), `GetSensorFPS`/`SetSensorFPS` read-back, `SetScalerLv` (rewritten from the OEM function). `Get/SetISPCSCAttr` and `Get/SetCCMAttr` run on the literal OEM state; the CSC wire block is 64 bytes. `t40_csc_unsafe=1` restores the old 92-byte lifted path (not for use).
- **New state section.** The lift reaches the OEM `.bss` through `&isp_memopt + N` offsets, so new `.bss`/`.data` objects shift what those accesses hit (the frames stopped once). All new state (CCM, CSC, gamma, flip) is in its own section `.t40c2`; the sizes of `.bss`, `.data` and `.rodata` equal the base. `/sys/module/tx_isp_t40/parameters/t40_c2_state` shows it.
- **Sensor flip.** The vendor core acts on HVFLIP modes 4..8 only when the sensor module has a vertical-flip handler; the vendor sc830ai module has none, so the vendor never flips this sensor. The open driver can flip through the sensor register profile (`0x3221`) applied from the HVFLIP ioctl, but it is off by default (`t40_c2_flip=0`, like the vendor); with it on the picture did not change on this sensor. `t40_c2_stray=1` restores a stray store of the lifted CSC standard (bisect only).
- **GetGamma.** Answers `{mode 0, 129 nodes}` from the last programmed LUT (production uses the soft-gamma writer, not the lifted gamma context).
- **Probe parameters.** `t40_ev_follow=0` switches the AE EV fan-out off (A/B), `t40_adr_ev_shift` scales the EV fed to the ADR chain (diagnosis only, 0 = OEM unit).
- **Reload.** `t40_rmmod_skip_slake=1` stays the default (the slake step is skipped; the core remove passed every time); the unload order is frame source first, then core.
- **Clock teardown at rmmod (#152).** `private_clk_prepare_enable` counts every successful enable per clock name, `private_clk_disable_unprepare` takes it back; `tx_isp_t40_core_exit` gates what is still counted (`gate_isp`, `div_isp`, `gate_csi`, `gate_ahb0`, a sensor MCLK that was left on) after the last child remove. OEM: `tx_isp_subdev_deinit -> isp_subdev_release_clks` does `clk_disable_unprepare` + `devm_clk_put` inside the core remove (core first); the open driver defers the gate because the CSI remove still writes registers behind the ISP clocks and the slake variant of this (early gating) is what hung the Eufy. The sensor modules stop their own MCLK in their remove (CIM CDR stop bit 27), as on stock. Check: `/proc/jz/clock/clocks` counts of `gate_isp`/`div_isp`/`gate_csi` are back to the value before the load, CLKGR (0x10000020) bits 23/24 set after the rmmod; loop script `tests/t40_qemu/clk_reload_cycle.sh`.

## Lifted OEM AE removed (2026-10-26, `claude/t40-drop-oem-ae`)

- Exposure is owned by the driver's frame-3A AE (`enable_frame_3a`, `ae_soft_*`, `enable_ae_sensor_apply`). The lifted
  OEM AE process (`tisp_ae_main_process` event 1, `tisp_ae_sec_process` event 24) and its algorithm closure are removed
  together with `t40_oem_ae`; the OEM AE init still programs the AE statistics hardware, the AE statistics and
  histogram interrupts still fill `pstMainAeOri` (histogram, zones) for the tuning getters and the AE statistics API.
- `tisp_ae_g_luma`, `tisp_ae_{main,sec}_get_antiflicker_step` and `tisp_ae_g_comp` work on `pstMainAeOri` /
  `pstSecAeOri` (no `%hi(.bss)` asm).
- Method for further dead-code removal: link listing with `--print-gc-sections`, delete only bodies the listing drops
  and no remaining source line references (gcc inlines some gc'd bodies into live callers), nm/size before and after.

## Static checks for lift artefacts (2026-10-29, `claude/issue-139`)

- `tools/t40_uninit_gcc.sh` (after a `SOC=t40` build, `KDIR=` the kernel build dir): the recovered file once more
  with `-Wuninitialized -Wmaybe-uninitialized -O2` instead of `-w`.
- `python3 tools/t40_uninit_scan.py [--ioctl]`: STORE (store through a never-assigned local pointer or pointer frame
  slot), LEAK/ZERO (copy to user space from a never-written slot), ARITY (call through a cast with fewer arguments than
  the prototype: the callee reads stale registers), with the call depth from the control/tuning ioctl handlers.
- Fixed with it: tuning-node AE manual set (0x20007405) with `tisp_ae_{main,sec}_manual_set`, Get/SetFrameDrop,
  SwitchBin, `/dev/tisp` release. SwitchBin still reloads the configured bin, not `bname` (the open loader takes no
  path), and does not re-initialise the pipeline top (the lifted `tisp_tstp_main_init` oopses when run a second
  time; follow-up).

## Testing in QEMU

The modules can be loaded, unloaded and exercised without a camera in the `ingenic-t40` machine of the [gtxaspec/qemu](https://github.com/gtxaspec/qemu) `ingenic-txx` branch (boots the thingino image to a shell with the sc830ai sensor model, all modules load; it reproduced the `rmmod` oops and the frame-slot index crash of the ISR (both fixed) and is the bench for the reload tests). It is a crash-test bench, not a picture-quality bench: the ISP is a register-file model with a modelled frame path (synthetic colour-bar frames), there are no 3A statistics, and timing and image quality cannot be tested. Setup, per-SoC status and limits: [docs/QEMU_TESTING.md](../../docs/QEMU_TESTING.md).

## Literal chains rebuilt as plain C (2026-10-25, `claude/t40-c-chains`)

The literal mips2c chains (`tx_isp_t40_*_lit.inc`, one emulated MIPS stack and a call dispatcher per chain) are being
replaced by readable C written from the OEM flow, one header per block. Each replacement is compared on the host with
the literal chain it replaces (`tests/t40/c_chains_host`, literal source taken from git `6d63667b`): every register
write and the whole chain state, 26 SDK 1.3.1 + 5 Eufy tuning bins, day/night banks, gain walks, random bins.

- `tx_isp_t40_intp.h`: the OEM 11-knot table interpolation (`tisp_simple_intp_int8/16`: bit-15 rounding, unsigned
  index compare) for the C chains.
- `tx_isp_t40_dpc.h` (TOP bit 4): bank section +11960 (1074 bytes), linear/WDR table set, 23 gain tables, static and
  gain registers 0x7000..0x70a0, refresh when the total gain moved by 1/256. Parameter `t40_dpc_on` as before.
- `tx_isp_t40_lce.h` (TOP bit 21): bank section +0x10c84 (984 bytes), 5x9 statistics cells, IRQ 8 (ping/pong RAM) and
  event 0x10, global + 32 local histogram curves, 32x16 LUT via 0x501e0/0x501e4. Parameter `t40_lce_on` as before.
  The session end resets the LCE session state as the OEM `tisp_slake_all -> tisp_lce_remove` does.
- `tx_isp_t40_sdns.h` (TOP bit 18, `enable_sdns`): bank section +0x17b00 (2900 bytes), 125 fields (linear/WDR
  half), 123 interpolated at the denoise EV, static and gain registers 0x14000..0x14200, 0x14054 latch. The init runs
  at block init, on a bank switch and after SetModule_Ratio (as the literal glue did); the recovered `main_sdns*`
  globals point at the C state, so the recovered helpers (ratio scaling, WDR switch, tuning get/set) see the same data.
- The `dpclit_*` / `lcelit_*` diagnostic counters are gone; an init failure is logged as an error.

## AE tuning API (2026-10-26, T40-AE-API)

The vendor T40 1.3.1 AE calls are served by the frame-3A AE: GetAeStatistics (hardware AE statistics, OEM
arithmetic), AeTargetComp/HLC/BLC (ScenceAttr), AeExprInfo (T40 220-byte layout; freeze, manual IT/AG/ISPDG, min AG,
caps), AeWeight, FaceAe, AeSpeed and antiflicker. Plain-data part and OEM formulas: `tx_isp_t40_ae_api.h`
(host test `tests/tx_isp_t40_ae_api_test.c`). Diagnostics: `/sys/module/tx_isp_t40/parameters/t40_ae_api`;
`t40_ae_stats_src` 0 auto / 1 hardware / 2 frame grid; `t40_ae_af_enable`, `t40_ae_af_step_now`.
Not acting on the AE: AeExpList (stored, read back), AeStartEv (stored), SetAeAlgoFunc (not offered).

## AF statistics, RGB coefficients (2026-10-26, `claude/gate-1026`)

GetAfStatistics / GetAFMetricesInfo read the AF DMA ring (buffer 4 of the tisp DMA set, 0x1a0cc..0x1a0d8) on demand:
the newest completed buffer is the one whose row-trailer frame counter is ahead of the others; unpack (15x15 zones,
OEM `tisp_af_get_statistics` bit layout) and metrics (OEM `tisp_af_alogrithm`, bank + 0x18674: weights +580,
parameters +806) are plain C in `tx_isp_t40_af.h` (host test `tests/t40/af_stats_host`). No AF IRQ and no AF
algorithm/lens control. Awb_Get/SetRgbCoefft act on the BCSH RGB offset vector (outer block +0x248 / WDR +0x480).

## `/dev/tisp` parameter get/set is a debug build only (#164, 2026-10-31)

The `/dev/tisp` commands 0x20007400 (get) and 0x20007401 (set) read and write the module parameter blocks and, with id 0x18, ISP
registers (window-limited since #139). They are not part of the release module: the default build has no `t40_tisp_par` parameter and
the two commands fail with `-EFAULT`. For the apitest case `tisppar_t40` and for bisecting build a debug module with
`make ... TX_ISP_T40_TISP_PAR=y` and load it with `t40_tisp_par=1` (read-only parameter, every call also needs `CAP_SYS_RAWIO`).
`build_local.sh` fails a default build that still carries the parameter (`tests/check_t40_tisp_par_gate.sh`). Never ship the debug
module in a firmware image.
