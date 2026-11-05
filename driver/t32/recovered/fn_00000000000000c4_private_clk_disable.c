/* T32 OEM 0xc4: private_clk_disable; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_clk_disable(struct clk *clk);
void private_clk_disable(struct clk *clk)
{
    clk_disable(clk);
}
