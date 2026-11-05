/* T32 OEM 0x560: private_i2c_put_adapter; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_i2c_put_adapter(struct i2c_adapter *adap);
void private_i2c_put_adapter(struct i2c_adapter *adap)
{
    i2c_put_adapter(adap);
}
