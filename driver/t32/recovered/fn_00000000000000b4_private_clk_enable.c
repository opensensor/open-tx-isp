/* T32 OEM 0xb4: private_clk_enable; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_clk_enable(struct clk *clk);
int private_clk_enable(struct clk *clk)
{
    return clk_enable(clk);
}
