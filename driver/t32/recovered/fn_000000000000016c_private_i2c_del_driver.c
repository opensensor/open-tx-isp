/* T32 OEM 0x16c: private_i2c_del_driver; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_i2c_del_driver(struct i2c_driver *driver);
void private_i2c_del_driver(struct i2c_driver *driver)
{
    i2c_del_driver(driver);
}
