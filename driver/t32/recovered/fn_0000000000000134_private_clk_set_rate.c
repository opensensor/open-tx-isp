/* T32 OEM 0x134: private_clk_set_rate; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_clk_set_rate(struct clk *clk, unsigned long rate);
int private_clk_set_rate(struct clk *clk, unsigned long rate)
{
    return clk_set_rate(clk, rate);
}
