/* T32 OEM 0x430: private_iounmap; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_iounmap(const volatile void __iomem *addr);
void private_iounmap(const volatile void __iomem *addr)
{
    iounmap((volatile void __iomem *)addr);
}
