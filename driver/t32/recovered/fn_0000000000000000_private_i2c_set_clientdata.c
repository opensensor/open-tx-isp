/* T32 OEM 0x0: private_i2c_set_clientdata; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_i2c_set_clientdata(struct i2c_client *dev, void *data);
void private_i2c_set_clientdata(struct i2c_client *dev, void *data)
{
    i2c_set_clientdata(dev, data);
}
