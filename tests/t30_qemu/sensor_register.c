#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <imp/imp_common.h>
#include <imp/imp_system.h>
#include <imp/imp_isp.h>
/* not in the T30 public header; the symbol is exported by libimp */
int IMP_ISP_GetSensorRegister(unsigned reg, unsigned *val);
int main(int argc, char **argv)
{
    IMPSensorInfo si; memset(&si, 0, sizeof si);
    strcpy(si.name, "sc4236"); si.cbus_type = TX_SENSOR_CONTROL_INTERFACE_I2C;
    strcpy(si.i2c.type, "sc4236"); si.i2c.addr = 0x30; si.i2c.i2c_adapter = 0;
    si.rst_gpio = -1; si.pwdn_gpio = -1; si.power_gpio = -1;
    printf("System_Init rc=%d\n", IMP_System_Init());
    printf("ISP_Open rc=%d\n", IMP_ISP_Open());
    printf("AddSensor rc=%d\n", IMP_ISP_AddSensor(&si));
    printf("EnableSensor rc=%d\n", IMP_ISP_EnableSensor());
    fflush(stdout);
    unsigned regs[] = {0x3107, 0x3108, 0x3200, 0x3e03};
    for (int i = 0; i < 4; i++) {
        unsigned v = 0xdeadbeef;
        int r = IMP_ISP_GetSensorRegister(regs[i], &v);
        printf("GetSensorRegister(0x%x) rc=%d val=0x%x\n", regs[i], r, v); fflush(stdout);
    }
    IMP_ISP_DisableSensor(); IMP_ISP_DelSensor(&si); IMP_ISP_Close();
    printf("done\n");
    return 0;
}
