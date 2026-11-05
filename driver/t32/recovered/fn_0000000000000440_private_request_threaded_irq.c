/* T32 OEM 0x440: private_request_threaded_irq; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_request_threaded_irq(unsigned int irq, irq_handler_t handler, irq_handler_t thread_fn, unsigned long flags, const char *name, void *dev);
int private_request_threaded_irq(unsigned int irq, irq_handler_t handler, irq_handler_t thread_fn, unsigned long flags, const char *name, void *dev)
{
    return request_threaded_irq(irq, handler, thread_fn, flags, name, dev);
}
