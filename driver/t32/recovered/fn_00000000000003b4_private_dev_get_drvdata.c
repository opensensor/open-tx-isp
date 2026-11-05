/* T32 OEM 0x3b4: private_dev_get_drvdata; recovery status: normalized_exact_match. */
#include "../compat.h"
void *private_dev_get_drvdata(const struct device *dev);
void *private_dev_get_drvdata(const struct device *dev)
{
    return dev_get_drvdata(dev);
}
