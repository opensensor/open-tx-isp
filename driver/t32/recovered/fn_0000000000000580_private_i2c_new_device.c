/* T32 OEM 0x580: private_i2c_new_device; recovery status: normalized_exact_match. */
#include "../compat.h"
struct i2c_client *private_i2c_new_device(struct i2c_adapter *adap, const struct i2c_board_info *info);
struct i2c_client *private_i2c_new_device(struct i2c_adapter *adap, const struct i2c_board_info *info)
{
    return i2c_new_device(adap, info);
}
