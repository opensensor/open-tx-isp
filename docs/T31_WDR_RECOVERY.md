# T31 WDR source recovery

The T31 WDR path previously contained successful-return stubs for histogram
matching, EV interpolation, fusion, parameter loading and register output. The
wrapper also used an incomplete algorithm signature and incorrect parameter IDs.
These functions now perform the recovered calculations and program their results.

This does **not** enable HDR on a running linear-mode camera. The separate T31
short-exposure AE controller, `tisp_ae1_process`, remains disabled; WDR frame
processing keeps the previous registers when short-exposure controls are absent.
Live DOL sensor timing, exposure convergence, motion and daylight image quality
still need validation before enabling HDR on a device.

## Implementation

- Preserve the complete thirty-pointer `Tiziano_wdr_fpga` ABI, RGB histogram
  matching, map resampling, temporal blending, detail and deghost calculations.
- Restore EV-dependent fusion curves, spatial weights, all 51 parameter IDs
  (`0x3ff` through `0x431`), calibration-bank offsets and register masks/order.
- Decode packed long/short RGB statistics from the completed DMA slot. Copy the
  eight payload fragments into separate storage without modifying DMA input.
- Snapshot statistics in the interrupt path and perform histogram matching in
  a workqueue. The ISP event dispatcher holds interrupts disabled, so it cannot
  perform this calculation or take a mutex. Parameter updates and exported
  algorithm calls serialize with the worker's shared scratch storage.
- Retain and release the WDR DMA allocation across initialization/teardown;
  synchronize interrupts and drain work before freeing it or removing MMIO.
- Read AE1 DMA statistics instead of overwriting them. Calculate each block's
  area from its row and column dimensions and select the brightest 4–8 blocks
  from all 225 entries for fusion feedback.

Explicit departures from the reference include bounded input checks, rejection
of invalid interpolation knots/zero divisors, a defined unity map before the
first result, and complete brightest-block selection. Hardware output is committed
only after a successful frame calculation. These guards are not a claim that
arbitrary corrupt calibration words are safe or meaningful.

## Reproducible validation

`make -C tests check` includes packed-statistics and boundary tests plus 821
reference comparisons: 432 full algorithm cases, 72 parameter-register cases,
240 EV/fusion/deghost cases, 72 result-register cases and 5 spatial geometries.
Register comparisons include write order and high-bit masking. The host runtime
adapter includes the actual driver integration with mocked hardware and scheduling;
it does not exercise kernel concurrency or physical DMA.

The checked-in numeric fixtures and output digests require no proprietary binary
to run. To regenerate them, supply your own matching, unstripped reference module
and install `pyelftools` and `unicorn` in a Python environment:

```sh
python tools/gen_t31_wdr_oracle.py --vendor-ko /path/to/tx-isp-t31.ko
make -C tests check
```

The generator loads and relocates MIPS code in a host emulator, supplies the same
inputs to the recovered C implementation, compares output digests, and writes
the header only after every case passes. MMIO and memory routines are intercepted;
no device is accessed and no vendor executable is copied into the repository.
Reference ELF SHA-256:
`f762133b0f6f7b729ebbc75ea057fb11bd556e979ca5b74dd2c3e20d8b3abb12`.
The repository's `driver/t31/tx-isp-t31.ko_hlil.txt` provides the corresponding
decompiled reference; ELF symbols resolve layout differences.

Both WDR host tests also pass AddressSanitizer/UndefinedBehaviorSanitizer. The
complete T31 module builds and links against the Thingino 3.10.14 kernel using
`ROOT=/path/to/thingino/output SOC=t31 ./build_local.sh`. This source recovery
has not yet been loaded on a camera or validated with a live two-exposure stream.
