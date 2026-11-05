/* T32 OEM 0x36c: private_platform_set_drvdata; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_platform_set_drvdata(struct platform_device *pdev, void *data);
void private_platform_set_drvdata(struct platform_device *pdev, void *data)
{
    platform_set_drvdata(pdev, data);
}
