/* T32 OEM 0x550: private_i2c_get_adapter; recovery status: normalized_exact_match. */
#include "../compat.h"
struct i2c_adapter *private_i2c_get_adapter(int nr);
struct i2c_adapter *private_i2c_get_adapter(int nr)
{
    return i2c_get_adapter(nr);
}
