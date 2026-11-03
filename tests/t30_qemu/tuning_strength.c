/* QEMU T30: strengths scaled through the driver calibration tables, scene mode, colour effect, brightness/saturation read-back
 * (Lu-Fi/openimp#177).  Prints one line per call; exit 1 when a result is not as expected. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <imp/imp_common.h>
#include <imp/imp_system.h>
#include <imp/imp_isp.h>

static int bad;
#define CHK(call, cond) do { int _r = (call); printf("%-48s rc=%d %s\n", #call, _r, (cond) ? "ok" : "BAD"); fflush(stdout); if (!(cond)) bad++; } while (0)

int main(int argc, char **argv)
{
    IMPSensorInfo si; memset(&si, 0, sizeof si);
    unsigned v = 0;
    IMPISPSceneMode sm = 0; IMPISPColorfxMode cm = 0;
    unsigned char b = 0;
    int cycles = argc > 1 ? atoi(argv[1]) : 1, i;

    strcpy(si.name, "sc4236"); si.cbus_type = TX_SENSOR_CONTROL_INTERFACE_I2C;
    strcpy(si.i2c.type, "sc4236"); si.i2c.addr = 0x30; si.i2c.i2c_adapter = 0;
    si.rst_gpio = -1; si.pwdn_gpio = -1; si.power_gpio = -1;
    CHK(IMP_System_Init(), _r == 0);
    CHK(IMP_ISP_Open(), _r == 0);
    CHK(IMP_ISP_AddSensor(&si), _r == 0);
    CHK(IMP_ISP_EnableSensor(), _r == 0);
    CHK(IMP_ISP_EnableTuning(), _r == 0);
    for (i = 0; i < cycles; i++) {
        CHK(IMP_ISP_Tuning_SetSinterStrength(128), _r == 0);
        CHK(IMP_ISP_Tuning_SetSinterStrength(200), _r == 0);
        CHK(IMP_ISP_Tuning_GetSinterStrength(&v), _r == 0 && v == 200);
        CHK(IMP_ISP_Tuning_SetSinterStrength(128), _r == 0);
        CHK(IMP_ISP_Tuning_SetTemperStrength(100), _r == 0);
        CHK(IMP_ISP_Tuning_GetTemperStrength(&v), _r == 0 && v == 100);
        CHK(IMP_ISP_Tuning_SetTemperStrength(128), _r == 0);
        CHK(IMP_ISP_Tuning_SetSceneMode((IMPISPSceneMode)3), _r == 0);
        CHK(IMP_ISP_Tuning_GetSceneMode(&sm), _r == 0 && (int)sm == 3);
        CHK(IMP_ISP_Tuning_SetSceneMode((IMPISPSceneMode)0), _r == 0);
        CHK(IMP_ISP_Tuning_SetColorfxMode((IMPISPColorfxMode)1), _r == 0);
        CHK(IMP_ISP_Tuning_GetColorfxMode(&cm), _r == 0 && (int)cm == 1);
        CHK(IMP_ISP_Tuning_SetColorfxMode((IMPISPColorfxMode)0), _r == 0);
        /* picture levels are cached in the tuning object and read back (they read 0 before #177) */
        CHK(IMP_ISP_Tuning_SetBrightness(90), _r == 0);
        CHK(IMP_ISP_Tuning_GetBrightness(&b), _r == 0 && b == 90);
        CHK(IMP_ISP_Tuning_SetBrightness(128), _r == 0);
        CHK(IMP_ISP_Tuning_SetSaturation(160), _r == 0);
        CHK(IMP_ISP_Tuning_GetSaturation(&b), _r == 0 && b == 160);
        CHK(IMP_ISP_Tuning_SetSaturation(128), _r == 0);
    }
    IMP_ISP_DisableTuning(); IMP_ISP_DisableSensor(); IMP_ISP_DelSensor(&si); IMP_ISP_Close();
    printf("done bad=%d\n", bad);
    return bad ? 1 : 0;
}
