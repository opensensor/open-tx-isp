/* T32 OEM 0x1d0: private_jzgpio_set_func; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int jzgpio_set_func(int, int, unsigned long);
int private_jzgpio_set_func(int port, int func, unsigned long pins)
{
    return jzgpio_set_func(port, func, pins);
}
