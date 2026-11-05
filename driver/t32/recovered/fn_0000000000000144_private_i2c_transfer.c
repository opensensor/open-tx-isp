/* T32 OEM 0x144: private_i2c_transfer; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num);
int private_i2c_transfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
    return i2c_transfer(adap, msgs, num);
}
