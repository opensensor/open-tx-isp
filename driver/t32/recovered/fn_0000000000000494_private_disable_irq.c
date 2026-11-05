/* T32 OEM 0x494: private_disable_irq; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_disable_irq(unsigned int irq);
void private_disable_irq(unsigned int irq)
{
    disable_irq(irq);
}
