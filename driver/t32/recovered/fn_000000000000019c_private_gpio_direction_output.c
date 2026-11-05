/* T32 OEM 0x19c: private_gpio_direction_output; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_gpio_direction_output(unsigned int gpio, int value);
int private_gpio_direction_output(unsigned int gpio, int value)
{
    return gpio_direction_output(gpio, value);
}
