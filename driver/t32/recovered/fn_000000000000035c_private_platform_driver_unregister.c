/* T32 OEM 0x35c: private_platform_driver_unregister; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_platform_driver_unregister(struct platform_driver *drv);
void private_platform_driver_unregister(struct platform_driver *drv)
{
    platform_driver_unregister(drv);
}
