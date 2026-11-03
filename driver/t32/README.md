# T32 (PRJ007) open TX-ISP driver — S3 (3 channels, sensor fps)

Status: **QEMU only** (`-M ingenic-t32`, kernel 4.4.94, vendor libimp 2.2.0,
prebuilt `sensor_cv8001_t32.ko`). Not tested on a camera.

T32 is a hybrid: T41-family Tiziano ISP core, T23-style MSCA at 0xf0000,
XBurst1 CPU (MXU/MXU2, no MXU3), HERA/JPEG encoders (T23/T30 soc_vpu
family). Plan and reference traces: `audit/T32_T33_PLAN_1025.md`,
`audit/T32_S0_1025.md` in the campaign notes.

This is a new, typed driver rather than a copy of the recovered T41 module:
the T41 code is written against T41 object offsets and ioctl numbers, and
both differ on T32 (sensor registration 116 bytes, framechan ioctls nr
131-140 with a 96-byte buffer, subdevice ops at 0x108). The pieces that are
generation-shared come from the shared code instead:

| Piece | Source |
|---|---|
| sensor registry, `/proc/jz/sensor` | `driver/common/tx_isp_sinfo.c` (T32 offsets in `tx_isp_t32_sinfo.c`) |
| MSCA channel geometry rules | `driver/t23/tx_isp_t23_msca_geom.h` (T32 channel layout in `tx_isp_t32_msca.h`) |
| kernel-API wrappers for sensor modules | same set as T41 (`tx_isp_t32_funcs.c`) |

## What S1 does

- Device nodes: `/dev/tx-isp`, `/dev/isp-m0`, `/dev/misc-ivdc`,
  `/dev/framechan0-2`; `/proc/jz/isp/isp-m0` and `isp-w02` (status text).
- `REGISTER_SENSOR`: creates the I2C client, the prebuilt sensor module
  probes, the driver copies the registration into the sensor object and calls
  its `g_chip_ident` (detection), then binds it in the sensor registry.
- Answers the libimp 2.2.0 sequence of `IMP_ISP_Open`, `IMP_ISP_AddSensor`,
  `IMP_ISP_EnableSensor`, `IMP_System_Init` and `IMP_ISP_EnableTuning`
  exactly as the vendor driver does (same ioctls, same order, same returned
  values; QEMU run s1d vs vendor r22):
  - `DRIVER_VERSION` fills a 64-byte buffer: SoC name and driver version,
    which libimp compares with its own (`driver_soc`, `driver_version`).
  - `DEFAULT_BIN` fills an 880-byte buffer with the IQ bin format version and
    SoC that libimp checks the bin against (`bin_version`).
  - `ENUMINPUT` returns `{index, name[32]}`; libimp finds its sensor by name.
  - `MEMORY_MALLOC`/`FREE`: page-contiguous buffers returned as `{kva, pa}`;
    libimp maps them through `/dev/mem` and loads the IQ bins into them.
  - `S_INPUT` returns the sensor size as `w << 16 | h`.
  - `GET_ISP_MEM_INFO` returns the ISP working-memory size
    (`tx_isp_t32_mem.h`, same value as the vendor: 0x9f9000 at 3840x2160,
    `isp_memopt` 1500); IPC (RISC-V) memory 0.
  - `STREAMON`/`STREAMOFF` run the sensor's own init and `s_stream`.
- Register lists (`tx_isp_t32_rcfg.h`): builder and walker for the RCFG list
  format, for S2 (the vendor driver runs one list at stream-on).

## S2: frame path (`tx_isp_t32_hw.c`, `tx_isp_t32_fs.c`)

- `S_INPUT` writes the VIC input configuration, `STREAMON` enables the ISP
  interrupt block, runs the VIC and starts the MIPI CSI host and D-PHY
  (values and order of the vendor trace; derived from the sensor attributes
  since S3).
