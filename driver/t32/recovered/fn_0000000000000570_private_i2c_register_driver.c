/* T32 OEM 0x570: private_i2c_register_driver; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_i2c_register_driver(struct module *owner, struct i2c_driver *driver);
int private_i2c_register_driver(struct module *owner, struct i2c_driver *driver)
{
    return i2c_register_driver(owner, driver);
}
