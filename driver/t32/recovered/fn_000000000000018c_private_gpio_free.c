/* T32 OEM 0x18c: private_gpio_free; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_gpio_free(unsigned int gpio);
void private_gpio_free(unsigned int gpio)
{
    gpio_free(gpio);
}
