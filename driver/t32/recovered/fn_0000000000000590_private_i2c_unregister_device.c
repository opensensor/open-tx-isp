/* T32 OEM 0x590: private_i2c_unregister_device; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_i2c_unregister_device(struct i2c_client *client);
void private_i2c_unregister_device(struct i2c_client *client)
{
    i2c_unregister_device(client);
}
