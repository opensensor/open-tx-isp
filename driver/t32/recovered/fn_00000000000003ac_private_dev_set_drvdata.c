/* T32 OEM 0x3ac: private_dev_set_drvdata; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_dev_set_drvdata(struct device *dev, void *data);
void private_dev_set_drvdata(struct device *dev, void *data)
{
    *(void **)((char *)dev + 0x4c) = data;
}
