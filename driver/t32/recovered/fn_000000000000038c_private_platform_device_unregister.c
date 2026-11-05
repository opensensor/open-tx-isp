/* T32 OEM 0x38c: private_platform_device_unregister; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_platform_device_unregister(struct platform_device *pdev);
void private_platform_device_unregister(struct platform_device *pdev)
{
    platform_device_unregister(pdev);
}
