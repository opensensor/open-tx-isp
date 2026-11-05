/* T32 OEM 0x8: private_i2c_get_clientdata; recovery status: normalized_exact_match. */
#include "../compat.h"
void *private_i2c_get_clientdata(const struct i2c_client *dev);
void *private_i2c_get_clientdata(const struct i2c_client *dev)
{
    return i2c_get_clientdata(dev);
}
