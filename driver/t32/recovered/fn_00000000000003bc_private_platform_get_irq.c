/* T32 OEM 0x3bc: private_platform_get_irq; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_platform_get_irq(struct platform_device *pdev, unsigned int num);
int private_platform_get_irq(struct platform_device *pdev, unsigned int num)
{
    return platform_get_irq(pdev, num);
}
