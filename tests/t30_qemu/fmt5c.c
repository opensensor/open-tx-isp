/*
 * Lu-Fi/openimp#178 (QEMU ingenic-t30, sc4236 model): the frame-channel format
 * ioctl in the 0x5c-byte form of the vendor libimp (0xc05c56c3 / 0x405c56c4)
 * and in the old 0x4c-byte form (0xc04c56c3 / 0x404c56c4) must give the same
 * answer.  N x (ISP init, set/get on /dev/framechan0 in both forms, teardown).
 * Prints "cycles done" and exits 0 when all checks hold.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <imp/imp_common.h>
#include <imp/imp_system.h>
#include <imp/imp_isp.h>

#define SET5C 0xc05c56c3u
#define GET5C 0x405c56c4u
#define SET4C 0xc04c56c3u
#define GET4C 0x404c56c4u

static int bad;
#define CK(c, ...) do { if (!(c)) { bad++; printf("FAIL line %d: ", __LINE__); printf(__VA_ARGS__); printf("\n"); } } while (0)

static void fill5c(uint32_t *w, int width, int height)
{
    memset(w, 0, 0x5c);
    w[0] = 1; w[1] = width; w[2] = height; w[3] = 0x3231564e; /* NV12 */
    w[7] = 8;                                                /* SRGB */
    w[9] = 0x11111111; w[10] = 0x22222222; w[11] = 0x33333333; w[12] = 0x44444444;
    w[13] = 0; w[18] = 0; w[22] = 1;                         /* rate_mask as the vendor */
}

int main(int argc, char **argv)
{
    int n = argc > 1 ? atoi(argv[1]) : 3;
    IMPSensorInfo si; memset(&si, 0, sizeof si);
    strcpy(si.name, "sc4236"); si.cbus_type = TX_SENSOR_CONTROL_INTERFACE_I2C;
    strcpy(si.i2c.type, "sc4236"); si.i2c.addr = 0x30; si.i2c.i2c_adapter = 0;
    si.rst_gpio = -1; si.pwdn_gpio = -1; si.power_gpio = -1;

    for (int i = 0; i < n; i++) {
        uint32_t a[23], b[23], c[19], d[19];
        int r;
        int rc = IMP_System_Init();
        rc |= IMP_ISP_Open(); rc |= IMP_ISP_AddSensor(&si); rc |= IMP_ISP_EnableSensor();
        CK(rc == 0, "isp init rc=%d", rc);
        int fd = open("/dev/framechan0", O_RDWR);
        CK(fd >= 0, "open framechan0: %s", strerror(errno));
        if (fd >= 0) {
            fill5c(a, 2304, 1536);
            r = ioctl(fd, SET5C, a);
            CK(r == 0, "SET 0x5c rc=%d errno=%d", r, errno);
            CK(a[1] == 2304 && a[2] == 1536, "5c set size %ux%u", a[1], a[2]);
            CK(a[5] >= 2304 && a[6] >= 2304 * 1536 * 3 / 2, "5c set bytesperline %u sizeimage %u", a[5], a[6]);
            CK(a[9] == 0x11111111 && a[10] == 0x22222222 && a[11] == 0x33333333 && a[12] == 0x44444444,
               "extra words changed: %x %x %x %x", a[9], a[10], a[11], a[12]);
            memset(b, 0xa5, sizeof b); b[0] = 1;
            r = ioctl(fd, GET5C, b);
            CK(r == 0, "GET 0x5c rc=%d", r);
            CK(b[0] == 1 && b[1] == 2304 && b[2] == 1536 && b[3] == 0x3231564e, "5c get %u %ux%u fmt %x", b[0], b[1], b[2], b[3]);
            CK(b[4] == 4 && b[7] == 8, "5c get field %u colorspace %u", b[4], b[7]);
            CK(b[9] == 0 && b[10] == 0 && b[11] == 0 && b[12] == 0, "5c get extra words not zero");
            /* the same set through the old 0x4c form */
            memset(c, 0, sizeof c);
            c[0] = 1; c[1] = 2304; c[2] = 1536; c[3] = 0x3231564e; c[7] = 8; c[18] = 1;
            r = ioctl(fd, SET4C, c);
            CK(r == 0, "SET 0x4c rc=%d", r);
            memset(d, 0, sizeof d); d[0] = 1;
            r = ioctl(fd, GET4C, d);
            CK(r == 0, "GET 0x4c rc=%d", r);
            CK(d[1] == b[1] && d[2] == b[2] && d[5] == b[5] && d[6] == b[6] && d[3] == b[3],
               "4c/5c differ: %ux%u bpl %u size %u vs %ux%u bpl %u size %u", d[1], d[2], d[5], d[6], b[1], b[2], b[5], b[6]);
            CK(c[5] == a[5] && c[6] == a[6], "set results differ");
            /* wrong field: refused like the 0x4c form */
            fill5c(a, 2304, 1536); a[4] = 1;
            r = ioctl(fd, SET5C, a);
            CK(r == -1 && errno == EINVAL, "field=1 accepted rc=%d errno=%d", r, errno);
            /* scaled channel in the 0x5c form */
            fill5c(a, 640, 360); a[18] = 1; a[19] = 640; a[20] = 360;
            r = ioctl(fd, SET5C, a);
            printf("scaled 5c set rc=%d size %ux%u sizeimage %u\n", r, a[1], a[2], a[6]);
            close(fd);
        }
        printf("cycle %d done bad=%d\n", i, bad); fflush(stdout);
        IMP_ISP_DisableSensor(); IMP_ISP_DelSensor(&si); IMP_ISP_Close(); IMP_System_Exit();
    }
    if (bad) { printf("FAILED %d\n", bad); return 1; }
    printf("cycles done\n");
    return 0;
}
