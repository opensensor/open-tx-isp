/* T32 OEM 0x484: private_enable_irq; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_enable_irq(unsigned int irq);
void private_enable_irq(unsigned int irq)
{
    enable_irq(irq);
}