- `/dev/framechanN`: `REQBUFS`, `QBUF`/`DQBUF` (96-byte buffer, geometry from
  QBUF word 19 and stride word 17), `STREAMON`/`STREAMOFF`, `LISTEN_BUF`
  (`listen_timeout_ms`). Queued buffers go to the MSCA channel's push FIFOs;
  the ISP interrupt (INTC 29, `isp_irq`) drains the done FIFO (UV read
  before the Y pop) and wakes the listener. VIC interrupt: INTC 30
  (`vic_irq`). Closing the channel stops it.
- QEMU (vendor libimp 2.2.0, `sensor_cv8001_t32.ko`): FrameSource 10/10
  frames at 1920x1080 and 5/5 at 1280x720 with the model's colour bars, JPEG
  and H.264 encoders bound to channel 0 deliver 10/10, full teardown
  (`DisableSensor`/`DelSensor`) returns 0, rmmod/modprobe cycles with frames
  are clean.

## S3: sensor attributes, frame rate, channels 1/2, register lists

- VIC and CSI/D-PHY values derived from the sensor attributes
  (`tx_isp_t32_vic.h`; formulas in the header): line words, `csi_fmt`,
  `mipi_sc` control word, crops, frame mode; lanes and the D-PHY settle value
  from the lane clock. Identical to the vendor's writes for the cv8001 (67/67).
  DVP sensors and CSI host 1: refused (not referenced yet).
- Sensor frame rate: isp-m0 tuning id `0x08000070` (`num << 16 | den`); GET
  answers the sensor's rate, SET calls the sensor's
  `TX_ISP_EVENT_SENSOR_FPS` (frame length over I2C), as tisp does.
- `/dev/framechan0-2`: each channel gets size, crop, scaler steps (input /
  output in Q14) and its parameter words at `STREAMON`; no upscaling.
- Register lists (`tx_isp_t32_rcfg.h`): both command kinds (consecutive
  registers, bit 31 set; one table port, bit 31 clear). The stream-on list
  (table word 49, `0x22014` bit 17) runs at `STREAMON`; it is empty until
  tisp fills it (S4).
- QEMU (vendor libimp 2.2.0, our QEMU build with the cv8001 frame timing from
  its HTS/VTS registers): ch0 1080p + ch1 640x360 + ch2 720p at 14.7 fps
  (sensor 15/1), `SetSensorFPS(10/1)` -> 9.9 fps, 5 reload cycles clean.

## S4 (in progress): MSCA polyphase curves, stream-on list, statistics, front end

- At every channel start the driver loads the polyphase filter curves of all
  three channels through the MSCA shadow port (`tx_isp_t32_msca_curve.h`,
  flow of the vendor `tisp_msca_curve_calc` / `tisp_msca_ch_curve_write`):
  ratio out/in in Q14 (limit 27306), 25 samples of a Lanczos-2 shaped kernel,
  8 phases x 6 taps normalised to 2048, 13 words per direction at
  `0xf0820 + ch * 0xa0` (vertical +0x50), the tail field 0x5a at `0xf09e0`,
  the pair count to `0xf8100`. Unused channels get the flat 6-tap box.
  The kernel table is computed (`tools/t32_msca_sinc_tab.py`), not the
  vendor's: against the vendor's QEMU writes (3840x2160 to 1080p, 720p,
  640x360) 6 of 75 coefficients differ by 1 of 2048, the 1:6 curve is
  identical. The vendor leaves a not yet used channel 2 out of the first
  blocks; the driver always loads all three.
- `+0x28` filter-select pulse per channel (cv8001/PRJ007 values 0x41, 0x01,
  0x00 until the IQ bin parser provides them), as the vendor.
- QEMU (run s4a, vendor libimp 2.2.0): 3 channels 1080p/640x360/720p 8/8
  frames each, 14.7 fps; MSCA writes = vendor run v1 except the curve LSBs.
