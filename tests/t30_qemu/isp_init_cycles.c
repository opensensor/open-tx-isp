#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <imp/imp_common.h>
#include <imp/imp_system.h>
#include <imp/imp_isp.h>
int main(int argc, char **argv)
{
    int n = argc > 1 ? atoi(argv[1]) : 10;
    IMPSensorInfo si; memset(&si, 0, sizeof si);
    strcpy(si.name, "sc4236"); si.cbus_type = TX_SENSOR_CONTROL_INTERFACE_I2C;
    strcpy(si.i2c.type, "sc4236"); si.i2c.addr = 0x30; si.i2c.i2c_adapter = 0;
    si.rst_gpio = -1; si.pwdn_gpio = -1; si.power_gpio = -1;
    for (int i = 0; i < n; i++) {
        int a = IMP_System_Init(), b = IMP_ISP_Open(), c = IMP_ISP_AddSensor(&si), d = IMP_ISP_EnableSensor();
        printf("cycle %d init=%d open=%d add=%d en=%d\n", i, a, b, c, d); fflush(stdout);
        usleep(300000);
        IMP_ISP_DisableSensor(); IMP_ISP_DelSensor(&si); IMP_ISP_Close(); IMP_System_Exit();
    }
    printf("cycles done\n");
    return 0;
}
