/* T32 OEM 0x5a0: private_gpio_direction_input; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_gpio_direction_input(unsigned int gpio);
int private_gpio_direction_input(unsigned int gpio)
{
    return gpio_direction_input(gpio);
}
