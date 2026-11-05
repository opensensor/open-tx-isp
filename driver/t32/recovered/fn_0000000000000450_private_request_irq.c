/* C wrapper checked against the T32 OEM calling convention. */
#include "../compat.h"
int private_request_irq(unsigned int irq, irq_handler_t handler,
                        unsigned long flags, const char *name, void *dev)
{
    return request_threaded_irq(irq, handler, NULL, flags, name, dev);
}
