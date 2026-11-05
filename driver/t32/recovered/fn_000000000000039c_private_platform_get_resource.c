/* T32 OEM 0x39c: private_platform_get_resource; recovery status: normalized_exact_match. */
#include "../compat.h"
struct resource *private_platform_get_resource(struct platform_device *pdev, unsigned int type, unsigned int num);
struct resource *private_platform_get_resource(struct platform_device *pdev, unsigned int type, unsigned int num)
{
    return platform_get_resource(pdev, type, num);
}