- Stream-on register list = the LSC block from the IQ bin
  (`tx_isp_t32_lsc.h`, flow of the vendor `tisp_lsc_init`,
  `tisp_lsc_calc_para_refresh`, `tisp_lsc_interp_by_tgain`,
  `tisp_lsc_write_all_reg`): parameters at bin + 0x98 + 0x68c4 (block id
  0x0134da11, also written to 0x5000), grid from the sensor size and the
  cell size, the 13 control registers 0x5040..0x5070, the mesh (1152 cells,
  3 words each) through the port 0x32020/0x32024, 0x2f4 = 0. Built from the
  cv8001 PRJ007 bin at 3850 K it is identical to the vendor's list (3479 of
  3479 words, host test with the bin and the r20 dump). Stage 1: between two
  colour temperature tables the nearer one is used (the vendor blends them;
  `tisp_lsc_interp_by_ct` is stage 2), the colour temperature is the module
  parameter `lsc_ct` (vendor init 5000, no AWB yet), gain 0. The QEMU model
  does not execute T32 lists: QEMU shows the list built and run (run s4c,
  3 channels 8/8 frames), the picture effect needs a camera.

- AE and AWB statistics engines initialised from the IQ bin at stream-on
  (`tx_isp_t32_stats.h`, flow of the vendor `tisp_ae_malloc_cfg`,
  `tisp_ae_set_hardware_param`, `tisp_ae_roi_point`, `tisp_awb_malloc_cfg`,
  `tisp_awb_set_hardware_param`, `tisp_awb_set_regional_threshold`,
  `tisp_awb_set_lum_th_freq`): zone grid, ROI, thresholds (EV 1024 as
  `tisp_awb_init`), buffers (AE 4 x 4 KiB zones + 4 x 2 KiB histograms, AWB
  4 x 0x7000). Against the vendor's AddSensor writes (cv8001 bin, 3840x2160):
  50 of 50 identical apart from the buffer addresses (host test with the bin;
  QEMU run s4g). The blocks are IQ bin sections 1 (AE, bin + 0x104) and 2
  (AWB, bin + 0xddc) of the section table the vendor's `tisp_bin_data_parse`
  walks (`tx_isp_t32_iq.h`: 28 x { enable, length } at 0x14, sections packed
  from 0xa0); the vendor copies each to its own tparamsP offset (AE + 0x68,
  AWB + 0xd40, LSC + 0x68c4), which explains the former 4-byte AE question.
  Stream-on checks that the bin's table puts them there.
  The engines are switched off before their buffers are freed (#132 lesson).
  Statistics interrupts (0x30028 bits 3/4/5) are counted (proc).

- **Bring-up controller, not the vendor AE/AWB** (`bringup_ae=1`, default off):
  scaffolding only, until the vendor AE flow is reimplemented. Every AE
  histogram interrupt schedules a work item that reads the histogram buffer
  written last (0x1708c bits 1:0; 256 bins of 24 bits, two per 64-bit word),
  takes the mean bin and scales the integration time by `bringup_target` /
  mean (at most x4 / x0.25 per step, 1 .. VTS - 4 lines, gain unchanged)
  through the sensor's EXPO event (0x02000017). No AWB, no tuning. QEMU run
  s4h: 13 histogram interrupts, 5 steps, the sensor ioctl accepted each; proc
  shows steps, last mean and integration time.

- **Front end: CSC, CSCCR, ISP top** (`tx_isp_t32_front.h`, flow of the vendor
  `tisp_csc_init`, `tisp_csccr_init`, `tisp_top_init`, `tisp_top_reg_cfg`),
  written at stream-on before the statistics engines: the colour conversion
  matrix of the bin's mode (BT.601/709/2020, full/limited; the bin supplies
  the mode, the vendor loads the matrix of the mode over its working copy),
  the chroma range (mode 0..2), the ISP top size/bayer/enable registers
  (sensor size, `isp_mbus_to_bayer` for 8/10/12-bit Bayer codes, control
  bits from IQ section 0). 25 of 25 writes identical to the vendor's
  AddSensor writes (cv8001 bin, 3840x2160, SRGGB10; host test with the bin).
  The vendor writes them at AddSensor, the driver at stream-on (the bin and the
  sensor mode are known there). IQ section offsets now include the look-up
  table payloads the vendor's parse copies after sections 7, 12, 13, 19, 20
  (not counted in the table lengths): sections 8 and up were at wrong
  offsets before (none was used).

