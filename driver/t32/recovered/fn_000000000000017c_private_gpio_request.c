/* T32 OEM 0x17c: private_gpio_request; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_gpio_request(unsigned int gpio, const char *label);
int private_gpio_request(unsigned int gpio, const char *label)
{
    return gpio_request(gpio, label);
}
