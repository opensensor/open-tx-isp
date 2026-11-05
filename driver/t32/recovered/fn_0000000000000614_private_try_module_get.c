/* T32 OEM 0x614: private_try_module_get; recovery status: normalized_exact_match. */
#include "../compat.h"
bool private_try_module_get(struct module *module);
bool private_try_module_get(struct module *module)
{
    return try_module_get(module);
}
