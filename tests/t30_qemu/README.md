# T30 QEMU regression tests (tx-isp-t30, no camera)

Evidence level: `qemu` only (QEMU `ingenic-t30` machine with the sc4236 sensor model). Nothing here
is device evidence.

| Test | Issue | What it proves |
| --- | --- | --- |
| `sensor_register.c` | Lu-Fi/openimp#174 | `IMP_ISP_GetSensorRegister` (ioctl 0xc0385650) returns the sensor register (sc4236 chip id 0x3107/0x3108 = 0x32/0x35) and does not oops |
| `isp_init_cycles.c` | Lu-Fi/openimp#176 | N x (System_Init, ISP_Open, AddSensor, EnableSensor, teardown) with a module built with `TX_ISP_T30_TEST_FW_INIT_DELAY_MS=400` (holds the firmware init window open so a frame IRQ lands before the event queue exists): no "Fatal exception in interrupt" |
| `fs_two_channels.c` | Lu-Fi/openimp#175 (open) | N x (ISP init, FrameSource ch0 2304x1536 + ch1 640x360, EnableChn 0 then 1, teardown). Currently still fatal in about 1 of 7 cycles (LIST_POISON2 in `tx_isp_t30_mscaler_configure_dma` from the mscaler ISR), so it is a repro, not a passing test |

## Build and run

    # module: normal, and delay build for isp_init_cycles
    ROOT=<thingino output dir> SOC=t30 ./build_local.sh
    TX_ISP_T30_TEST_FW_INIT_DELAY_MS=400 ROOT=<thingino output dir> SOC=t30 ./build_local.sh
    # test programs (OpenIMP T30 libimp + headers)
    $ROOT/host/bin/mipsel-linux-gcc -std=gnu99 -Os -mabi=32 -march=mips32r2 -DPLATFORM_T30 \
        -I <openimp>/include sensor_register.c -o sensor_register -L<libimp dir> -l:libimp.so -lpthread -lm

In the guest (QEMU T30 `init=/bin/sh` image, sc4236 device on i2c0): `insmod tx-isp-t30.ko; modprobe sensor_sc4236_t30;
./sensor_register` must print `GetSensorRegister(0x3107) rc=0 val=0x32`, `(0x3108) val=0x35` and `done`;
`./isp_init_cycles 6` (delay module) must print `cycles done`; `dmesg | grep -c Oops` must be 0.
Expected result on the unfixed driver: oops in `tx_isp_unlocked_ioctl` (BadVA 0x40c) resp. panic
"Fatal exception in interrupt" at `apical_loop_buffer_write_u8`.
