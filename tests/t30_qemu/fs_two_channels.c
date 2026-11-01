/*
 * Lu-Fi/openimp#175 regression (QEMU ingenic-t30, sc4236 model):
 * N x (ISP init, FrameSource ch0 2304x1536 + ch1 640x360, EnableChn 0 then 1,
 * teardown).
 *
 * Deterministic check: after every teardown the multi-scaler's Y push FIFO of
 * both channels must be empty (channel N state register 0x130b0000 + 0x170 +
 * N * 0x100: bit 0 empty, bits 4:2 count).  The unfixed driver left the
 * addresses of the session in the hardware FIFO at stream-off; the next
 * session then got "done" for buffers still queued in software and corrupted
 * the mscaler fifo list (LIST_POISON2 oops in configure_dma, ~1 in 7 cycles).
 * Prints "STALE" and exits 1 on the first non-empty FIFO; "cycles done" else.
 * Pass "nocheck" as second argument to run the cycles without the check.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <imp/imp_common.h>
#include <imp/imp_system.h>
#include <imp/imp_isp.h>
#include <imp/imp_framesource.h>

#define MSCA_BASE 0x130b0000u

static volatile uint32_t *msca_map(void)
{
    int fd = open("/dev/mem", O_RDONLY | O_SYNC);
    void *p;

    if (fd < 0)
        return NULL;
    p = mmap(NULL, 0x1000, PROT_READ, MAP_SHARED, fd, MSCA_BASE);
    close(fd);
    return p == MAP_FAILED ? NULL : p;
}

int main(int argc, char **argv)
{
    int n = argc > 1 ? atoi(argv[1]) : 10;
    int check = !(argc > 2 && !strcmp(argv[2], "nocheck"));
    volatile uint32_t *msca = check ? msca_map() : NULL;
    IMPSensorInfo si; memset(&si, 0, sizeof si);
    strcpy(si.name, "sc4236"); si.cbus_type = TX_SENSOR_CONTROL_INTERFACE_I2C;
    strcpy(si.i2c.type, "sc4236"); si.i2c.addr = 0x30; si.i2c.i2c_adapter = 0;
    si.rst_gpio = -1; si.pwdn_gpio = -1; si.power_gpio = -1;
    IMPFSChnAttr fs0, fs1;
    memset(&fs0, 0, sizeof fs0);
    fs0.picWidth = 2304; fs0.picHeight = 1536; fs0.pixFmt = PIX_FMT_NV12;
    fs0.outFrmRateNum = 15; fs0.outFrmRateDen = 1; fs0.nrVBs = 2; fs0.type = FS_PHY_CHANNEL;
    fs1 = fs0; fs1.picWidth = 640; fs1.picHeight = 360; fs1.nrVBs = 3;
    fs1.scaler.enable = 1; fs1.scaler.outwidth = 640; fs1.scaler.outheight = 360;
    if (check && !msca) {
        printf("cannot map /dev/mem at 0x%08x\n", MSCA_BASE);
        return 2;
    }
    for (int i = 0; i < n; i++) {
        int a = IMP_System_Init(), b = IMP_ISP_Open(), c = IMP_ISP_AddSensor(&si), d = IMP_ISP_EnableSensor();
        int e = IMP_FrameSource_CreateChn(0, &fs0), f = IMP_FrameSource_CreateChn(1, &fs1);
        int g = IMP_FrameSource_EnableChn(0);
        usleep(150000);
        int h = IMP_FrameSource_EnableChn(1);
        printf("cycle %d init=%d open=%d add=%d en=%d c0=%d c1=%d e0=%d e1=%d\n", i, a, b, c, d, e, f, g, h); fflush(stdout);
        usleep(200000);
        IMP_FrameSource_DisableChn(1); IMP_FrameSource_DisableChn(0);
        IMP_FrameSource_DestroyChn(1); IMP_FrameSource_DestroyChn(0);
        IMP_ISP_DisableSensor(); IMP_ISP_DelSensor(&si); IMP_ISP_Close(); IMP_System_Exit();
        if (check) {
            uint32_t s0 = msca[0x170 / 4], s1 = msca[0x270 / 4];
            if (!(s0 & 1) || !(s1 & 1)) {
                printf("STALE cycle %d push fifo ch0=0x%x (n=%u) ch1=0x%x (n=%u)\n", i,
                       s0, (s0 >> 2) & 7, s1, (s1 >> 2) & 7);
                return 1;
            }
        }
    }
    printf("cycles done\n");
    return 0;
}