- **tisp init blocks from the IQ bin** (S4 step 5; flow of the vendor
  `tisp_*_init` at AddSensor, one header per block, written at stream-on after
  the statistics engines, `t32_tisp_init`): DMSC (`tx_isp_t32_dmsc.h`, section
  11, 175 writes), gamma (`_gamma.h`, section 13 and its curve payload, 390),
  CDNS (`_cdns.h`, section 18, 16), YDNS (`_ydns.h`, section 17, 17), SDNS
  (`_sdns.h`, section 22, 27), YSP (`_ysp.h`, section 21, 147) and CLM
  (`_clm.h`, section 20 and its colour-temperature payload, 868; the
  YCbCr -> RGB matrix of the colour space is computed from the primaries, not
  copied). The interpolated blocks run the vendor's table interpolation at the
  gain index 1.0 (as `tisp_*_refresh(0x10000)` at init); the DMSC and YSP
  register functions are a mechanical transcription of the vendor flow (the
  section is edited by them, so the driver passes a copy). Against the vendor's
  AddSensor writes (cv8001 bin, 3840x2160, SRGGB10) every block is identical
  write for write: 1640 of the 5555 writes of the vendor's AddSensor core
  phase (host test `tx_isp_t32_tisp_test` with `T32_IQ_BIN` and the local
  trace `T32_ADD_TRACE`; with the earlier front end, AE/AWB and MSCA blocks 1726).
  A block whose section is missing or has another size is skipped. Not built
  (vendor flow needs inputs the bin does not carry or vendor-internal
  tables): tmo, MDNS (its compression setting comes from the init parameters),
  RDNS (vendor smooth table), DPC, GIB, defog, CCM, BCSH, LCE, AF and the
  remaining small blocks (about 3800 writes). QEMU (debug kernel,
  `slub_debug=FZPU`, `maxcpus=1`, vendor libimp 2.2.0): the blocks' writes
  appear in the stream-on phase with the vendor's values; picture effect
  needs a camera.

## Not yet (S4+)

No tisp/3A, no IQ bin parsing (the bin's physical address is kept), no
image-pipeline register programming (the QEMU model does not process pixels,
so this needs a camera); the stream-on list carries the LSC block only. The channel parameter words
are the vendor's cv8001/PRJ007 values until the bin parser provides them.
Day/night, WDR, LDC, OSD, IVDC direct mode, AOV/RISC-V hand-over: off.

## Build

```sh
make -C $KDIR M=$PWD/driver/t32 ARCH=mips CROSS_COMPILE=mipsel-linux- modules
```
against a thingino T32 kernel 4.4.94 tree. Host tests:
`make -C tests tx_isp_t32_mem_rcfg_test tx_isp_t32_vic_test tx_isp_t32_msca_curve_test tx_isp_t32_lsc_test tx_isp_t32_stats_test tx_isp_t32_front_test tx_isp_t32_tisp_test`
(`T32_IQ_BIN` / `T32_RCFG_REF` / `T32_ADD_TRACE` for the comparison with the vendor lists).

## Module parameters

| Name | Default | Meaning |
|---|---|---|
| `print_level` | 1 | `isp_printf` threshold (0 info, 1 warning, 2 error) |
| `isp_memopt` | 1500 | MDNS memory ratio in 1/1000 (<= 1000 uncompressed, max 2000) |
| `driver_soc`, `driver_version` | `PRJ007`, `20251107a` | answered to `DRIVER_VERSION`; must match libimp |
| `bin_version` | `1.00` | IQ bin format version answered to `DEFAULT_BIN` |
| `t32_trace` | 1 | log every ioctl (bring-up) |
| `isp_irq`, `vic_irq` | 37, 38 | Linux IRQs of INTC 29/30 (XBURST_SOC_IRQ_BASE 8) |
| `listen_timeout_ms` | 2000 | `LISTEN_BUF` wait limit |
| `lsc_ct` | 5000 | colour temperature for the LSC mesh at stream-on |
| `bringup_ae` | 0 | 1 = bring-up exposure controller (not the vendor AE) |
| `bringup_target` | 64 | its target mean histogram bin (0..255) |
