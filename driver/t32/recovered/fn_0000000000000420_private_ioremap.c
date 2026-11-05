/* T32 OEM 0x420: private_ioremap; recovery status: normalized_exact_match. */
#include "../compat.h"
void __iomem *private_ioremap(phys_addr_t offset, unsigned long size);
void __iomem *private_ioremap(phys_addr_t offset, unsigned long size)
{
    return ioremap(offset, size);
}
