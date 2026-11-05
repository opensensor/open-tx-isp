/* T32 OEM 0x4a4: private_free_irq; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_free_irq(unsigned int irq, void *dev_id);
void private_free_irq(unsigned int irq, void *dev_id)
{
    free_irq(irq, dev_id);
}
