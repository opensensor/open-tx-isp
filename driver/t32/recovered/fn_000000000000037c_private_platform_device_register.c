/* T32 OEM 0x37c: private_platform_device_register; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_platform_device_register(struct platform_device *pdev);
int private_platform_device_register(struct platform_device *pdev)
{
    return platform_device_register(pdev);
}
