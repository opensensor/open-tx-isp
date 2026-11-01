#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <imp/imp_common.h>
#include <imp/imp_system.h>
#include <imp/imp_isp.h>
#include <imp/imp_framesource.h>
int main(int argc, char **argv)
{
    int n = argc > 1 ? atoi(argv[1]) : 10;
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
    }
    printf("cycles done\n");
    return 0;
}
