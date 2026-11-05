/* T32 OEM 0x5d0: private_gpio_set_debounce; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_gpio_set_debounce(unsigned int gpio, unsigned int debounce);
int private_gpio_set_debounce(unsigned int gpio, unsigned int debounce)
{
    return gpio_set_debounce(gpio, debounce);
}
