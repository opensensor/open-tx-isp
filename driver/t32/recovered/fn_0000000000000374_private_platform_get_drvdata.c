/* T32 OEM 0x374: private_platform_get_drvdata; recovery status: normalized_exact_match. */
#include "../compat.h"
void *private_platform_get_drvdata(const struct platform_device *pdev);
void *private_platform_get_drvdata(const struct platform_device *pdev)
{
    return platform_get_drvdata(pdev);
}
