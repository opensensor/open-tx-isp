/* T32 OEM 0x104: private_clk_get_rate; recovery status: normalized_exact_match. */
#include "../compat.h"
unsigned long private_clk_get_rate(struct clk *clk);
unsigned long private_clk_get_rate(struct clk *clk)
{
    return clk_get_rate(clk);
}
