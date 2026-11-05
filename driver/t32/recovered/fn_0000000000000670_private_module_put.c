/* T32 OEM 0x670: private_module_put; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_module_put(struct module *module);
void private_module_put(struct module *module)
{
    module_put(module);
}
